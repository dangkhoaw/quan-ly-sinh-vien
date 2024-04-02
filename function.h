#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

#define USERNAME "admin"
#define PASSWORD "123456789"
#define MAX_LEN_USERNAME 20
#define MAX_LEN_PASSWORLD 20
#define MAX_SIZE 100
#define MAX_CLASS 6

int countClass = 0;
char facultyCode[10];
char academicYear[10];
char facultyName[50];

struct Student
{
    char ID[10];
    char fullName[35];
    char firstName[10]; // Tên
    char lastName[25];  // Họ
    char email[25];
    char birthDay[15];
    char sex[5];
    char address[30];
};
typedef struct Student *STUDENT;

struct StudentList
{
    int maxSize;
    int count;
    char className[10];
    char fileName[50];
    STUDENT *std;
};
typedef struct StudentList *STUDENTLIST;

STUDENTLIST createClass(int size)
{
    STUDENTLIST L = malloc(sizeof(struct StudentList));
    L->count = 0;
    L->maxSize = size;
    L->std = malloc(size * sizeof(struct Student));
    return L;
}

void removeEnter(char s[]) // Do hàm fgets lấy dấu enter nên phải xóa dấu enter ra
{
    size_t len = strlen(s);
    if (s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
    }
}

char *toLower(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
    return s;
}

char *toUpper(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
    return s;
}

char *lTrim(char s[]) // Cắt khoảng trống bên trái
{
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    if (i > 0)
    {
        strcpy(&s[0], &s[i]);
    }
    return s;
}

char *rTrim(char s[]) // Cắt khoảng trống bên phải
{
    int i = strlen(s) - 1;
    while (s[i] == ' ')
    {
        i--;
    }
    s[i + 1] = '\0';
    return s;
}

char *trim(char s[])
{
    rTrim(lTrim(s));
    char *ptr = strstr(s, "  ");
    while (ptr != NULL)
    {
        strcpy(ptr, ptr + 1); // Xóa 1 dấu cách
        ptr = strstr(s, "  ");
    }
    return s;
}

char *toName(char s[])
{
    trim(s);
    toLower(s);
    for (int i = 0; i < strlen(s); i++)
        if (i == 0 || (i > 0 && s[i - 1] == ' '))
            s[i] = s[i] - 32;
    return s;
}

bool checkFacultyCode()
{
    if (strcmp(facultyCode, "101") == 0 || strcmp(facultyCode, "102") == 0 || strcmp(facultyCode, "103") == 0 ||
        strcmp(facultyCode, "104") == 0 || strcmp(facultyCode, "105") == 0 || strcmp(facultyCode, "106") == 0 ||
        strcmp(facultyCode, "107") == 0 || strcmp(facultyCode, "109") == 0 || strcmp(facultyCode, "110") == 0 ||
        strcmp(facultyCode, "111") == 0 || strcmp(facultyCode, "117") == 0 || strcmp(facultyCode, "118") == 0 ||
        strcmp(facultyCode, "121") == 0 || strcmp(facultyCode, "123") == 0)
    {
        return true;
    }
    return false;
}

void generateFacultyName()
{
    if (strcmp(facultyCode, "101") == 0) // Khoa Cơ khí
        strcpy(facultyName, "Cơ khí");

    if (strcmp(facultyCode, "102") == 0) // Khoa Công nghệ Thông tin
        strcpy(facultyName, "Công nghệ thông tin");

    if (strcmp(facultyCode, "103") == 0) // Khoa Cơ khí Giao thông
        strcpy(facultyName, "Cơ khí giao thông");

    if (strcmp(facultyCode, "104") == 0) // Khoa CN Nhiệt-Điện lạnh
        strcpy(facultyName, "CN Nhiệt-Điện lạnh");

    if (strcmp(facultyCode, "105") == 0) // Khoa Điện
        strcpy(facultyName, "Điện");

    if (strcmp(facultyCode, "106") == 0) // Khoa Điện tử Viễn Thông
        strcpy(facultyName, "Điện tử Viễn thông");

    if (strcmp(facultyCode, "107") == 0) // Khoa Hóa
        strcpy(facultyName, "Hóa");

    if (strcmp(facultyCode, "109") == 0) // Khoa Xây dựng Cầu-Đường
        strcpy(facultyName, "XD Cầu-Đường");

    if (strcmp(facultyCode, "110") == 0) // Khoa Xây dựng Dân dụng - Công nghiệp
        strcpy(facultyName, "XD Dân dụng - Công nghiệp");

    if (strcmp(facultyCode, "111") == 0) // Khoa Xây dựng công trình thủy
        strcpy(facultyName, "XD Công trình thủy");

    if (strcmp(facultyCode, "117") == 0) // Khoa Môi trường
        strcpy(facultyName, "Môi trường");

    if (strcmp(facultyCode, "118") == 0) // Khoa Quản lí dự án
        strcpy(facultyName, "Quản lí dự án");

    if (strcmp(facultyCode, "121") == 0) // Khoa Kiến trúc
        strcpy(facultyName, "Kiến trúc");

    if (strcmp(facultyCode, "123") == 0) // Khoa Khoa học CNghe tiên tiến
        strcpy(facultyName, "KH Công nghệ tiên tiến");
}

void enterCode()
{
    do
    {
        printf("\n➡️  Mời bạn nhập vào mã khoa: ");
        scanf("%s", facultyCode);
        if (checkFacultyCode() == 0)
            printf("\n⚠️ Sai mã khoa, mời nhập lại\n");
    } while (checkFacultyCode() == 0);

    generateFacultyName();

    printf("\n➡️  Mời bạn nhập vào mã khóa: ");
    scanf("%s", academicYear);
}

bool checkClassName(char className[])
{
    if (strcmp(facultyCode, "101") == 0) // Khoa Cơ khí
    {
        if (strstr(className, "C1") || strstr(className, "CDT") || strstr(className, "CKHK"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "102") == 0) // Khoa Công nghệ Thông tin
    {
        if (strstr(className, "T_DT") || strstr(className, "T_KHDL") || strstr(className, "T_Nhat"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "103") == 0) // Khoa Cơ khí Giao thông
    {
        if (strstr(className, "C4") || strstr(className, "HTCN") || strstr(className, "KTOTO") || strstr(className, "KTTT"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "104") == 0) // Khoa CN Nhiệt-Điện lạnh
    {
        if (strstr(className, "N"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "105") == 0) // Khoa Điện
    {
        if (strstr(className, "D") || strstr(className, "TDH"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "106") == 0) // Khoa Điện tử Viễn Thông
    {
        if (strstr(className, "DT") || strstr(className, "KTMT"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "107") == 0) // Khoa Hóa
    {
        if (strstr(className, "H2") || strstr(className, "H5") || strstr(className, "KTHH") || strstr(className, "SH") || strstr(className, "SHYD"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "109") == 0) // Khoa Xây dựng Cầu-Đường
    {
        if (strstr(className, "BIM_AI") || strstr(className, "CSHT") || strstr(className, "VLXD") || strstr(className, "X3"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "110") == 0) // Khoa Xây dựng Dân dụng - Công nghiệp
    {
        if (strstr(className, "X1"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "111") == 0) // Khoa Xây dựng công trình thủy
    {
        if (strstr(className, "DTTM") || strstr(className, "THXD") || strstr(className, "X2"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "117") == 0) // Khoa Môi trường
    {
        if (strstr(className, "MT") || strstr(className, "QLMT"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "118") == 0) // Khoa Quản lí dự án
    {
        if (strstr(className, "KX") || strstr(className, "QLCN"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "121") == 0) // Khoa Kiến trúc
    {
        if (strstr(className, "KT"))
        {
            return true;
        }
    }

    if (strcmp(facultyCode, "123") == 0) // Khoa Khoa học CNghe tiên tiến
    {
        if (strstr(className, "PFIEV") || strstr(className, "ES") || strstr(className, "ECE"))
        {
            return true;
        }
    }
    return false;
}

void insertStudent(STUDENTLIST *classList, STUDENTLIST Class, STUDENT std)
{
    if (Class->count >= Class->maxSize)
        exit(1);
    Class->std[Class->count] = std;
    Class->count++;
    classList[countClass] = Class;
}

void addStudent(STUDENTLIST *classList)
{
    if (countClass == MAX_CLASS)
    {
        printf("Vượt quá giới hạn lớp học\n");
        return;
    }

    STUDENTLIST class = createClass(MAX_SIZE);
    if (class == NULL)
    {
        printf("\nKhông đủ bộ nhớ để tạo lớp mới.\n");
        return;
    }

    char className[15];
    do
    {
        printf("\n➡️  Mời bạn nhập vào tên lớp: ");
        fgets(className, sizeof(className), stdin);
        removeEnter(className);
        toUpper(className);
        if (checkClassName(className) == 0)
        {
            printf("\n⚠️  Tên lớp không hợp lệ, cần nhập lại\n");
        }
    } while (checkClassName(className) == 0);

    for (int i = 0; i < countClass; i++)
    {
        if (strcmp(classList[i]->className, className) == 0)
        {
            printf("\n⚠️  Danh sách lớp %s đã có sinh viên.\n", className);
            return;
        }
    }

    strcpy(class->className, className);
    strcpy(class->fileName, "");

    int numStd;
    printf("\n➡️  Mời bạn nhập vào số sinh viên của lớp %s: ", className);
    scanf("%d", &numStd);
    fflush(stdin);

    if (numStd <= 0 || numStd > MAX_SIZE)
    {
        printf("\n⚠️ Số lượng học sinh không hợp lệ ⚠️\n");
        return;
    }

    for (int i = 0; i < numStd; i++)
    {
        STUDENT newStudent = malloc(sizeof(struct Student));
        if (newStudent == NULL)
        {
            printf("\nKhông đủ bộ nhớ để tạo sinh viên mới.\n");
            return;
        }

        printf("\n➡️  Nhập họ và tên lót sinh viên thứ %d: ", i + 1);
        fgets(newStudent->lastName, sizeof(newStudent->lastName), stdin);
        removeEnter(newStudent->lastName);
        toName(newStudent->lastName);

        printf("\n➡️  Nhập tên sinh viên thứ %d: ", i + 1);
        fgets(newStudent->firstName, sizeof(newStudent->firstName), stdin);
        removeEnter(newStudent->firstName);
        toName(newStudent->firstName);

        printf("\n➡️  Nhập vào ngày sinh: ");
        fgets(newStudent->birthDay, sizeof(newStudent->birthDay), stdin);
        removeEnter(newStudent->birthDay);

        printf("\n➡️  Nhập vào giới tính: ");
        fgets(newStudent->sex, sizeof(newStudent->sex), stdin);
        removeEnter(newStudent->sex);
        toName(newStudent->sex);

        printf("\n➡️  Nhập vào địa chỉ: ");
        fgets(newStudent->address, sizeof(newStudent->address), stdin);
        removeEnter(newStudent->address);

        strcpy(newStudent->ID, "");

        strcpy(newStudent->email, "");

        strcpy(newStudent->fullName, newStudent->lastName);
        strcat(newStudent->fullName, " ");
        strcat(newStudent->fullName, newStudent->firstName);

        insertStudent(classList, class, newStudent);
        printf("\n👏 Đã thêm sinh viên thành công\n");
    }
    countClass++;
}

bool isSorted(STUDENTLIST class)
{
    for (int i = 1; i < class->count; i++)
    {
        if (strcmp(class->std[i]->firstName, class->std[i - 1]->firstName) < 0)
        {
            return false;
        }
        if (strcmp(class->std[i]->firstName, class->std[i - 1]->firstName) == 0 && strcmp(class->std[i]->lastName, class->std[i - 1]->lastName) < 0)
        {
            return false;
        }
    }
    return true;
}

void printToFile(STUDENTLIST *classList, FILE *f, int position)
{
    fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", classList[position]->className);
    if (strcmp(classList[position]->std[0]->ID, "") == 0)
    {
        fprintf(f, "%-11s %-21s %-17s %-16s %s\n", "STT", "Họ và tên", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < classList[position]->count; i++)
        {
            fprintf(f, " %-5d %-25s %-11s %-15s %s\n", i + 1, classList[position]->std[i]->fullName, classList[position]->std[i]->sex, classList[position]->std[i]->birthDay, classList[position]->std[i]->address);
        }
    }
    else if (strcmp(classList[position]->std[0]->email, "") == 0)
    {
        fprintf(f, "%-5s %-23s %-21s %-17s %-16s %s\n", "STT", "Mã sinh viên", "Họ và tên", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < classList[position]->count; i++)
        {
            fprintf(f, " %-5d %-15s %-25s %-11s %-15s %s\n", i + 1, classList[position]->std[i]->ID, classList[position]->std[i]->fullName, classList[position]->std[i]->sex, classList[position]->std[i]->birthDay, classList[position]->std[i]->address);
        }
    }
    else
    {
        fprintf(f, "%-5s %-23s %-29s %-21s %-17s %-16s %s\n", "STT", "Mã sinh viên", "Họ và tên", "Email", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < classList[position]->count; i++)
        {
            fprintf(f, " %-5d %-15s %-23s %-31s %-11s %-15s %s\n", i + 1, classList[position]->std[i]->ID, classList[position]->std[i]->fullName, classList[position]->std[i]->email, classList[position]->std[i]->sex, classList[position]->std[i]->birthDay, classList[position]->std[i]->address);
        }
    }
}

void swapStudent(STUDENT *std1, STUDENT *std2)
{
    STUDENT tmp = *std1;
    *std1 = *std2;
    *std2 = tmp;
}

void sortStudent(STUDENTLIST *classList)
{
    if (countClass == 0)
    {
        printf("\n🔔 Chưa có danh sách sinh viên nào\n");
        return;
    }

    printf("\n➡️  Mời bạn nhập tên lớp cần sắp xếp: ");
    char className[15];
    int sorted = 0;
    int found = 0;
    fgets(className, sizeof(className), stdin);
    removeEnter(className);
    toUpper(className);

    for (int i = 0; i < countClass; i++)
    {
        if (strcmp(className, classList[i]->className) == 0)
        {
            found = 1;
            if (isSorted(classList[i]))
            {
                char fileName[15];
                printf("\n👏 Sắp xếp thành công\n");
                sprintf(fileName, "input_%s.txt", classList[i]->className);
                FILE *f = fopen(fileName, "w");
                printToFile(classList, f, i);
                fclose(f);
                return;
            }

            for (int j = 0; j < classList[i]->count - 1; j++)
            {
                for (int k = j + 1; k < classList[i]->count; k++)
                {
                    sorted = 1;
                    if (strcmp(classList[i]->std[j]->firstName, classList[i]->std[k]->firstName) > 0 ||
                        (strcmp(classList[i]->std[j]->firstName, classList[i]->std[k]->firstName) == 0 &&
                         strcmp(classList[i]->std[j]->lastName, classList[i]->std[k]->lastName) > 0))
                    {
                        swapStudent(&classList[i]->std[k], &classList[i]->std[j]);
                    }
                }
            }
            char fileName[15];
            sprintf(fileName, "input_%s.txt", classList[i]->className);
            FILE *f = fopen(fileName, "w");
            printToFile(classList, f, i);
            fclose(f);
            break;
        }
    }
    if (!found)
    {
        printf("\n🔔 Không tìm thấy lớp %s \n", className);
        return;
    }

    if (sorted == 1)
        printf("\n👏 Sắp xếp thành công\n");
}

void printListStudent(STUDENTLIST *classList)
{
    if (countClass == 0)
    {
        printf("\n🔔 Chưa có danh sách sinh viên nào\n");
        return;
    }

    printf("\n➡️  Mời bạn nhập vào tên lớp cần in danh sách: ");
    char className[15];
    fgets(className, sizeof(className), stdin);
    removeEnter(className);
    toUpper(className);

    int found = 0;
    for (int i = 0; i < countClass; i++)
    {
        if (strcmp(classList[i]->className, className) == 0)
        {
            if (isSorted(classList[i]) == 0)
            {
                printf("\n🔔 Bạn cần sắp xếp lớp %s để in danh sách\n", className);
                return;
            }

            found = 1;
            if (classList[i]->count == 0)
            {
                printf("\n🔔 Danh sách không có sinh viên\n");
                return;
            }

            // Tạo tên file
            FILE *f;
            char fileName[40] = "K";
            strcat(fileName, academicYear);
            strcat(fileName, "-");
            strcat(fileName, className);
            strcat(fileName, "-");
            strcat(fileName, facultyName);
            strcat(fileName, ".txt");
            strcpy(classList[i]->fileName, fileName);

            f = fopen(fileName, "w");
            if (f == NULL)
            {
                printf("🔔 Không thể tạo file\n");
                return;
            }

            printToFile(classList, f, i);
            printf("\n👏 Đã in danh sách sinh viên\n");
            printf("\n📝 Bạn mở file %s để xem danh sách sinh viên của lớp %s\n", fileName, className);
            fclose(f);
            break;
        }
    }
    if (!found)
    {
        printf("\n🔔 Không tìm thấy lớp %s\n", className);
    }
}

void generateID(STUDENTLIST *classList)
{
    if (countClass == 0)
    {
        printf("\nChưa có danh sách sinh viên nào\n");
        return;
    }

    printf("\n➡️  Mời bạn nhập vào tên lớp cần cấp ID: ");
    char className[15];
    int success = 0, found = 0;
    fgets(className, sizeof(className), stdin);
    removeEnter(className);
    toUpper(className);

    for (int i = 0; i < countClass; i++)
    {
        if (strcmp(className, classList[i]->className) == 0)
        {
            found = 1;
            if (isSorted(classList[i]))
            {
                for (int j = 0; j < classList[i]->count; j++)
                {
                    success = 1;
                    if (strcmp(classList[i]->std[j]->ID, "") == 0)
                    {
                        char ordinal[5], studentCode[10], temp[10];
                        strcpy(temp, academicYear);
                        static int number = 0;
                        number++;
                        strcpy(studentCode, facultyCode);
                        sprintf(ordinal, "%04d", number);
                        strcat(temp, ordinal);
                        strcat(studentCode, temp);
                        strcat(classList[i]->std[j]->ID, studentCode);
                    }
                }
                if (strcmp(classList[i]->fileName, "") != 0)
                {
                    FILE *f = fopen(classList[i]->fileName, "w");
                    printToFile(classList, f, i);
                    fclose(f);
                }
                break;
            }
            else
            {
                printf("\n⚠️ Lớp chưa được sắp xếp, mời bạn sắp xếp lớp trước ⚠️\n");
                return;
            }
        }
    }
    if (!found)
        printf("\n🔔 Không tìm thấy lớp %s\n", className);
    if (success == 1)
        printf("\n👏 Cấp ID thành công\n");
}

void generateEmail(STUDENTLIST *classList)
{
    if (countClass == 0)
    {
        printf("\nChưa có danh sách sinh viên nào\n");
        return;
    }

    printf("\n➡️  Mời bạn nhập vào tên lớp cần cấp email: ");
    char className[15];
    fgets(className, sizeof(className), stdin);
    removeEnter(className);
    toUpper(className);

    int success = 0, found = 0;
    for (int i = 0; i < countClass; i++)
    {
        if (strcmp(className, classList[i]->className) == 0)
        {
            found = 1;
            for (int j = 0; j < classList[i]->count; j++)
            {
                if (strcmp(classList[i]->std[j]->ID, "") == 0)
                {
                    printf("\n⚠️ Lớp chưa được cấp mã sinh viên, mời bạn cấp mã sinh viên trước ⚠️\n");
                    return;
                }
                success = 1;
                char email[25];
                strcpy(email, classList[i]->std[j]->ID);
                strcat(email, "@sv.dut.udn.vn");
                strcpy(classList[i]->std[j]->email, email);
            }
            if (strcmp(classList[i]->fileName, "") != 0)
            {
                FILE *f = fopen(classList[i]->fileName, "w");
                printToFile(classList, f, i);
                fclose(f);
            }
            break;
        }
    }
    if (!found)
        printf("\n🔔 Không tìm thấy lớp %s\n", className);
    if (success == 1)
        printf("\n👏 Cấp email thành công\n");
}

void removeStudent(STUDENTLIST *classList)
{
    if (countClass == 0)
    {
        printf("\n🔔 Chưa có danh sách sinh viên nào\n");
        return;
    }

    int success = 0, found = 0;
    char ID[10], choice;
    fflush(stdin);
    printf("\n➡️  Mời nhập ID bạn muốn xóa: ");
    fgets(ID, sizeof(ID), stdin);
    removeEnter(ID);

    for (int i = 0; i < countClass; i++)
    {
        for (int j = 0; j < classList[i]->count; j++)
        {
            if (strcmp(classList[i]->std[j]->ID, "") == 0)
            {
                break;
            }
            if (strcmp(classList[i]->std[j]->ID, ID) == 0)
            {
                found = 1;
                printf("\n❓ Bạn có chắc chắn xóa sinh viên %s %s ra khỏi danh sách không? (Y/N) ", classList[i]->std[j]->ID, classList[i]->std[j]->fullName);
                fflush(stdin);
                scanf("%c", &choice);
                if (choice == 'Y' || choice == 'y')
                {
                    success = 1;
                    for (int k = j; k < classList[i]->count - 1; k++)
                    {
                        classList[i]->std[k] = classList[i]->std[k + 1];
                    }
                    classList[i]->count--;
                    if (strcmp(classList[i]->fileName, "") != 0)
                    {
                        FILE *f = fopen(classList[i]->fileName, "w");
                        printToFile(classList, f, i);
                        fclose(f);
                    }
                    break;
                }
                else
                    return;
            }
        }
    }
    if (!found)
    {
        printf("\n🔔 Không tìm thấy ID\n");
    }
    if (success == 1)
        printf("\n👏 Đã xóa thành công sinh viên\n");
}

void menuSearch()
{
    printf("\n================================");
    printf("\n1. Tìm kiếm theo tên\n");
    printf("2. Tìm kiếm theo ID\n");
    printf("\nMời bạn chọn: ");
}

void searchStudentByName(STUDENTLIST *classList)
{
    char name[35], tempName[35];
    printf("\n➡️  Mời bạn nhập tên sinh viên bạn muốn tìm: ");
    fflush(stdin);
    fgets(name, sizeof(name), stdin);
    removeEnter(name);
    strcpy(tempName, name);
    toName(tempName);

    int found = 0;
    for (int i = 0; i < countClass; i++)
    {
        for (int j = 0; j < classList[i]->count; j++)
        {
            if (strstr(classList[i]->std[j]->fullName, tempName))
            {
                found = 1;
                printf("\n🔔 Tìm thấy: %s  %s\n", classList[i]->std[j]->ID, classList[i]->std[j]->fullName);
            }
        }
    }
    if (!found)
        printf("\n🔔 Không tìm thấy sinh viên tên %s\n", name);
}

void searchStudentByID(STUDENTLIST *classList)
{
    char ID[10];
    printf("\n➡️  Mời bạn nhập ID bạn muốn tìm: ");
    fflush(stdin);
    fgets(ID, sizeof(ID), stdin);
    removeEnter(ID);

    int found = 0;
    for (int i = 0; i < countClass; i++)
    {
        for (int j = 0; j < classList[i]->count; j++)
        {
            if (strcmp(classList[i]->std[j]->ID, ID) == 0)
            {
                found = 1;
                printf("\n🔔 Tìm thấy: %s  %s\n", classList[i]->std[j]->ID, classList[i]->std[j]->fullName);
                return;
            }
        }
    }
    if (!found)
        printf("\n🔔 Không tìm thấy sinh viên có ID %s\n", ID);
}

void searchStudent(STUDENTLIST *classList)
{
    if (countClass == 0)
    {
        printf("\n🔔 Chưa có danh sách sinh viên nào\n");
        return;
    }
    menuSearch();
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        searchStudentByName(classList);
        break;
    case 2:
        searchStudentByID(classList);
        break;
    default:
        printf("\nChọn 1 hoặc 2\n");
        searchStudent(classList);
        break;
    }
}

void menu()
{
    printf("\n* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*   1.  Thêm sinh viên                      *\n");
    printf("*   2.  Sắp xếp sinh viên                   *\n");
    printf("*   3.  Xóa sinh viên                       *\n");
    printf("*   4.  Tìm sinh viên                       *\n");
    printf("*   5.  Cấp mã sinh viên                    *\n");
    printf("*   6.  Cấp email                           *\n");
    printf("*   7.  In danh sách sinh viên              *\n");
    printf("*   8.  Thoát                               *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\nMời bạn chọn: ");
}

bool login()
{
    char username[MAX_LEN_USERNAME];
    char password[MAX_LEN_PASSWORLD];
    int checkLogin = 0;
    printf("\n\t===============Login Page===============\n\n");
    while (checkLogin < 3)
    {
        printf("Username : ");
        fgets(username, MAX_LEN_USERNAME, stdin);
        removeEnter(username);
        printf("Password : ");
        int i = 0;
        char get;
        while (i < MAX_LEN_PASSWORLD)
        {
            get = getch(); // Lấy ký tự từ terminal mà không hiển thị lên màn hình
            if (get == '\r' || get == '\n')
            {
                break;
            }
            else if (get == '\b' && i > 0)
            {
                printf("\b \b");
                i--;
            }
            else
            {
                password[i++] = get;
                printf("*");
            }
        }
        password[i] = '\0';

        if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0)
        {
            printf("\n\nĐăng nhập thành công!");
            Sleep(500);
            printf("\n\nLoading");
            for (int i = 0; i < 4; i++)
            {
                for (int k = 0; k < 3; k++)
                {
                    printf(".");
                    Sleep(150);
                }
                printf("\b \b\b \b\b \b");
            }
            system("cls");
            return true;
        }
        else
        {
            checkLogin++;
            if (checkLogin < 3)
                printf("\n\n⚠️  Sai Username hoặc Password. Hãy thử lại!\n\n");
        }
        if (checkLogin == 3)
        {
            break;
        }
    }
    printf("\n\n🚫 Sai quá nhiều lần. Thoát chương trình\n");
    return false;
}

void runProgram()
{
    enterCode();
    STUDENTLIST *classList = malloc(MAX_CLASS * sizeof(struct StudentList));
    int choice;
    printf("\n------------CHƯƠNG TRÌNH QUẢN LÍ SINH VIÊN------------\n\n");
    do
    {
        menu();
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            addStudent(classList);
            break;
        case 2:
            sortStudent(classList);
            break;
        case 3:
            removeStudent(classList);
            break;
        case 4:
            searchStudent(classList);
            break;
        case 5:
            generateID(classList);
            break;
        case 6:
            generateEmail(classList);
            break;
        case 7:
            printListStudent(classList);
            break;
        }
    } while (choice != 8);
    free(classList);
}

#endif
#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 20
#define MIN_USERNAME_LENGTH 5
#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8
#define MAX_SIZE 100
#define MAX_CLASS 6
#define KEY 15

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

STUDENTLIST createClass(int maxSize)
{
    STUDENTLIST Class = malloc(sizeof(struct StudentList));
    Class->count = 0;
    Class->maxSize = maxSize;
    Class->std = malloc(maxSize * sizeof(struct Student));
    return Class;
}

void removeEnter(char s[]) // Do hàm fgets lấy dấu enter nên phải xóa dấu enter ra
{
    size_t len = strlen(s);
    if (s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
    }
}

bool isNumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool isLower(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

bool isUpper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
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
    else if (strcmp(facultyCode, "102") == 0) // Khoa Công nghệ Thông tin
        strcpy(facultyName, "Công nghệ thông tin");
    else if (strcmp(facultyCode, "103") == 0) // Khoa Cơ khí Giao thông
        strcpy(facultyName, "Cơ khí giao thông");
    else if (strcmp(facultyCode, "104") == 0) // Khoa CN Nhiệt-Điện lạnh
        strcpy(facultyName, "CN Nhiệt-Điện lạnh");
    else if (strcmp(facultyCode, "105") == 0) // Khoa Điện
        strcpy(facultyName, "Điện");
    else if (strcmp(facultyCode, "106") == 0) // Khoa Điện tử Viễn Thông
        strcpy(facultyName, "Điện tử Viễn thông");
    else if (strcmp(facultyCode, "107") == 0) // Khoa Hóa
        strcpy(facultyName, "Hóa");
    else if (strcmp(facultyCode, "109") == 0) // Khoa Xây dựng Cầu-Đường
        strcpy(facultyName, "XD Cầu-Đường");
    else if (strcmp(facultyCode, "110") == 0) // Khoa Xây dựng Dân dụng - Công nghiệp
        strcpy(facultyName, "XD Dân dụng - Công nghiệp");
    else if (strcmp(facultyCode, "111") == 0) // Khoa Xây dựng công trình thủy
        strcpy(facultyName, "XD Công trình thủy");
    else if (strcmp(facultyCode, "117") == 0) // Khoa Môi trường
        strcpy(facultyName, "Môi trường");
    else if (strcmp(facultyCode, "118") == 0) // Khoa Quản lí dự án
        strcpy(facultyName, "Quản lí dự án");
    else if (strcmp(facultyCode, "121") == 0) // Khoa Kiến trúc
        strcpy(facultyName, "Kiến trúc");
    else if (strcmp(facultyCode, "123") == 0) // Khoa Khoa học CNghe tiên tiến
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
    else if (strcmp(facultyCode, "102") == 0) // Khoa Công nghệ Thông tin
    {
        if (strstr(className, "T_DT") || strstr(className, "T_KHDL") || strstr(className, "T_Nhat"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "103") == 0) // Khoa Cơ khí Giao thông
    {
        if (strstr(className, "C4") || strstr(className, "HTCN") || strstr(className, "KTOTO") || strstr(className, "KTTT"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "104") == 0) // Khoa CN Nhiệt-Điện lạnh
    {
        if (strstr(className, "N"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "105") == 0) // Khoa Điện
    {
        if (strstr(className, "D") || strstr(className, "TDH"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "106") == 0) // Khoa Điện tử Viễn Thông
    {
        if (strstr(className, "DT") || strstr(className, "KTMT"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "107") == 0) // Khoa Hóa
    {
        if (strstr(className, "H2") || strstr(className, "H5") || strstr(className, "KTHH") || strstr(className, "SH") || strstr(className, "SHYD"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "109") == 0) // Khoa Xây dựng Cầu-Đường
    {
        if (strstr(className, "BIM_AI") || strstr(className, "CSHT") || strstr(className, "VLXD") || strstr(className, "X3"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "110") == 0) // Khoa Xây dựng Dân dụng - Công nghiệp
    {
        if (strstr(className, "X1"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "111") == 0) // Khoa Xây dựng công trình thủy
    {
        if (strstr(className, "DTTM") || strstr(className, "THXD") || strstr(className, "X2"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "117") == 0) // Khoa Môi trường
    {
        if (strstr(className, "MT") || strstr(className, "QLMT"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "118") == 0) // Khoa Quản lí dự án
    {
        if (strstr(className, "KX") || strstr(className, "QLCN"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "121") == 0) // Khoa Kiến trúc
    {
        if (strstr(className, "KT"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "123") == 0) // Khoa Khoa học CNghe tiên tiến
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

void inputStudentInfo(STUDENT student)
{
    printf("\n➡️  Nhập họ và tên lót sinh viên: ");
    fgets(student->lastName, sizeof(student->lastName), stdin);
    removeEnter(student->lastName);
    toName(student->lastName);

    printf("\n➡️  Nhập tên sinh viên: ");
    fgets(student->firstName, sizeof(student->firstName), stdin);
    removeEnter(student->firstName);
    toName(student->firstName);

    printf("\n➡️  Nhập vào ngày sinh: ");
    fgets(student->birthDay, sizeof(student->birthDay), stdin);
    removeEnter(student->birthDay);

    printf("\n➡️  Nhập vào giới tính: ");
    fgets(student->sex, sizeof(student->sex), stdin);
    removeEnter(student->sex);
    toName(student->sex);

    printf("\n➡️  Nhập vào địa chỉ: ");
    fgets(student->address, sizeof(student->address), stdin);
    removeEnter(student->address);

    strcpy(student->ID, "");

    strcpy(student->email, "");

    sprintf(student->fullName, "%s %s", student->lastName, student->firstName);
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
        if (!checkClassName(className))
        {
            printf("\n⚠️  Tên lớp không hợp lệ, cần nhập lại\n");
        }
    } while (!checkClassName(className));

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

        inputStudentInfo(newStudent);

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
        fprintf(f, "%-11s %-25s %-17s %-16s %s\n", "STT", "Họ và tên", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < classList[position]->count; i++)
        {
            fprintf(f, " %-5d %-29s %-11s %-15s %s\n", i + 1, classList[position]->std[i]->fullName, classList[position]->std[i]->sex, classList[position]->std[i]->birthDay, classList[position]->std[i]->address);
        }
    }
    else if (strcmp(classList[position]->std[0]->email, "") == 0)
    {
        fprintf(f, "%-5s %-23s %-24s %-17s %-16s %s\n", "STT", "Mã sinh viên", "Họ và tên", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < classList[position]->count; i++)
        {
            fprintf(f, " %-5d %-15s %-28s %-11s %-15s %s\n", i + 1, classList[position]->std[i]->ID, classList[position]->std[i]->fullName, classList[position]->std[i]->sex, classList[position]->std[i]->birthDay, classList[position]->std[i]->address);
        }
    }
    else
    {
        fprintf(f, "%-5s %-23s %-33s %-21s %-17s %-16s %s\n", "STT", "Mã sinh viên", "Họ và tên", "Email", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < classList[position]->count; i++)
        {
            fprintf(f, " %-5d %-15s %-26s %-31s %-12s %-15s %s\n", i + 1, classList[position]->std[i]->ID, classList[position]->std[i]->fullName, classList[position]->std[i]->email, classList[position]->std[i]->sex, classList[position]->std[i]->birthDay, classList[position]->std[i]->address);
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
    fgets(className, sizeof(className), stdin);
    removeEnter(className);
    toUpper(className);

    int found = 0;
    int sorted = 0;

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

    if (sorted)
    {
        printf("\n👏 Sắp xếp thành công\n");
    }
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
                printf("\n🔔 Bạn cần sắp xếp lớp %s để in danh sách\n", classList[i]->className);
                return;
            }

            found = 1;
            if (classList[i]->count == 0)
            {
                printf("\n🔔 Danh sách không có sinh viên\n");
                return;
            }

            // Tạo tên file
            sprintf(classList[i]->fileName, "K%s-%s-%s", academicYear, classList[i]->className, facultyName);

            FILE *f = fopen(classList[i]->fileName, "w");
            if (f == NULL)
            {
                printf("🔔 Không thể tạo file\n");
                return;
            }

            printToFile(classList, f, i);
            printf("\n👏 Đã in danh sách sinh viên\n");
            printf("\n📝 Bạn mở file %s để xem danh sách sinh viên của lớp %s\n", classList[i]->fileName, className);
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
    fgets(className, sizeof(className), stdin);
    removeEnter(className);
    toUpper(className);

    int success = 0, found = 0;
    for (int i = 0; i < countClass; i++)
    {
        if (strcmp(className, classList[i]->className) == 0)
        {
            found = 1;
            if (isSorted(classList[i]))
            {
                for (int j = 0; j < classList[i]->count; j++)
                {
                    if (strcmp(classList[i]->std[j]->ID, "") == 0)
                    {
                        static int ordinal = 0;
                        ordinal++;
                        sprintf(classList[i]->std[j]->ID, "%s%s%04d", facultyCode, academicYear, ordinal);
                        success = 1;
                    }
                }
                if (strcmp(classList[i]->fileName, "") != 0)
                {
                    FILE *f = fopen(classList[i]->fileName, "w");
                    if (f == NULL)
                    {
                        printf("🔔 Không thể tạo file\n");
                        return;
                    }
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
    {
        printf("\n🔔 Không tìm thấy lớp %s\n", className);
    }
    if (success)
    {
        printf("\n👏 Cấp ID thành công\n");
    }
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
            if (strcmp(classList[i]->std[0]->ID, "") == 0)
            {
                printf("\n⚠️ Lớp chưa được cấp mã sinh viên, mời bạn cấp mã sinh viên trước ⚠️\n");
                return;
            }

            for (int j = 0; j < classList[i]->count; j++)
            {
                if (strcmp(classList[i]->std[j]->email, "") == 0)
                {
                    success = 1;
                    sprintf(classList[i]->std[j]->email, "%s@sv.dut.udn.vn", classList[i]->std[j]->ID);
                }
            }
            if (strcmp(classList[i]->fileName, "") != 0)
            {
                FILE *f = fopen(classList[i]->fileName, "w");
                if (f == NULL)
                {
                    printf("🔔 Không thể tạo file\n");
                    return;
                }
                printToFile(classList, f, i);
                fclose(f);
            }
            break;
        }
    }
    if (!found)
    {
        printf("\n🔔 Không tìm thấy lớp %s\n", className);
    }
    if (success)
    {
        printf("\n👏 Cấp email thành công\n");
    }
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
                printf("\n❓ Bạn có chắc chắn xóa sinh viên %s %s ra khỏi danh sách không? (Y/N): ", classList[i]->std[j]->ID, classList[i]->std[j]->fullName);
                fflush(stdin);
                scanf("%c", &choice);
                if (choice == 'Y' || choice == 'y')
                {
                    for (int k = j; k < classList[i]->count - 1; k++)
                    {
                        classList[i]->std[k] = classList[i]->std[k + 1];
                    }
                    classList[i]->count--;
                    success = 1;
                    if (strcmp(classList[i]->fileName, "") != 0)
                    {
                        FILE *f = fopen(classList[i]->fileName, "w");
                        if (f == NULL)
                        {
                            printf("🔔 Không thể tạo file\n");
                            return;
                        }
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
    if (success)
        printf("\n👏 Đã xóa thành công sinh viên\n");
}

void menuSearch()
{
    printf("\n================================");
    printf("\n1. Tìm kiếm theo tên");
    printf("\n2. Tìm kiếm theo ID");
    printf("\n\nMời bạn chọn: ");
}

void searchStudentByName(STUDENTLIST *classList)
{
    char searchName[35], formatName[35];
    printf("\n➡️  Mời bạn nhập tên sinh viên bạn muốn tìm: ");
    fflush(stdin);
    fgets(searchName, sizeof(searchName), stdin);
    removeEnter(searchName);
    strcpy(formatName, searchName);
    toName(formatName);

    int found = 0;
    for (int i = 0; i < countClass; i++)
    {
        for (int j = 0; j < classList[i]->count; j++)
        {
            if (strstr(classList[i]->std[j]->fullName, formatName))
            {
                found = 1;
                printf("\n🔔 Tìm thấy: %s  %s\n", classList[i]->std[j]->ID, classList[i]->std[j]->fullName);
            }
        }
    }
    if (!found)
        printf("\n🔔 Không tìm thấy sinh viên tên %s\n", searchName);
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
    printf("*   \033[1;34m1.  Thêm sinh viên\033[0m                      *\n");
    printf("*   \033[1;35m2.  Sắp xếp sinh viên\033[0m                   *\n");
    printf("*   \033[1;36m3.  Xóa sinh viên\033[0m                       *\n");
    printf("*   \033[1;33m4.  Tìm sinh viên\033[0m                       *\n");
    printf("*   \033[1;32m5.  Cấp mã sinh viên\033[0m                    *\n");
    printf("*   \033[1;31m6.  Cấp email\033[0m                           *\n");
    printf("*   \033[1;37m7.  In danh sách sinh viên\033[0m              *\n");
    printf("*   \033[1;30m8.  Thoát\033[0m                               *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\nMời bạn chọn: ");
}

void loading()
{
    printf("\n\nLoading");
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            printf(".");
            Sleep(150);
        }
        printf("\b \b\b \b\b \b");
    }
}

char encodeNumber(char c)
{
    char encryptedNumber[] = {'5', '2', '3', '6', '9', '8', '7', '4', '1', '0'};
    return encryptedNumber[c - '0'];
}

char decodeNumber(char c)
{
    char encryptedNumber[] = {'5', '2', '3', '6', '9', '8', '7', '4', '1', '0'};
    for (int i = 0; i < 10; i++)
    {
        if (c == encryptedNumber[i])
        {
            return i + '0';
        }
    }
}

void encryptPassword(char password[])
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            password[i] = (password[i] - 'a' + KEY) % 26 + 'a';
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            password[i] = (password[i] - 'A' + KEY) % 26 + 'A';
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            password[i] = encodeNumber(password[i]);
        }
    }
}

void decryptPassword(char password[])
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            password[i] = (password[i] - 'a' - KEY + 26) % 26 + 'a';
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            password[i] = (password[i] - 'A' - KEY + 26) % 26 + 'A';
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            password[i] = decodeNumber(password[i]);
        }
    }
}

void enterPassword(char password[])
{
    int i = 0;
    char get;
    while (i < MAX_PASSWORD_LENGTH)
    {
        get = getch();
        if (get == '\r' || get == '\n')
        {
            break;
        }
        else if (get == '\b')
        {
            if (i > 0)
            {
                printf("\b \b");
                i--;
            }
            else
            {
                printf(" \b");
            }
        }
        else
        {
            password[i++] = get;
            printf("•");
        }
    }
    password[i] = '\0';
}

bool isValidUsername(char username[])
{
    if (strlen(username) < MIN_USERNAME_LENGTH || strlen(username) > MAX_USERNAME_LENGTH)
    {
        return false;
    }
    for (int i = 0; i < strlen(username); i++)
    {
        if (username[i] == ' ')
        {
            return false;
        }
    }
    FILE *f = fopen("index.txt", "r");
    if (f == NULL)
    {
        printf("Không thể mở file\n");
        return false;
    }
    char user[25];
    while (fscanf(f, "%s", user) != EOF)
    {
        if (strcmp(user, username) == 0)
        {
            fclose(f);
            return false;
        }
    }
    fclose(f);
    return true;
}

bool isValidPassword(char password[])
{
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasNumber = false;
    bool notSpace = true;

    if (strlen(password) < MIN_PASSWORD_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH)
    {
        return false;
    }

    for (int i = 0; i < strlen(password); i++)
    {
        if (isUpper(password[i]))
        {
            hasUppercase = true;
        }
        else if (isLower(password[i]))
        {
            hasLowercase = true;
        }
        else if (isNumber(password[i]))
        {
            hasNumber = true;
        }
        else if (password[i] == ' ')
        {
            notSpace = false;
        }
    }

    return hasUppercase && hasLowercase && hasNumber && notSpace;
}

void registerAccount()
{
    system("cls");
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char x[50];
    FILE *f = fopen("index.txt", "a");
    printf("\n\t=============== Register Page ===============\n\n");
    do
    {
        printf("Username: ");
        fgets(username, sizeof(username), stdin);
        removeEnter(username);
        if (!isValidUsername(username))
        {
            printf("\n⚠️  Username không hợp lệ hoặc đã tồn tại. Hãy thử lại!\n\n");
        }
    } while (!isValidUsername(username));
    fprintf(f, "%s\n", username);
    do
    {
        printf("Password: ");
        enterPassword(password);
        if (!isValidPassword(password))
        {
            printf("\n⚠️  Password không hợp lệ. Hãy thử lại!\n\n");
        }
    } while (!isValidPassword(password));
    encryptPassword(password);
    fprintf(f, "%s\n\n", password);
    fclose(f);
    printf("\n\n👏 Đăng kí thành công!");
    Sleep(500);
    loading();
}

bool checkPassword(char PASS[], char pass[])
{
    decryptPassword(PASS);
    if (strcmp(PASS, pass) == 0)
        return true;
    return false;
}

bool checkUsername(char USER[], char user[])
{
    if (strcmp(USER, user) == 0)
        return true;
    return false;
}

bool checkUsernameAndPassword(char user[], char pass[])
{
    char username[25];
    char password[25];
    FILE *f = fopen("index.txt", "r");
    if (f == NULL)
    {
        printf("Không thể mở file\n");
        return false;
    }
    while (fscanf(f, "%s", username) != EOF)
    {
        if (username[0] == '\0')
            continue;
        if (fscanf(f, "%s", password) != EOF)
        {
            if (checkUsername(username, user) && checkPassword(password, pass))
            {
                fclose(f);
                return true;
            }
        }
    }
    fclose(f);
    return false;
}

bool login()
{
    system("cls");
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int checkLogin = 0;
    printf("\n\t=============== Login Page ===============\n\n");
    while (checkLogin < 3)
    {
        printf("Username : ");
        fgets(username, MAX_USERNAME_LENGTH, stdin);
        removeEnter(username);
        printf("Password : ");
        enterPassword(password);
        if (checkUsernameAndPassword(username, password))
        {
            printf("\n\n👏 Đăng nhập thành công!");
            Sleep(500);
            loading();
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
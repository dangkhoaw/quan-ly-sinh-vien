#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 30
#define MIN_USERNAME_LENGTH 5
#define MAX_PASSWORD_LENGTH 30
#define MIN_PASSWORD_LENGTH 8
#define MAX_SIZE 100
#define MAX_CLASS 11
#define KEY 15

int countClass = 0;
char facultyCode[10];
char academicYear[10];
char facultyName[50];
int temp = 0;

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
    int studentOrder;
    STUDENT *std;
};
typedef struct StudentList *STUDENTLIST;

//------------------------------------------------------------------------------------------------------------------------

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
    return c >= '0' && c <= '9';
}

bool isLower(char c)
{
    return c >= 'a' && c <= 'z';
}

bool isUpper(char c)
{
    return c >= 'A' && c <= 'Z';
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

//------------------------------------------------------------------------------------------------------------------------

STUDENTLIST createClass(int maxSize)
{
    STUDENTLIST Class = malloc(sizeof(struct StudentList));
    Class->count = 0;
    Class->studentOrder = 0;
    Class->maxSize = maxSize;
    Class->std = malloc(maxSize * sizeof(struct Student));
    return Class;
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

void printListClassName()
{
    if (strcmp(facultyCode, "101") == 0)
    {
        printf("\n📚 %sC1A\n", academicYear);
        printf("📚 %sC1B\n", academicYear);
        printf("📚 %sC1C\n", academicYear);
        printf("📚 %sC1D\n", academicYear);
        printf("📚 %sCDT1\n", academicYear);
        printf("📚 %sCDT2\n", academicYear);
        printf("📚 %sCDT3\n", academicYear);
        printf("📚 %sCDT4\n", academicYear);
        printf("📚 %sCKHK\n", academicYear);
    }
    else if (strcmp(facultyCode, "102") == 0)
    {
        printf("\n📚 %sT_DT1\n", academicYear);
        printf("📚 %sT_DT2\n", academicYear);
        printf("📚 %sT_DT3\n", academicYear);
        printf("📚 %sT_DT4\n", academicYear);
        printf("📚 %sT_KHDL1\n", academicYear);
        printf("📚 %sT_KHDL2\n", academicYear);
        printf("📚 %sT_Nhat1\n", academicYear);
        printf("📚 %sT_Nhat2\n", academicYear);
    }
    else if (strcmp(facultyCode, "103") == 0)
    {
        printf("\n📚 %sC4A\n", academicYear);
        printf("📚 %sC4B\n", academicYear);
        printf("📚 %sC4C\n", academicYear);
        printf("📚 %sHTCN\n", academicYear);
        printf("📚 %sKTOTO1\n", academicYear);
        printf("📚 %sKTOTO2\n", academicYear);
        printf("📚 %sKTTT\n", academicYear);
    }
    else if (strcmp(facultyCode, "104") == 0)
    {
        printf("\n📚 %sN1\n", academicYear);
        printf("📚 %sN2\n", academicYear);
    }
    else if (strcmp(facultyCode, "105") == 0)
    {
        printf("\n📚 %sD1\n", academicYear);
        printf("📚 %sD2\n", academicYear);
        printf("📚 %sD3\n", academicYear);
        printf("📚 %sD4\n", academicYear);
        printf("📚 %sD5\n", academicYear);
        printf("📚 %sTDH1\n", academicYear);
        printf("📚 %sTDH2\n", academicYear);
        printf("📚 %sTDH3\n", academicYear);
    }
    else if (strcmp(facultyCode, "106") == 0)
    {
        printf("\n📚 %sDT1\n", academicYear);
        printf("📚 %sDT2\n", academicYear);
        printf("📚 %sDT3\n", academicYear);
        printf("📚 %sDT4\n", academicYear);
        printf("📚 %sKTMT1\n", academicYear);
        printf("📚 %sKTMT2\n", academicYear);
    }
    else if (strcmp(facultyCode, "107") == 0)
    {
        printf("\n📚 %sH2A\n", academicYear);
        printf("📚 %sH2B\n", academicYear);
        printf("📚 %sH2C\n", academicYear);
        printf("📚 %sH5\n", academicYear);
        printf("📚 %sKTHH1\n", academicYear);
        printf("📚 %sKTHH2\n", academicYear);
        printf("📚 %sSH1\n", academicYear);
        printf("📚 %sSH2\n", academicYear);
        printf("📚 %sSHYD\n", academicYear);
    }
    else if (strcmp(facultyCode, "109") == 0)
    {
        printf("\n📚 %sBIM_AI\n", academicYear);
        printf("📚 %sCSHT\n", academicYear);
        printf("📚 %sVLXD\n", academicYear);
        printf("📚 %sX3\n", academicYear);
    }
    else if (strcmp(facultyCode, "110") == 0)
    {
        printf("\n📚 %sX1A\n", academicYear);
        printf("📚 %sX1B\n", academicYear);
        printf("📚 %sX1C\n", academicYear);
        printf("📚 %sX1D\n", academicYear);
    }
    else if (strcmp(facultyCode, "111") == 0)
    {
        printf("\n📚 %sDTTM\n", academicYear);
        printf("📚 %sTHXD\n", academicYear);
        printf("📚 %sX2\n", academicYear);
    }
    else if (strcmp(facultyCode, "117") == 0)
    {
        printf("\n📚 %sMT\n", academicYear);
        printf("📚 %sQLMT\n", academicYear);
    }
    else if (strcmp(facultyCode, "118") == 0)
    {
        printf("\n📚 %sKX1\n", academicYear);
        printf("📚 %sKX2\n", academicYear);
        printf("📚 %sKX3\n", academicYear);
        printf("📚 %sQLCN1\n", academicYear);
        printf("📚 %sQLCN2\n", academicYear);
        printf("📚 %sQLCN3\n", academicYear);
    }
    else if (strcmp(facultyCode, "121") == 0)
    {
        printf("\n📚 %sKT1\n", academicYear);
        printf("📚 %sKT2\n", academicYear);
    }
    else if (strcmp(facultyCode, "123") == 0)
    {
        printf("\n📚 %sPFIEV1\n", academicYear);
        printf("\n📚 %sPFIEV2\n", academicYear);
        printf("\n📚 %sPFIEV3\n", academicYear);
        printf("📚 %sES\n", academicYear);
        printf("📚 %sECE\n", academicYear);
    }
}
void printFacultyName()
{
    printf("\n📚 101: Khoa Cơ khí\n");
    printf("📚 102: Khoa Công nghệ Thông tin\n");
    printf("📚 103: Khoa Cơ khí Giao thông\n");
    printf("📚 104: Khoa CN Nhiệt-Điện lạnh\n");
    printf("📚 105: Khoa Điện\n");
    printf("📚 106: Khoa Điện tử Viễn Thông\n");
    printf("📚 107: Khoa Hóa\n");
    printf("📚 109: Khoa Xây dựng Cầu-Đường\n");
    printf("📚 110: Khoa Xây dựng Dân dụng - Công nghiệp\n");
    printf("📚 111: Khoa Xây dựng công trình thủy\n");
    printf("📚 117: Khoa Môi trường\n");
    printf("📚 118: Khoa Quản lí dự án\n");
    printf("📚 121: Khoa Kiến trúc\n");
    printf("📚 123: Khoa Khoa học Công nghệ tiên tiến\n");
}

void enterCode()
{
    printf("\n➡️  Mời bạn nhập vào mã khóa: ");
    scanf("%s", academicYear);

    printFacultyName();
    do
    {
        printf("\n➡️  Mời bạn nhập vào mã khoa: ");
        scanf("%s", facultyCode);
        if (checkFacultyCode() == 0)
            printf("\n⚠️ Sai mã khoa, mời nhập lại\n");
    } while (checkFacultyCode() == 0);

    generateFacultyName();
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
    Class->studentOrder++;
    classList[countClass] = Class;
}

void printToFile(STUDENTLIST *classList, FILE *f, int position)
{
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

void printNewStudentToFile(STUDENTLIST *classList, FILE *f, int position, STUDENT newStudent)
{
    if (strcmp(classList[position]->std[0]->ID, "") == 0)
    {
        fprintf(f, " %-5d %-29s %-11s %-15s %s\n", classList[position]->studentOrder, newStudent->fullName, newStudent->sex, newStudent->birthDay, newStudent->address);
    }
    else if (strcmp(classList[position]->std[0]->email, "") == 0)
    {
        fprintf(f, " %-5d %-15s %-28s %-11s %-15s %s\n", classList[position]->studentOrder, newStudent->ID, newStudent->fullName, newStudent->sex, newStudent->birthDay, newStudent->address);
    }
    else
    {
        fprintf(f, " %-5d %-15s %-26s %-31s %-12s %-15s %s\n", classList[position]->studentOrder, newStudent->ID, newStudent->fullName, newStudent->email, newStudent->sex, newStudent->birthDay, newStudent->address);
    }
}

void inputStudentInfo(STUDENT student)
{
    printf("\n➡️  Nhập họ và lót: ");
    fgets(student->lastName, sizeof(student->lastName), stdin);
    removeEnter(student->lastName);
    toName(student->lastName);

    printf("\n➡️  Nhập tên: ");
    fgets(student->firstName, sizeof(student->firstName), stdin);
    removeEnter(student->firstName);
    toName(student->firstName);

    printf("\n➡️  Nhập ngày sinh: ");
    fgets(student->birthDay, sizeof(student->birthDay), stdin);
    removeEnter(student->birthDay);

    printf("\n➡️  Nhập giới tính: ");
    fgets(student->sex, sizeof(student->sex), stdin);
    removeEnter(student->sex);
    toName(student->sex);

    printf("\n➡️  Nhập địa chỉ: ");
    fgets(student->address, sizeof(student->address), stdin);
    removeEnter(student->address);

    strcpy(student->ID, "");

    strcpy(student->email, "");

    sprintf(student->fullName, "%s %s", student->lastName, student->firstName);
}

bool confirmExit()
{
    char choice;
    printf("\n❓ Bạn có muốn thoát không? (Y/N): ");
    scanf(" %c", &choice);
    fflush(stdin);
    if (choice == 'Y' || choice == 'y')
    {
        return true;
    }
    return false;
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
        printListClassName();
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
            class = classList[i];
            FILE *f = fopen(classList[i]->fileName, "a");
            int numStd;
            do
            {
                printf("\n🔔 Lớp %s đã có %d sinh viên\n", classList[i]->className, classList[i]->count);
                printf("\n➡️  Nhập số sinh viên muốn thêm: ");
                scanf("%d", &numStd);
                if (numStd <= 0 || numStd > MAX_SIZE - classList[i]->count)
                {
                    printf("\n⚠️ Số lượng học sinh không hợp lệ ⚠️\n");
                }
                fflush(stdin);
            } while (numStd + classList[i]->count > MAX_SIZE);
            for (int j = 0; j < numStd; j++)
            {
                STUDENT newStudent = malloc(sizeof(struct Student));

                inputStudentInfo(newStudent);

                insertStudent(classList, class, newStudent);

                printNewStudentToFile(classList, f, i, newStudent);

                printf("\n👏 Đã thêm sinh viên thành công\n");
                if (j == numStd - 1 || confirmExit())
                {
                    fclose(f);
                    return;
                }
            }
        }
    }

    strcpy(class->className, className);
    sprintf(class->fileName, "K%s-%s-%s", academicYear, class->className, facultyName);

    FILE *f = fopen(class->fileName, "w");
    fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", class->className);

    int numStd;
    printf("\n➡️  Nhập số sinh viên muốn thêm: ");
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

        inputStudentInfo(newStudent);

        insertStudent(classList, class, newStudent);
        printf("\n👏 Đã thêm sinh viên thành công\n");
        if (i == numStd - 1 || confirmExit())
        {
            printToFile(classList, f, countClass);
            countClass++;
            fclose(f);
            return;
        }
    }
}

bool isSorted(STUDENTLIST class)
{
    for (int i = 1; i < class->count; i++)
    {
        if (strcmp(class->std[i]->firstName, class->std[i - 1]->firstName) < 0 ||
            (strcmp(class->std[i]->firstName, class->std[i - 1]->firstName) == 0 &&
             strcmp(class->std[i]->lastName, class->std[i - 1]->lastName) < 0))
        {
            return false;
        }
    }
    return true;
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

    printf("\n➡️  Nhập tên lớp cần sắp xếp: ");
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
                // sprintf(fileName, "input_%s.txt", classList[i]->className);
                // FILE *f = fopen(fileName, "w");
                // printToFile(classList, f, i);
                // fclose(f);
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

            // char fileName[15];
            // sprintf(fileName, "input_%s.txt", classList[i]->className);
            FILE *f = fopen(classList[i]->fileName, "w");
            fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", classList[i]->className);
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

    printf("\n➡️  Nhập vào tên lớp cần in danh sách: ");
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
                printf("\n🔔 Cần sắp xếp lớp %s để in danh sách\n", classList[i]->className);
                return;
            }

            found = 1;
            if (classList[i]->count == 0)
            {
                printf("\n🔔 Danh sách không có sinh viên\n");
                return;
            }

            FILE *f = fopen(classList[i]->fileName, "w");
            fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", classList[i]->className);

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
                    fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", classList[i]->className);
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
                fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", classList[i]->className);
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
                        fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", classList[i]->className);
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
    printf("\n┌───────────────────────┐");
    printf("\n│ 1. Tìm kiếm theo tên  │");
    printf("\n│ 2. Tìm kiếm theo ID   │");
    printf("\n└───────────────────────┘");
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
    printf("\n┌───────────────────────────────────────────┐\n");
    printf("│   1.  Thêm sinh viên                      │\n");
    printf("│   2.  Sắp xếp sinh viên                   │\n");
    printf("│   3.  Xóa sinh viên                       │\n");
    printf("│   4.  Tìm sinh viên                       │\n");
    printf("│   5.  Cấp mã sinh viên                    │\n");
    printf("│   6.  Cấp email                           │\n");
    printf("│   7.  In danh sách sinh viên              │\n");
    printf("│   8.  Thoát                               │\n");
    printf("└───────────────────────────────────────────┘\n");
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

void readUsernameAndPasswordFromFile(FILE *f, char username[], char password[])
{
    char get;
    int index = 0;

    while ((get = fgetc(f)) != ':' && get != EOF)
    {
        username[index++] = get;
    }
    username[index] = '\0';

    index = 0;
    while ((get = fgetc(f)) != '\n' && get != EOF)
    {
        password[index++] = get;
    }
    password[index] = '\0';
}

bool isValidUsername(char username[])
{
    if (strlen(username) < MIN_USERNAME_LENGTH || strlen(username) > MAX_USERNAME_LENGTH)
    {
        printf("\n⚠️  Username phải có từ %d đến %d ký tự\n\n", MIN_USERNAME_LENGTH, MAX_USERNAME_LENGTH);
        return false;
    }
    for (int i = 0; i < strlen(username); i++)
    {
        if (username[i] == ' ')
        {
            printf("\n⚠️  Username không được chứa khoảng trắng\n\n");
            return false;
        }
    }
    FILE *f = fopen("index.txt", "r");
    if (f == NULL)
    {
        printf("Không thể mở file\n");
        return false;
    }
    char user[MAX_USERNAME_LENGTH], pass[MAX_PASSWORD_LENGTH];
    while (1)
    {
        if (feof(f))
            break;

        readUsernameAndPasswordFromFile(f, user, pass);

        if (strcmp(user, username) == 0)
        {
            printf("\n⚠️  Username đã tồn tại\n\n");
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
    bool hasSpace = false;

    if (strlen(password) < MIN_PASSWORD_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH)
    {
        printf("\n\n⚠️  Password phải có ít nhất %d ký tự\n\n", MIN_PASSWORD_LENGTH);
        return false;
    }

    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] == ' ')
        {
            hasSpace = true;
        }
        else if (isUpper(password[i]))
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
    }
    if (!hasUppercase)
    {
        printf("\n\n⚠️  Password phải chứa ít nhất 1 ký tự in hoa\n\n");
        return false;
    }
    if (!hasLowercase)
    {
        printf("\n\n⚠️  Password phải chứa ít nhất 1 ký tự thường\n\n");
        return false;
    }
    if (!hasNumber)
    {
        printf("\n\n⚠️  Password phải chứa ít nhất 1 số\n\n");
        return false;
    }
    if (hasSpace)
    {
        printf("\n\n⚠️  Password không được chứa khoảng trắng\n\n");
        return false;
    }

    return true;
}

void registerAccount()
{
    system("cls");
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    FILE *f = fopen("index.txt", "a");
    printf("\n\t=============== Register Page ===============\n\n");

    printf("\n(Username phải có từ %d đến %d ký tự và không chứa khoảng trắng)", MIN_USERNAME_LENGTH, MAX_USERNAME_LENGTH);
    printf("\n(Password dài tối thiểu %d kí tự, phải chứa ít nhất 1 ký tự in hoa, 1 ký tự thường, 1 số và không chứa khoảng trắng)\n\n", MIN_PASSWORD_LENGTH);

    do
    {
        printf("Username: ");
        fgets(username, sizeof(username), stdin);
        removeEnter(username);
    } while (!isValidUsername(username));
    fprintf(f, "%s:", username);
    do
    {
        printf("Password: ");
        enterPassword(password);
    } while (!isValidPassword(password));
    encryptPassword(password);
    fprintf(f, "%s\n", password);
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
    FILE *f = fopen("index.txt", "r");
    char username[25];
    char password[25];
    while (1)
    {
        if (feof(f))
            break;

        readUsernameAndPasswordFromFile(f, username, password);

        if (checkUsername(username, user) && checkPassword(password, pass))
        {
            fclose(f);
            return true;
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
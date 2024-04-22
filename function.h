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
#define and &&
#define or ||

char facultyCode[10];
char academicYear[10];
char classList[10][15];
int numClass = 0;

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
    bool isSorted;
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
    return c >= '0' and c <= '9';
}

bool isLower(char c)
{
    return c >= 'a' and c <= 'z';
}

bool isUpper(char c)
{
    return c >= 'A' and c <= 'Z';
}

char *toLower(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] >= 65 and s[i] <= 90)
            s[i] += 32;
    return s;
}

char *toUpper(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] >= 97 and s[i] <= 122)
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
        if (i == 0 or (i > 0 and s[i - 1] == ' '))
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
    if (strcmp(facultyCode, "101") == 0 or strcmp(facultyCode, "102") == 0 or strcmp(facultyCode, "103") == 0 or
        strcmp(facultyCode, "104") == 0 or strcmp(facultyCode, "105") == 0 or strcmp(facultyCode, "106") == 0 or
        strcmp(facultyCode, "107") == 0 or strcmp(facultyCode, "109") == 0 or strcmp(facultyCode, "110") == 0 or
        strcmp(facultyCode, "111") == 0 or strcmp(facultyCode, "117") == 0 or strcmp(facultyCode, "118") == 0 or
        strcmp(facultyCode, "121") == 0 or strcmp(facultyCode, "123") == 0)
    {
        return true;
    }
    printf("\n⚠️ Mã khoa không hợp lệ, mời nhập lại\n");
    return false;
}

void countClass()
{
    if (strcmp(facultyCode, "101") == 0)
    {
        sprintf(classList[0], "%sC1A", academicYear);
        sprintf(classList[1], "%sC1B", academicYear);
        sprintf(classList[2], "%sC1C", academicYear);
        sprintf(classList[3], "%sC1D", academicYear);
        sprintf(classList[4], "%sCDT1", academicYear);
        sprintf(classList[5], "%sCDT2", academicYear);
        sprintf(classList[6], "%sCDT3", academicYear);
        sprintf(classList[7], "%sCDT4", academicYear);
        sprintf(classList[8], "%sCKHK", academicYear);

        numClass = 9;
    }
    else if (strcmp(facultyCode, "102") == 0)
    {
        sprintf(classList[0], "%sT_DT1", academicYear);
        sprintf(classList[1], "%sT_DT2", academicYear);
        sprintf(classList[2], "%sT_DT3", academicYear);
        sprintf(classList[3], "%sT_DT4", academicYear);
        sprintf(classList[4], "%sT_KHDL1", academicYear);
        sprintf(classList[5], "%sT_KHDL2", academicYear);
        sprintf(classList[6], "%sT_Nhat1", academicYear);
        sprintf(classList[7], "%sT_Nhat2", academicYear);

        numClass = 8;
    }
    else if (strcmp(facultyCode, "103") == 0)
    {
        sprintf(classList[0], "%sC4A", academicYear);
        sprintf(classList[1], "%sC4B", academicYear);
        sprintf(classList[2], "%sC4C", academicYear);
        sprintf(classList[3], "%sHTCN", academicYear);
        sprintf(classList[4], "%sKTOTO1", academicYear);
        sprintf(classList[5], "%sKTOTO2", academicYear);
        sprintf(classList[6], "%sKTTT", academicYear);

        numClass = 7;
    }
    else if (strcmp(facultyCode, "104") == 0)
    {
        sprintf(classList[0], "%sN1", academicYear);
        sprintf(classList[1], "%sN2", academicYear);

        numClass = 2;
    }
    else if (strcmp(facultyCode, "105") == 0)
    {
        sprintf(classList[0], "%sD1", academicYear);
        sprintf(classList[1], "%sD2", academicYear);
        sprintf(classList[2], "%sD3", academicYear);
        sprintf(classList[3], "%sD4", academicYear);
        sprintf(classList[4], "%sD5", academicYear);
        sprintf(classList[5], "%sTDH1", academicYear);
        sprintf(classList[6], "%sTDH2", academicYear);
        sprintf(classList[7], "%sTDH3", academicYear);

        numClass = 8;
    }
    else if (strcmp(facultyCode, "106") == 0)
    {
        sprintf(classList[0], "%sDT1", academicYear);
        sprintf(classList[1], "%sDT2", academicYear);
        sprintf(classList[2], "%sDT3", academicYear);
        sprintf(classList[3], "%sDT4", academicYear);
        sprintf(classList[4], "%sKTMT1", academicYear);
        sprintf(classList[5], "%sKTMT2", academicYear);

        numClass = 6;
    }
    else if (strcmp(facultyCode, "107") == 0)
    {
        sprintf(classList[0], "%sH2A", academicYear);
        sprintf(classList[1], "%sH2B", academicYear);
        sprintf(classList[2], "%sH2C", academicYear);
        sprintf(classList[3], "%sH5", academicYear);
        sprintf(classList[4], "%sKTHH1", academicYear);
        sprintf(classList[5], "%sKTHH2", academicYear);
        sprintf(classList[6], "%sSH1", academicYear);
        sprintf(classList[7], "%sSH2", academicYear);
        sprintf(classList[8], "%sSHYD", academicYear);

        numClass = 9;
    }
    else if (strcmp(facultyCode, "109") == 0)
    {
        sprintf(classList[0], "%sBIM_AI", academicYear);
        sprintf(classList[1], "%sCSHT", academicYear);
        sprintf(classList[2], "%sVLXD", academicYear);
        sprintf(classList[3], "%sX3", academicYear);

        numClass = 4;
    }
    else if (strcmp(facultyCode, "110") == 0)
    {
        sprintf(classList[0], "%sX1A", academicYear);
        sprintf(classList[1], "%sX1B", academicYear);
        sprintf(classList[2], "%sX1C", academicYear);
        sprintf(classList[3], "%sX1D", academicYear);

        numClass = 4;
    }
    else if (strcmp(facultyCode, "111") == 0)
    {
        sprintf(classList[0], "%sDTTM", academicYear);
        sprintf(classList[1], "%sTHXD", academicYear);
        sprintf(classList[2], "%sX2", academicYear);

        numClass = 3;
    }
    else if (strcmp(facultyCode, "117") == 0)
    {
        sprintf(classList[0], "%sMT", academicYear);
        sprintf(classList[1], "%sQLMT", academicYear);

        numClass = 2;
    }
    else if (strcmp(facultyCode, "118") == 0)
    {
        sprintf(classList[0], "%sKX1", academicYear);
        sprintf(classList[1], "%sKX2", academicYear);
        sprintf(classList[2], "%sKX3", academicYear);
        sprintf(classList[3], "%sQLCN1", academicYear);
        sprintf(classList[4], "%sQLCN2", academicYear);
        sprintf(classList[5], "%sQLCN3", academicYear);

        numClass = 6;
    }
    else if (strcmp(facultyCode, "121") == 0)
    {
        sprintf(classList[0], "%sKT1", academicYear);
        sprintf(classList[1], "%sKT2", academicYear);

        numClass = 2;
    }
    else if (strcmp(facultyCode, "123") == 0)
    {
        sprintf(classList[0], "%sPFIEV1", academicYear);
        sprintf(classList[1], "%sPFIEV2", academicYear);
        sprintf(classList[2], "%sPFIEV3", academicYear);
        sprintf(classList[3], "%sES", academicYear);
        sprintf(classList[4], "%sECE", academicYear);

        numClass = 5;
    }
}

void printListClassName()
{
    countClass();
    if (strcmp(facultyCode, "101") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "102") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "103") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "104") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "105") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "106") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "107") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "109") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "110") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "111") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "117") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "118") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "121") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "123") == 0)
    {
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
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
    } while (checkFacultyCode() == 0);
}

bool checkClassName(char className[])
{
    if (strcmp(facultyCode, "101") == 0) // Khoa Cơ khí
    {
        if (strstr(className, "C1") or strstr(className, "CDT") or strstr(className, "CKHK"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "102") == 0) // Khoa Công nghệ Thông tin
    {
        if (strstr(className, "T_DT") or strstr(className, "T_KHDL") or strstr(className, "T_Nhat"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "103") == 0) // Khoa Cơ khí Giao thông
    {
        if (strstr(className, "C4") or strstr(className, "HTCN") or strstr(className, "KTOTO") or strstr(className, "KTTT"))
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
        if (strstr(className, "D") or strstr(className, "TDH"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "106") == 0) // Khoa Điện tử Viễn Thông
    {
        if (strstr(className, "DT") or strstr(className, "KTMT"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "107") == 0) // Khoa Hóa
    {
        if (strstr(className, "H2") or strstr(className, "H5") or strstr(className, "KTHH") or strstr(className, "SH") or strstr(className, "SHYD"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "109") == 0) // Khoa Xây dựng Cầu-Đường
    {
        if (strstr(className, "BIM_AI") or strstr(className, "CSHT") or strstr(className, "VLXD") or strstr(className, "X3"))
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
        if (strstr(className, "DTTM") or strstr(className, "THXD") or strstr(className, "X2"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "117") == 0) // Khoa Môi trường
    {
        if (strstr(className, "MT") or strstr(className, "QLMT"))
        {
            return true;
        }
    }
    else if (strcmp(facultyCode, "118") == 0) // Khoa Quản lí dự án
    {
        if (strstr(className, "KX") or strstr(className, "QLCN"))
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
        if (strstr(className, "PFIEV") or strstr(className, "ES") or strstr(className, "ECE"))
        {
            return true;
        }
    }
    printf("\n⚠️  Tên lớp không hợp lệ, cần nhập lại\n");
    return false;
}

void insertStudent(STUDENTLIST Class, STUDENT std)
{
    if (Class->count >= Class->maxSize)
        exit(1);
    Class->std[Class->count] = std;
    Class->count++;
    Class->studentOrder++;
}

void printToFile(STUDENTLIST class, FILE *f)
{
    if (strcmp(class->std[0]->ID, "") == 0)
    {
        fprintf(f, "%-11s %-25s %-17s %-16s %s\n", "STT", "Họ và tên", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < class->count; i++)
        {
            fprintf(f, " %-5d %-29s %-11s %-15s %s\n", i + 1, class->std[i]->fullName, class->std[i]->sex, class->std[i]->birthDay, class->std[i]->address);
        }
    }
    else if (strcmp(class->std[0]->email, "") == 0)
    {
        fprintf(f, "%-5s %-23s %-24s %-17s %-16s %s\n", "STT", "Mã sinh viên", "Họ và tên", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < class->count; i++)
        {
            fprintf(f, " %-5d %-15s %-28s %-11s %-15s %s\n", i + 1, class->std[i]->ID, class->std[i]->fullName, class->std[i]->sex, class->std[i]->birthDay, class->std[i]->address);
        }
    }
    else
    {
        fprintf(f, "%-5s %-23s %-33s %-21s %-17s %-16s %s\n", "STT", "Mã sinh viên", "Họ và tên", "Email", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < class->count; i++)
        {
            fprintf(f, " %-5d %-15s %-26s %-31s %-12s %-15s %s\n", i + 1, class->std[i]->ID, class->std[i]->fullName, class->std[i]->email, class->std[i]->sex, class->std[i]->birthDay, class->std[i]->address);
        }
    }
}

void printNewStudentToFile(FILE *f, STUDENT newStudent)
{
    fprintf(f, "%s:%s:%s:%s:%s:%s:%s\n", newStudent->ID, newStudent->lastName, newStudent->firstName, newStudent->email, newStudent->sex, newStudent->birthDay, newStudent->address);
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

bool isSorted(STUDENTLIST class)
{
    for (int i = 1; i < class->count; i++)
    {
        if (strcmp(class->std[i]->firstName, class->std[i - 1]->firstName) < 0 or
            (strcmp(class->std[i]->firstName, class->std[i - 1]->firstName) == 0 and
             strcmp(class->std[i]->lastName, class->std[i - 1]->lastName) < 0))
        {
            return false;
        }
    }
    return true;
}

void readStudentInfoFromFile(FILE *f, STUDENTLIST class)
{
    while (!feof(f))
    {
        STUDENT newStudent = malloc(sizeof(struct Student));
        char get;
        int index = 0;
        while ((get = fgetc(f)) != ':' and get != EOF)
        {
            newStudent->ID[index++] = get;
        }
        newStudent->ID[index] = '\0';
        index = 0;
        while ((get = fgetc(f)) != ':' and get != EOF)
        {
            newStudent->lastName[index++] = get;
        }
        newStudent->lastName[index] = '\0';
        index = 0;
        while ((get = fgetc(f)) != ':' and get != EOF)
        {
            newStudent->firstName[index++] = get;
        }
        newStudent->firstName[index] = '\0';
        index = 0;
        while ((get = fgetc(f)) != ':' and get != EOF)
        {
            newStudent->email[index++] = get;
        }
        newStudent->email[index] = '\0';
        index = 0;
        while ((get = fgetc(f)) != ':' and get != EOF)
        {
            newStudent->sex[index++] = get;
        }
        newStudent->sex[index] = '\0';
        index = 0;
        while ((get = fgetc(f)) != ':' and get != EOF)
        {
            newStudent->birthDay[index++] = get;
        }
        newStudent->birthDay[index] = '\0';
        index = 0;
        while ((get = fgetc(f)) != '\n' and get != EOF)
        {
            newStudent->address[index++] = get;
        }
        newStudent->address[index] = '\0';
        if (newStudent->ID[0] == '\0' and newStudent->lastName[0] == '\0' and newStudent->firstName[0] == '\0' and
            newStudent->email[0] == '\0' and newStudent->sex[0] == '\0' and newStudent->birthDay[0] == '\0' and newStudent->address[0] == '\0')
        {
            break;
        }
        else
        {
            sprintf(newStudent->fullName, "%s %s", newStudent->lastName, newStudent->firstName);
            insertStudent(class, newStudent);
        }
    }
    if (isSorted(class))
        class->isSorted = true;
    else
        class->isSorted = false;
}

bool confirmExit()
{
    char choice;
    printf("\n❓ Bạn có muốn tiếp tục không? (Y/N): ");
    scanf(" %c", &choice);
    fflush(stdin);
    if (choice == 'Y' or choice == 'y')
    {
        return false;
    }
    return true;
}

void addStudent()
{
    char className[15];
    do
    {
        printListClassName();
        printf("\n➡️  Mời bạn nhập vào tên lớp: ");
        fgets(className, sizeof(className), stdin);
        removeEnter(className);
        toUpper(className);
    } while (!checkClassName(className));

    char fileName[50];
    sprintf(fileName, "%s-%s.txt", facultyCode, className);
    FILE *fileCheck = fopen(fileName, "r");
    if (fileCheck == NULL)
    {
        fclose(fileCheck);

        STUDENTLIST class = createClass(MAX_SIZE);
        FILE *f = fopen(fileName, "w");

        while (true)
        {
            STUDENT newStudent = malloc(sizeof(struct Student));

            inputStudentInfo(newStudent);

            printNewStudentToFile(f, newStudent);
            printf("\n👏 Đã thêm sinh viên thành công\n");

            if (confirmExit())
            {
                fclose(f);
                return;
            }
        }
    }
    else
    {
        fileCheck = fopen(fileName, "a");
        while (true)
        {
            STUDENT newStudent = malloc(sizeof(struct Student));

            inputStudentInfo(newStudent);

            printNewStudentToFile(fileCheck, newStudent);
            printf("\n👏 Đã thêm sinh viên thành công\n");
            if (confirmExit())
            {
                fclose(fileCheck);
                return;
            }
        }
    }
}

void swapStudent(STUDENT *std1, STUDENT *std2)
{
    STUDENT tmp = *std1;
    *std1 = *std2;
    *std2 = tmp;
}

void sortStudent()
{
    printListClassName();
    char className[15];
    do
    {
        printf("\n➡️  Nhập tên lớp cần sắp xếp: ");
        fgets(className, sizeof(className), stdin);
        removeEnter(className);
        toUpper(className);
    } while (!checkClassName(className));

    char fileName[50];
    sprintf(fileName, "%s-%s.txt", facultyCode, className);
    FILE *fileCheck = fopen(fileName, "r");
    if (fileCheck == NULL)
    {
        printf("\n🔔 Lớp %s chưa tồn tại\n", className);
        return;
    }
    else
    {
        STUDENTLIST class = createClass(MAX_SIZE);
        readStudentInfoFromFile(fileCheck, class);
        fclose(fileCheck);
        if (class->isSorted)
        {
            printf("\n🔔 Lớp %s đã được sắp xếp\n", className);
            return;
        }
        for (int i = 0; i < class->count - 1; i++)
        {
            for (int j = i + 1; j < class->count; j++)
            {
                if (strcmp(class->std[i]->firstName, class->std[j]->firstName) > 0 or
                    (strcmp(class->std[i]->firstName, class->std[j]->firstName) == 0 and
                     strcmp(class->std[i]->lastName, class->std[j]->lastName) > 0))
                {
                    swapStudent(&class->std[i], &class->std[j]);
                }
            }
        }
        FILE *f = fopen(fileName, "w");
        for (int i = 0; i < class->count; i++)
        {
            printNewStudentToFile(f, class->std[i]);
        }
        printf("\n🔔 Đã sắp xếp lớp %s\n", className);
        fclose(f);
    }
}

void printListStudent()
{
    printListClassName();
    char className[15];
    do
    {
        printf("\n➡️  Nhập vào tên lớp cần in danh sách: ");
        fgets(className, sizeof(className), stdin);
        removeEnter(className);
        toUpper(className);
    } while (!checkClassName(className));

    char fileName[50];
    sprintf(fileName, "%s-%s.txt", facultyCode, className);
    FILE *fileCheck = fopen(fileName, "r");
    if (fileCheck == NULL)
    {
        printf("\n🔔 Lớp %s chưa tồn tại\n", className);
        return;
    }
    else
    {
        STUDENTLIST class = createClass(MAX_SIZE);
        readStudentInfoFromFile(fileCheck, class);
        fclose(fileCheck);
        if (class->isSorted == false)
        {
            printf("\n🔔 Lớp chưa được sắp xếp, mời bạn sắp xếp lớp trước\n");
            return;
        }
        if (class->count == 0)
        {
            printf("\n🔔 Lớp %s chưa có sinh viên nào\n", className);
            return;
        }

        sprintf(fileName, "%s-%s-report.txt", facultyCode, className);
        FILE *f = fopen(fileName, "w");
        fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", className);
        printToFile(class, f);
        printf("\n👏 Đã in danh sách sinh viên của lớp %s\n", className);
        fclose(f);
    }
}

void generateID()
{
}

void generateEmail()
{
}

void removeStudent()
{
}

void menuSearch()
{
    printf("\n┌───────────────────────┐");
    printf("\n│ 1. Tìm kiếm theo tên  │");
    printf("\n│ 2. Tìm kiếm theo ID   │");
    printf("\n└───────────────────────┘");
    printf("\n\nMời bạn chọn: ");
}

void searchStudentByName()
{
    printf("\n➡️  Mời nhập tên sinh viên: ");
    char name[35];
    fflush(stdin);
    fgets(name, sizeof(name), stdin);
    removeEnter(name);
    toName(name);

    int found = 0;
    countClass();
    for (int i = 0; i < numClass; i++)
    {
        char fileName[50];
        sprintf(fileName, "%s-%s.txt", facultyCode, classList[i]);
        FILE *f = fopen(fileName, "r");
        if (f != NULL)
        {
            STUDENTLIST class = createClass(MAX_SIZE);
            readStudentInfoFromFile(f, class);
            fclose(f);
            for (int j = 0; j < class->count; j++)
            {
                if (strstr(class->std[j]->fullName, name))
                {
                    found = 1;
                    printf("\n🔔 Tìm thấy: %s  %s\n", class->std[j]->ID, class->std[j]->fullName);
                }
            }
        }
        else
            fclose(f);
    }
    if (!found)
        printf("\n🔔 Không tìm thấy sinh viên tên %s\n", name);
}

void searchStudentByID()
{
    char ID[10];
    printf("\n➡️  Mời bạn nhập ID bạn muốn tìm: ");
    fflush(stdin);
    fgets(ID, sizeof(ID), stdin);
    removeEnter(ID);

    int found = 0;
    countClass();
    for (int i = 0; i < numClass; i++)
    {
        STUDENTLIST class = createClass(MAX_SIZE);
        char fileName[50];
        sprintf(fileName, "%s-%s.txt", facultyCode, classList[i]);
        FILE *f = fopen(fileName, "r");
        if (f != NULL)
        {
            readStudentInfoFromFile(f, class);
            fclose(f);
            for (int j = 0; j < class->count; j++)
            {
                if (strcmp(class->std[j]->ID, ID) == 0)
                {
                    found = 1;
                    printf("\n🔔 Tìm thấy: %s  %s\n", class->std[j]->ID, class->std[j]->fullName);
                }
            }
        }
        else
            fclose(f);
    }
    if (!found)
        printf("\n🔔 Không tìm thấy sinh viên có ID %s\n", ID);
}

void searchStudent()
{
    menuSearch();
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        searchStudentByName();
        break;
    case 2:
        searchStudentByID();
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
        if (password[i] >= 'a' and password[i] <= 'z')
        {
            password[i] = (password[i] - 'a' + KEY) % 26 + 'a';
        }
        else if (password[i] >= 'A' and password[i] <= 'Z')
        {
            password[i] = (password[i] - 'A' + KEY) % 26 + 'A';
        }
        else if (password[i] >= '0' and password[i] <= '9')
        {
            password[i] = encodeNumber(password[i]);
        }
    }
}

void decryptPassword(char password[])
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' and password[i] <= 'z')
        {
            password[i] = (password[i] - 'a' - KEY + 26) % 26 + 'a';
        }
        else if (password[i] >= 'A' and password[i] <= 'Z')
        {
            password[i] = (password[i] - 'A' - KEY + 26) % 26 + 'A';
        }
        else if (password[i] >= '0' and password[i] <= '9')
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
        if (get == '\r' or get == '\n')
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

    while ((get = fgetc(f)) != ':' and get != EOF)
    {
        username[index++] = get;
    }
    username[index] = '\0';

    index = 0;
    while ((get = fgetc(f)) != '\n' and get != EOF)
    {
        password[index++] = get;
    }
    password[index] = '\0';
}

bool isValidUsername(char username[])
{
    if (strlen(username) < MIN_USERNAME_LENGTH or strlen(username) > MAX_USERNAME_LENGTH)
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

    if (strlen(password) < MIN_PASSWORD_LENGTH or strlen(password) > MAX_PASSWORD_LENGTH)
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
    while (true)
    {
        if (feof(f))
            break;

        readUsernameAndPasswordFromFile(f, username, password);

        if (checkUsername(username, user) and checkPassword(password, pass))
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
    while (true)
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
            break;
    }
    printf("\n\n🚫 Sai quá nhiều lần. Thoát chương trình\n");
    return false;
}

void runProgram()
{
    enterCode();
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
            addStudent();
            break;
        case 2:
            sortStudent();
            break;
        case 3:
            removeStudent();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            generateID();
            break;
        case 6:
            generateEmail();
            break;
        case 7:
            printListStudent();
            break;
        }
    } while (choice != 8);
    printf("\n👋  Hẹn gặp lại\n");
}

#endif
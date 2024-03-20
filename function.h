#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define USERNAME "admin"
#define PASSWORD "123456789"
#define MAX_LEN_USERNAME 20
#define MAX_LEN_PASSWORLD 20
#define MAX_SIZE 100
#define MAX_CLASS 6

int position = 0;

struct Code
{
    char faculty[5];
    char academicYear[5];
};
typedef struct Code CODE;
struct Student
{
    char ID[10];
    char firstName[100]; // Tên
    char lastName[100];  // Họ
    char email[100];
    char birthDay[100];
    char sex[5];
    char address[1000];
};
typedef struct Student *STUDENT;
struct StudentList
{
    int maxSize;
    int count;
    char className[100];
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
void insertStudent(STUDENTLIST *classList, STUDENTLIST Class, STUDENT std)
{
    if (Class->count >= Class->maxSize)
        exit(1);
    Class->std[Class->count] = std;
    Class->count++;
    classList[position] = Class;
}
void addStudent(STUDENTLIST *classList)
{
    if (position == MAX_CLASS)
    {
        printf("Vượt quá giới hạn lớp học\n");
        return;
    }

    printf("Mời bạn nhập vào tên lớp: ");
    char className[100];
    fgets(className, sizeof(className), stdin);
    removeEnter(className);

    for (int i = 0; i < position; i++)
    {
        if (strcmp(classList[i]->className, className) == 0)
        {
            printf("\nDanh sách lớp %s đã có sinh viên.\n", className);
            return;
        }
    }
    STUDENTLIST class = createClass(MAX_SIZE);
    if (class == NULL)
    {
        printf("\nKhông đủ bộ nhớ để tạo lớp mới.\n");
        return;
    }

    strcpy(class->className, className);

    int numStd;
    printf("Mời bạn nhập vào số sinh viên của lớp %s: ", className);
    scanf("%d", &numStd);
    getchar();

    for (int i = 0; i < numStd; i++)
    {
        STUDENT newStudent = malloc(sizeof(struct Student));
        if (newStudent == NULL)
        {
            printf("\nKhông đủ bộ nhớ để tạo sinh viên mới.\n");
            return;
        }

        printf("\nNhập họ và tên đệm sinh viên thứ %d: ", i + 1);
        fgets(newStudent->lastName, sizeof(newStudent->lastName), stdin);
        removeEnter(newStudent->lastName);
        toName(newStudent->lastName);

        printf("\nNhập tên sinh viên thứ %d: ", i + 1);
        fgets(newStudent->firstName, sizeof(newStudent->firstName), stdin);
        removeEnter(newStudent->firstName);
        toName(newStudent->lastName);

        printf("\nNhập vào ngày sinh: ");
        fgets(newStudent->birthDay, sizeof(newStudent->birthDay), stdin);
        removeEnter(newStudent->birthDay);

        printf("\nNhập vào giới tính: ");
        fgets(newStudent->sex, sizeof(newStudent->sex), stdin);
        removeEnter(newStudent->sex);

        printf("\nNhập vào địa chỉ: ");
        fgets(newStudent->address, sizeof(newStudent->address), stdin);
        removeEnter(newStudent->address);

        insertStudent(classList, class, newStudent);
        printf("\n----Đã thêm sinh viên thành công----\n");
    }
    position++;
}

void printToFile(STUDENTLIST *classList, FILE *f, int pos)
{
    // printf("%-5s%-35s%-20s%-20s%-20s%-s\n", "STT", "Họ và tên", "Ngày sinh", "Giới tính", "Địa chỉ");
    for (int i = 0; i < classList[pos]->count; i++)
    {
        fprintf(f, "%-5d%-10s%-20s%-20s%-20s%-s\n", i + 1, classList[pos]->std[i]->lastName, classList[pos]->std[i]->firstName,
                classList[pos]->std[i]->birthDay, classList[pos]->std[i]->sex, classList[pos]->std[i]->address);
    }
}
void printListStudent(STUDENTLIST *classList)
{
    if (position == 0)
    {
        printf("\nChưa có danh sách sinh viên nào\n");
        return;
    }

    printf("Mời bạn nhập vào tên lớp cần in danh sách: ");
    char className[50];
    fgets(className, sizeof(className), stdin);
    removeEnter(className);

    int found = 0;
    for (int i = 0; i < position; i++)
    {
        if (strcmp(classList[i]->className, className) == 0)
        {
            found = 1;
            if (classList[i]->count == 0)
            {
                printf("\nDanh sách không có sinh viên\n");
                return;
            }
            FILE *f;
            char nameFile[100], temp[100] = "Lop_";
            strcat(temp, className);
            strcpy(nameFile, strcat(temp, ".txt"));
            f = fopen(nameFile, "w");
            if (f == NULL)
            {
                printf("Không thể tạo file\n");
                return;
            }

            fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", className);
            printToFile(classList, f, i);
            printf("\nĐã in danh sách sinh viên\n");
            printf("Bạn mở file %s để xem danh sách sinh viên của lớp %s\n", nameFile, className);
            fclose(f);
            break;
        }
    }
    if (!found)
    {
        printf("\nKhông tìm thấy lớp %s\n", className);
    }
}
int isSorted(STUDENTLIST class)
{
    for (int i = 1; i < class->count; i++)
    {
        if (strcmp(class->std[i]->firstName, class->std[i - 1]->firstName) < 0)
        {
            return 0;
        }
        if (strcmp(class->std[i]->firstName, class->std[i - 1]->firstName) == 0 && strcmp(class->std[i]->lastName, class->std[i - 1]->lastName) < 0)
        {
            return 0;
        }
    }
    return 1;
}
void swapStudent(STUDENT *std1, STUDENT *std2)
{
    STUDENT tmp = *std1;
    *std1 = *std2;
    *std2 = tmp;
}
void sortStudent(STUDENTLIST *classList)
{
    if (position == 0)
    {
        printf("\nChưa có danh sách sinh viên nào\n");
        return;
    }

    printf("\nMời bạn nhập tên lớp cần sắp xếp: ");
    char className[50];
    int sorted = 0;
    int found = 0;
    fgets(className, sizeof(className), stdin);
    removeEnter(className);
    for (int i = 0; i < position; i++)
    {
        if (strcmp(className, classList[i]->className) == 0)
        {
            found = 1;
            if (isSorted(classList[i]))
            {
                printf("\nLớp %s đã được sắp xếp\n", className);
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
            break;
        }
        else
            printf("\nKhông tìm thấy lớp  %s\n", className);
        printf("\nKhông tìm thấy lớp  %s.\n", className);
    }
    if (!found)
    {
        printf("Không tìm thấy lớp %s \n", className);
        return;
    }

    if (sorted == 1)
        printf("\n----Sắp xếp thành công----\n");
}
void generateID(STUDENTLIST *classList)
{
    printf("Mời bạn nhập vào tên lớp cần cấp mã sinh viên: ");
    char className[100];
    fgets(className, sizeof(className), stdin);
    removeEnter(className);
    for (int i = 0; i < position; i++)
    {
        if (strcmp(className, classList[i]->className) == 0)
        {
            if (isSorted(classList[i]) == 0)
            {
                printf("Cần sắp xếp danh sách lớp %s để cấp mã sinh viên\n", className);
                return;
            }
            printf("Mời bạn nhập mã khoa: ");
            char facultyCode[10];
            scanf("%s", &facultyCode);
        }
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
int login()
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
        fgets(password, MAX_LEN_PASSWORLD, stdin);
        removeEnter(password);
        if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0)
        {
            printf("\nĐăng nhập thành công!");
            Sleep(1000);
            system("cls");
            for (int i = 0; i < 4; i++)
            {
                printf("Loading.");
                Sleep(150);
                system("cls");
                printf("Loading..");
                Sleep(150);
                system("cls");
                printf("Loading...");
                Sleep(150);
                system("cls");
            }
            return 1;
        }
        else
        {
            if (checkLogin == 2)
            {
                break;
            }
            printf("\nSai Username hoặc Password.\nHãy thử lại!\n\n");
            checkLogin++;
        }
    }
    printf("\nSai quá nhiều lần. Thoát chương trình\n");
    return 0;
}
#endif
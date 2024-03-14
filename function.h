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
//
struct Student
{
    unsigned long ID;
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
    STUDENT std;
};
typedef struct StudentList *STUDENTLIST;
struct Class
{
    int maxClass;
    int count;
    char className[100];
    STUDENTLIST classList;
};
typedef struct Class *CLASSLIST;
STUDENTLIST createClass(int size)
{
    STUDENTLIST L = malloc(sizeof(struct StudentList));
    L->count = 0;
    L->maxSize = size;
    L->std = malloc(size * sizeof(struct Student));
    return L;
}
CLASSLIST createListClass(int size)
{
    CLASSLIST C = malloc(sizeof(struct Class));
    C->count = 0;
    C->maxClass = size;
    C->classList = malloc(size * sizeof(STUDENTLIST));
    return C;
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
void insertClass(CLASSLIST classList, STUDENTLIST Class)
{
    if (classList->count == classList->maxClass)
        exit(1);
    classList->classList[classList->count] = *Class;
    classList->count++;
}
void insertStudent(STUDENTLIST Class, STUDENT std)
{
    int current;
    if (Class->count == Class->maxSize)
        exit(1);
    Class->std[Class->count] = *std;
    Class->count++;
}
void addStudent(CLASSLIST classList, STUDENTLIST class, STUDENT x)
{
    if (class->count < class->maxSize)
    {
        int numStd;
        printf("Mời bạn nhập vào số sinh viên cần thêm: ");
        scanf("%d", &numStd);
        getchar();
        for (int i = 0; i < numStd; i++)
        {

            printf("Nhập họ và tên đệm sinh viên thứ %d: ", i + 1);
            fgets(x->lastName, sizeof(x->lastName), stdin);
            removeEnter(x->lastName);
            printf("Nhập tên sinh viên thứ %d: ", i + 1);
            fgets(x->firstName, sizeof(x->firstName), stdin);
            removeEnter(x->firstName);
            printf("Nhập vào ngày sinh: ");
            fgets(x->birthDay, sizeof(x->birthDay), stdin);
            removeEnter(x->birthDay);
            printf("Nhập vào giới tính: ");
            fgets(x->sex, sizeof(x->sex), stdin);
            removeEnter(x->sex);
            printf("Nhập vào địa chỉ: ");
            fgets(x->address, sizeof(x->address), stdin);
            removeEnter(x->address);
            // insertClass(classList, class);
            insertStudent(class, x);
            printf("\nĐã thêm sinh viên thành công\n");
        }
    }
    else
        printf("Vượt quá giới hạn sinh viên\n");
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
                // printf("Loading...%d%%", i + 1);
                // Sleep(5);
                // system("cls");
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
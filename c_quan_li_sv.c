// CHƯƠNG TRÌNH QUẢN LÍ SINH VIÊN
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
struct Std
{
    unsigned long ID;
    char firstName[100]; // Tên
    char lastName[100];  // Họ
    char email[100];
    char birthDay[100];
    char sex[5];
    char address[1000];
};
typedef struct Std *Student;
struct StudentList
{
    int maxSize;
    int count;
    Student std;
};
typedef struct StudentList *StudentList;
struct Class
{
    int maxClass;
    int classCount;
    char className[100];
    StudentList listClass;
};
typedef struct Class *ListClass;
StudentList createClass(int size)
{
    StudentList L = malloc(sizeof(struct StudentList));
    L->count = 0;
    L->maxSize = size;
    L->std = malloc(size * sizeof(struct Std));
    return L;
}
ListClass createListClass(int size)
{
    ListClass C = malloc(sizeof(struct Class));
    C->classCount = 0;
    C->maxClass = size;
    C->listClass = malloc(size * sizeof(StudentList));
    return C;
}
//----------------------------------------------------------------------------------------------
void removeEnter(char s[]);
char *toLower(char s[]);
char *lTrim(char s[]);
char *rTrim(char s[]);
char *trim(char s[]);
char *toName(char s[]);
// void reverseStr(char s[]);
// char *getLastWord(char *s);
//----------------------------------------------------------------------------------------------
void menu();
int login();
int main()
{
    if (login() == 0)
    {
        return 0;
    }
    int choice, numberStudent = 0;
    ListClass listClass = createListClass(MAX_CLASS);
    StudentList Class = createClass(MAX_SIZE);
    Student std = malloc(sizeof(struct Std));
    printf("------------CHƯƠNG TRÌNH QUẢN LÍ SINH VIÊN------------\n\n");
    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // addStudent(Class, std);
            break;
        case 2:
            // sortStudent(Class);
            break;
        case 3:
            // removeStudent(Class, std);
            break;
        case 4:
            // searchStudentByName(Class, std);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            // printListStudent(Class);
            break;
        }
    } while (choice != 8 && choice < 8);
    free(std);
    return 0;
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
        i++;
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
// void reverseStr(char s[])
// {
//     for (int i = 0; i < strlen(s) / 2; i++)
//     {
//         char tmp = s[i];
//         s[i] = s[strlen(s) - i - 1];
//         s[strlen(s) - i - 1] = tmp;
//     }
// }
// char *getLastWord(char *s)
// {
//     char *tmp = (char *)malloc(strlen(s) + 1); // Cấp phát bộ nhớ cho tmp
//     int j = 0;
//     for (int i = strlen(s) - 1; i >= 0; i--)
//     {
//         if (s[i] == ' ')
//             break;
//         tmp[j++] = s[i];
//     }
//     tmp[j] = '\0';
//     reverseStr(tmp);
//     return tmp;
// }
void menu()
{
    printf("\n* * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*   1. Thêm sinh viên                       *\n");
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
            Sleep(2000);
            system("cls");
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
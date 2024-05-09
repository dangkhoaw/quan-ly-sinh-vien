#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

/*
                         _oo0oo_
                        o8888888o
                        88" . "88
                        (| -_- |)
                        0\  =  /0
                      ___/`---'\___
                    .' \\|     |// '.
                  // \\|||  :  |||// \\
                 // _||||| -:- |||||- \\
                 |   | \\\  -  /// |   |
                 | \_|  ''\---/''  |_/ |
                 \  .-\__  '-'  ___/-. /
               ___'. .'  /--.--\  `. .'___
            ."" '<  `.___\_<|>_/___.' >' "".
           | | :  `- \`.;`\ _ /`;.`/ - ` : | |
           \  \ `_.   \_ __\ /__ _/   .-` /  /
       =====`-.____`.___ \_____/___.-`___.-'=====
                         `=---='

       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              Phật phù hộ, không bao giờ BUG
       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#define MAX_USERNAME_LENGTH 30
#define MIN_USERNAME_LENGTH 5
#define MAX_PASSWORD_LENGTH 30
#define MIN_PASSWORD_LENGTH 8
#define MAX_SIZE 100
#define MAX_CLASS 11
#define and &&
#define or ||

char facultyCode[4];
char academicYear[3];
char classList[10][15];

struct Student
{
    char ID[10];
    char fullName[35];
    char firstName[10]; // Tên
    char lastName[25];  // Họ
    char email[25];
    char birthDay[15];
    char gender[5];
    char address[30];
};
typedef struct Student *STUDENT;

struct StudentList
{
    int count;
    bool isSorted;
    bool hasID;
    STUDENT *std;
};
typedef struct StudentList *STUDENTLIST;

//------------------------------------------------------------------------------------------------------------------------

void removeEnter(char string[]) // Do hàm fgets lấy dấu enter nên phải xóa dấu enter ra
{
    size_t len = strlen(string);
    if (string[len - 1] == '\n')
    {
        string[len - 1] = '\0';
    }
}

bool isNumber(char c) // Kiểm tra kí tự số
{
    return c >= '0' and c <= '9';
}

bool isLower(char c) // Kiểm tra kí tự thường
{
    return c >= 'a' and c <= 'z';
}

bool isUpper(char c) // Kiểm tra kí tự hoa
{
    return c >= 'A' and c <= 'Z';
}

char *toLower(char string[]) // Chuyển thành chuỗi in thường
{
    for (int i = 0; i < strlen(string); i++)
        if (string[i] >= 65 and string[i] <= 90)
            string[i] += 32;
    return string;
}

char *toUpper(char string[]) // Chuyển thành chuỗi in hoa
{
    for (int i = 0; i < strlen(string); i++)
        if (string[i] >= 97 and string[i] <= 122)
            string[i] -= 32;
    return string;
}

char *lTrim(char string[]) // Cắt khoảng trống bên trái
{
    int i = 0;
    while (string[i] == ' ')
    {
        i++;
    }
    if (i > 0)
    {
        strcpy(&string[0], &string[i]);
    }
    return string;
}

char *rTrim(char string[]) // Cắt khoảng trống bên phải
{
    int i = strlen(string) - 1;
    while (string[i] == ' ')
    {
        i--;
    }
    string[i + 1] = '\0';
    return string;
}

char *trim(char string[]) // Cắt khoảng trống dư thừa ở giữa và hai đầu
{
    rTrim(lTrim(string));
    char *doubleSpace = strstr(string, "  ");
    while (doubleSpace != NULL)
    {
        strcpy(doubleSpace, doubleSpace + 1); // Xóa 1 dấu cách
        doubleSpace = strstr(string, "  ");
    }
    return string;
}

char *toName(char string[]) // Chuyển chuỗi thành tên
{
    trim(string);
    toLower(string);
    for (int i = 0; i < strlen(string); i++)
        if (i == 0 or (i > 0 and string[i - 1] == ' '))
            string[i] = string[i] - 32;
    return string;
}

//------------------------------------------------------------------------------------------------------------------------

STUDENTLIST createClass() // Tạo danh sách sinh viên
{
    STUDENTLIST Class = malloc(sizeof(struct StudentList));
    Class->count = 0;
    Class->std = malloc(MAX_SIZE * sizeof(struct Student));
    return Class;
}

bool checkFacultyCode() // Kiểm tra mã khoa
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

void printListClassName() // In tên các lớp
{
    int numClass = 0;
    char classList[10][15];
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
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
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
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
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
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "104") == 0)
    {
        sprintf(classList[0], "%sN1", academicYear);
        sprintf(classList[1], "%sN2", academicYear);

        numClass = 2;
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
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
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
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
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
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
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "109") == 0)
    {
        sprintf(classList[0], "%sBIM_AI", academicYear);
        sprintf(classList[1], "%sCSHT", academicYear);
        sprintf(classList[2], "%sVLXD", academicYear);
        sprintf(classList[3], "%sX3", academicYear);

        numClass = 4;
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "110") == 0)
    {
        sprintf(classList[0], "%sX1A", academicYear);
        sprintf(classList[1], "%sX1B", academicYear);
        sprintf(classList[2], "%sX1C", academicYear);
        sprintf(classList[3], "%sX1D", academicYear);

        numClass = 4;
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "111") == 0)
    {
        sprintf(classList[0], "%sDTTM", academicYear);
        sprintf(classList[1], "%sTHXD", academicYear);
        sprintf(classList[2], "%sX2", academicYear);

        numClass = 3;
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "117") == 0)
    {
        sprintf(classList[0], "%sMT", academicYear);
        sprintf(classList[1], "%sQLMT", academicYear);

        numClass = 2;
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
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
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "121") == 0)
    {
        sprintf(classList[0], "%sKT1", academicYear);
        sprintf(classList[1], "%sKT2", academicYear);

        numClass = 2;
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
    else if (strcmp(facultyCode, "123") == 0)
    {
        sprintf(classList[0], "%sPFIEV1", academicYear);
        sprintf(classList[1], "%sPFIEV2", academicYear);
        sprintf(classList[2], "%sPFIEV3", academicYear);
        sprintf(classList[3], "%sES", academicYear);
        sprintf(classList[4], "%sECE", academicYear);

        numClass = 5;
        printf("\n");
        for (int i = 0; i < numClass; i++)
        {
            printf("📚 %s\n", classList[i]);
        }
    }
}

void printFacultyName() // In tên khoa
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

void inputCode() // Nhập mã khóa và mã khoa
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

bool checkClassName(char className[]) // Kiểm tra tên lớp
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

void insertStudent(STUDENTLIST Class, STUDENT std) // Thêm sinh viên vào danh sách
{
    if (Class->count >= MAX_SIZE)
    {
        printf("\n🔔 Lớp này đã đủ sinh viên\n");
        return;
    }
    Class->std[Class->count++] = std;
}

void printClassToFile(STUDENTLIST class, FILE *f) // In danh sách sinh viên ra file
{
    if (strcmp(class->std[0]->ID, "") == 0)
    {
        fprintf(f, "%-11s %-25s %-17s %-16s %s\n", "STT", "Họ và tên", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < class->count; i++)
        {
            fprintf(f, " %-5d %-29s %-11s %-15s %s\n", i + 1, class->std[i]->fullName, class->std[i]->gender, class->std[i]->birthDay, class->std[i]->address);
        }
    }
    else if (strcmp(class->std[0]->email, "") == 0)
    {
        fprintf(f, "%-5s %-23s %-24s %-17s %-16s %s\n", "STT", "Mã sinh viên", "Họ và tên", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < class->count; i++)
        {
            fprintf(f, " %-5d %-15s %-28s %-11s %-15s %s\n", i + 1, class->std[i]->ID, class->std[i]->fullName, class->std[i]->gender, class->std[i]->birthDay, class->std[i]->address);
        }
    }
    else
    {
        fprintf(f, "%-5s %-23s %-33s %-21s %-17s %-16s %s\n", "STT", "Mã sinh viên", "Họ và tên", "Email", "Giới tính", "Ngày sinh", "Địa chỉ");
        for (int i = 0; i < class->count; i++)
        {
            fprintf(f, " %-5d %-15s %-26s %-31s %-12s %-15s %s\n", i + 1, class->std[i]->ID, class->std[i]->fullName, class->std[i]->email, class->std[i]->gender, class->std[i]->birthDay, class->std[i]->address);
        }
    }
}

void printNewStudentToFile(FILE *f, STUDENT newStudent) // Thêm sinh viên mới vào file
{
    fprintf(f, "%s:%s:%s:%s:%s:%s:%s\n", newStudent->ID, newStudent->lastName, newStudent->firstName, newStudent->email, newStudent->gender, newStudent->birthDay, newStudent->address);
}

void getStudentInfo(STUDENT student) // Nhập thông tin sinh viên
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
    fgets(student->gender, sizeof(student->gender), stdin);
    removeEnter(student->gender);
    toName(student->gender);

    printf("\n➡️  Nhập địa chỉ: ");
    fgets(student->address, sizeof(student->address), stdin);
    removeEnter(student->address);

    strcpy(student->ID, "");

    strcpy(student->email, "");

    sprintf(student->fullName, "%s %s", student->lastName, student->firstName);
}

bool isSorted(STUDENTLIST class) // Kiểm tra danh sách đã được sắp xếp chưa
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

void readStudentInfoFromFile(FILE *f, STUDENTLIST class) // Đọc thông tin sinh viên từ file
{
    while (!feof(f)) // Đọc đến cuối file
    {
        STUDENT newStudent = malloc(sizeof(struct Student));
        char get;
        int index = 0;
        // Đọc từng thông tin của sinh viên cách nhau bởi dấu ':'
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
            newStudent->gender[index++] = get;
        }
        newStudent->gender[index] = '\0';
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
        // Do dòng cuối file là 1 dòng trống nên nó sẽ đoc ra 1 sinh viên rỗng
        if (newStudent->ID[0] == '\0' and newStudent->lastName[0] == '\0' and newStudent->firstName[0] == '\0' and
            newStudent->email[0] == '\0' and newStudent->gender[0] == '\0' and newStudent->birthDay[0] == '\0' and newStudent->address[0] == '\0')
        {
            break;
        }
        else
        {
            sprintf(newStudent->fullName, "%s %s", newStudent->lastName, newStudent->firstName);
            insertStudent(class, newStudent); // Thêm sinh viên vào danh sách
        }
    }
    // Kiểm tra xem danh sách đã được sắp xếp chưa
    if (isSorted(class))
        class->isSorted = true;
    else
        class->isSorted = false;

    if (strcmp(class->std[0]->ID, "") != 0)
        class->hasID = true;
    else
        class->hasID = false;
}

bool confirmExit() // Xác nhận thoát
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

void addStudent() // Thêm sinh viên
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
        FILE *file = fopen("class.txt", "a");
        fprintf(file, "%s-%s.txt\n", facultyCode, className);
        fclose(file);

        STUDENTLIST class = createClass(MAX_SIZE);
        FILE *f = fopen(fileName, "w");

        while (true)
        {
            STUDENT newStudent = malloc(sizeof(struct Student));

            getStudentInfo(newStudent);

            printNewStudentToFile(f, newStudent);
            printf("\n🎉 Đã thêm sinh viên thành công\n");

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

            getStudentInfo(newStudent);

            printNewStudentToFile(fileCheck, newStudent);
            printf("\n🎉 Đã thêm sinh viên thành công\n");
            if (confirmExit())
            {
                fclose(fileCheck);
                return;
            }
        }
    }
}

void swapStudent(STUDENT *student1, STUDENT *student2) // Đổi chỗ 2 sinh viên
{
    STUDENT tempStudent = *student1;
    *student1 = *student2;
    *student2 = tempStudent;
}

void quickSort(STUDENTLIST class, int start, int end)
{
    if (start < end)
    {
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
            if (strcmp(class->std[j]->firstName, class->std[end]->firstName) < 0 or
                (strcmp(class->std[j]->firstName, class->std[end]->firstName) == 0 and strcmp(class->std[j]->lastName, class->std[end]->lastName) < 0))
            {
                swapStudent(&class->std[++i], &class->std[j]);
            }
        }
        swapStudent(&class->std[++i], &class->std[end]);
        quickSort(class, start, i - 1);
        quickSort(class, i + 1, end);
    }
}

void sortStudent() // Sắp xếp sinh viên
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
        quickSort(class, 0, class->count - 1);
        FILE *f = fopen(fileName, "w");
        for (int i = 0; i < class->count; i++)
        {
            printNewStudentToFile(f, class->std[i]);
        }
        printf("\n🎉 Đã sắp xếp lớp %s\n", className);
        fclose(f);
    }
}

void printListStudent() // In danh sách sinh viên
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
        // In danh sách sinh viên ra file
        fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", className);
        printClassToFile(class, f);
        printf("\n🎉 Đã in danh sách sinh viên của lớp %s\n", className);
        fclose(f);
    }
}

void generateID() // Cấp mã sinh viên
{
    int numStudentHasID;
    char fileID[20];
    sprintf(fileID, ".id_%s_%s.txt", facultyCode, academicYear);
    FILE *f = fopen(fileID, "r");
    if (f == NULL)
    {
        f = fopen(fileID, "w");
        fprintf(f, "0");
        fclose(f);
        FILE *f = fopen(fileID, "r");
    }
    fscanf(f, "%d", &numStudentHasID);
    fclose(f);

    char className[15];
    do
    {
        printListClassName();
        printf("\n➡️  Mời bạn nhập vào tên lớp: ");
        fgets(className, sizeof(className), stdin);
        removeEnter(className);
        toUpper(className);
    } while (!checkClassName(className));

    char fileName[30];
    sprintf(fileName, "%s-%s.txt", facultyCode, className);
    FILE *fileCheck = fopen(fileName, "r");
    if (fileCheck == NULL)
    {
        printf("\n🔔 Lớp %s chưa tồn tại\n", className);
        fclose(fileCheck);
        return;
    }
    else
    {
        STUDENTLIST class = createClass(MAX_SIZE);
        readStudentInfoFromFile(fileCheck, class);
        fclose(fileCheck);
        if (class->hasID == false)
        {
            if (class->isSorted == false)
            {
                printf("\n🔔 Lớp %s chưa được sắp xếp\n", className);
                return;
            }
        }

        FILE *f = fopen(fileID, "w");
        for (int i = 0; i < class->count; i++)
        {
            if (strcmp(class->std[i]->ID, "") == 0)
            {
                sprintf(class->std[i]->ID, "%s%s%04d", facultyCode, academicYear, ++numStudentHasID);
            }
        }
        fprintf(f, "%d", numStudentHasID);
        fclose(f);
        FILE *file = fopen(fileName, "w");
        for (int i = 0; i < class->count; i++)
        {
            printNewStudentToFile(file, class->std[i]);
        }
        printf("\n🎉 Đã cấp mã sinh viên cho lớp %s\n", className);
        fclose(file);
    }
}

void generateEmail() // Cấp email
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

    char fileName[30];
    sprintf(fileName, "%s-%s.txt", facultyCode, className);
    FILE *fileCheck = fopen(fileName, "r");
    if (fileCheck == NULL)
    {
        printf("\n🔔 Lớp %s chưa tồn tại\n", className);
        fclose(fileCheck);
        return;
    }
    else
    {
        STUDENTLIST class = createClass(MAX_SIZE);
        readStudentInfoFromFile(fileCheck, class);
        fclose(fileCheck);
        if (class->hasID == false)
        {
            printf("\n🔔 Lớp %s chưa được cấp mã sinh viên\n", className);
            return;
        }

        FILE *f = fopen(fileName, "w");
        for (int i = 0; i < class->count; i++)
            if (strcmp(class->std[i]->email, "") == 0)
                sprintf(class->std[i]->email, "%s@sv.dut.udn.vn", class->std[i]->ID);

        for (int i = 0; i < class->count; i++)
            printNewStudentToFile(f, class->std[i]);

        printf("\n🎉 Đã cấp email cho lớp %s\n", className);
        fclose(f);
    }
}

void removeStudent() // Xóa sinh viên
{
    char ID[10];
    printf("\n➡️  Mời bạn nhập ID: ");
    fflush(stdin);
    fgets(ID, sizeof(ID), stdin);
    removeEnter(ID);

    int found = 0;
    FILE *f = fopen("class.txt", "r");
    char fileClass[50];
    while (fgets(fileClass, sizeof(fileClass), f))
    {
        removeEnter(fileClass);
        FILE *fileCheck = fopen(fileClass, "r");
        if (fileCheck != NULL)
        {
            STUDENTLIST class = createClass();
            readStudentInfoFromFile(fileCheck, class);
            fclose(fileCheck);
            for (int i = 0; i < class->count; i++)
            {
                if (strcmp(class->std[i]->ID, ID) == 0)
                {
                    found = 1;
                    printf("\n❓ Bạn có chắc chắn muốn xóa sinh viên %s %s? (Y/N): ", ID, class->std[i]->fullName);
                    char choice;
                    scanf(" %c", &choice);
                    if (choice == 'Y' or choice == 'y')
                    {
                        for (int k = i; k < class->count - 1; k++)
                        {
                            class->std[k] = class->std[k + 1];
                        }
                        class->count--;
                        printf("\n👏 Đã xóa sinh viên có ID %s\n", ID);
                        FILE *f = fopen(fileClass, "w");
                        for (int k = 0; k < class->count; k++)
                        {
                            printNewStudentToFile(f, class->std[k]);
                        }
                        fclose(f);
                        return;
                    }
                    else
                        return;
                }
            }
        }
        else
            fclose(fileCheck);
    }
    if (!found)
        printf("\n🔔 Không tìm thấy sinh viên có ID %s\n", ID);
}

void searchMenu() // Menu tìm kiếm
{
    printf("\n┌───────────────────────┐");
    printf("\n│ 1. Tìm kiếm theo tên  │");
    printf("\n│ 2. Tìm kiếm theo ID   │");
    printf("\n└───────────────────────┘");
    printf("\n\nMời bạn chọn: ");
}

void searchStudentByName() // Tìm kiếm sinh viên theo tên
{
    printf("\n➡️  Mời nhập tên sinh viên: ");
    char name[35];
    fflush(stdin);
    fgets(name, sizeof(name), stdin);
    removeEnter(name);
    toName(name);

    int found = 0;
    int count = 0;

    FILE *f = fopen("class.txt", "r");
    char fileClass[50];
    while (fgets(fileClass, sizeof(fileClass), f))
    {
        removeEnter(fileClass);
        FILE *fileCheck = fopen(fileClass, "r");
        if (fileCheck != NULL)
        {
            STUDENTLIST class = createClass();
            readStudentInfoFromFile(fileCheck, class);
            fclose(fileCheck);
            for (int i = 0; i < class->count; i++)
            {
                if (strstr(class->std[i]->fullName, name))
                {
                    found = 1;
                    printf("\n🔔 Tìm thấy: %s  %s  %s  %s  %s  %s\n", class->std[i]->ID, class->std[i]->fullName, class->std[i]->email, class->std[i]->gender, class->std[i]->birthDay, class->std[i]->address);
                }
            }
        }
        else
            fclose(fileCheck);
    }

    if (!found)
        printf("\n🔔 Không tìm thấy sinh viên tên %s\n", name);
    fclose(f);
}

void searchStudentByID() // Tìm kiếm sinh viên theo ID
{
    char ID[10];
    printf("\n➡️  Mời bạn nhập ID bạn muốn tìm: ");
    fflush(stdin);
    fgets(ID, sizeof(ID), stdin);
    removeEnter(ID);

    int found = 0;
    FILE *f = fopen("class.txt", "r");
    char fileClass[50];
    while (fgets(fileClass, sizeof(fileClass), f))
    {
        removeEnter(fileClass);
        FILE *fileCheck = fopen(fileClass, "r");
        if (fileCheck != NULL)
        {
            STUDENTLIST class = createClass();
            readStudentInfoFromFile(fileCheck, class);
            fclose(fileCheck);
            for (int i = 0; i < class->count; i++)
            {
                if (strcmp(class->std[i]->ID, ID) == 0)
                {
                    found = 1;
                    printf("\n🔔 Tìm thấy: %s  %s  %s  %s  %s  %s\n", class->std[i]->ID, class->std[i]->fullName, class->std[i]->email, class->std[i]->gender, class->std[i]->birthDay, class->std[i]->address);
                    return;
                }
            }
        }
        else
            fclose(fileCheck);
    }
    if (!found)
        printf("\n🔔 Không tìm thấy sinh viên có ID %s\n", ID);
    fclose(f);
}

void searchStudent() // Tìm kiếm sinh viên
{
    searchMenu();
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

void menu() // Menu chính
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

void loading() // Loading
{
    printf("\n\n");
    for (int i = 0; i <= 25; i++)
    {
        printf("\rLoading [");
        for (int j = 0; j < i; j++)
            printf("=");
        for (int j = i; j < 25; j++)
            printf(" ");
        printf("] %d%%", i * 4);
        Sleep(50);
    }
}

void encrypt(char string[]) // Mã hóa thành chuỗi hex
{
    char *hex = malloc(strlen(string) * 2 + 1);
    for (int i = 0; i < strlen(string); i++)
    {
        sprintf(&hex[i * 2], "%02x", string[i]);
    }
    strcpy(string, hex);
}

void decrypt(char string[]) // Giải mã
{
    // 1 byte = 2 hex
    /*"%2hhx" :     2:Đọc đúng 2 ký tự từ chuỗi đầu vào
                    hh: Chỉ định rằng giá trị đọc được sẽ được chuyển đổi thành một unsigned char
                    x: Chỉ định rằng giá trị đọc được là một số hệ thập lục phân.*/

    char *byte = malloc(strlen(string) / 2 + 1);
    for (int i = 0; i < strlen(string); i += 2)
    {
        sscanf(&string[i], "%2hhx", &byte[i / 2]);
    }
    strcpy(string, byte);
}

void inputPassword(char password[]) // Nhập password
{
    int i = 0;
    char get;
    while (i < MAX_PASSWORD_LENGTH)
    {
        get = getch();
        if (get == '\r' or get == '\n')
            break;
        else if (get == '\b')
        {
            if (i > 0)
            {
                printf("\b \b");
                i--;
            }
            else
                printf(" \b");
        }
        else
        {
            password[i++] = get;
            printf("•");
        }
    }
    password[i] = '\0';
}

void readUsernameAndPasswordFromFile(FILE *f, char username[], char password[]) // Đọc username và password từ file
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

bool isValidUsername(char username[]) // Kiểm tra username có hợp lệ hay không
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

        decrypt(user);
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

bool isValidPassword(char password[]) // Kiểm tra password có hợp lệ hay không
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

void registerNewAccount() // Đăng kí tài khoản
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
    encrypt(username);
    fprintf(f, "%s:", username);
    do
    {
        printf("Password: ");
        inputPassword(password);
    } while (!isValidPassword(password));
    encrypt(password);
    fprintf(f, "%s\n", password);
    fclose(f);
    printf("\n\n🎉 Đăng kí thành công!");
    Sleep(500);
    loading();
}

bool checkPassword(char password[], char userInputPass[]) // Kiểm tra password có đúng hay không
{
    decrypt(password);
    if (strcmp(password, userInputPass) == 0)
        return true;
    return false;
}

bool checkUsername(char userName[], char usernameInput[]) // Kiểm tra username có đúng hay không
{
    decrypt(userName);
    if (strcmp(userName, usernameInput) == 0)
        return true;
    return false;
}

bool checkUsernameAndPassword(char inputUsername[], char inputPassword[]) // Đọc từ file và kiểm tra username và password
{
    FILE *f = fopen("index.txt", "r");
    char username[25];
    char password[25];
    while (true)
    {
        if (feof(f))
            break;

        readUsernameAndPasswordFromFile(f, username, password);

        if (checkUsername(username, inputUsername) and checkPassword(password, inputPassword))
        {
            fclose(f);
            return true;
        }
    }
    fclose(f);
    return false;
}

bool login() // Đăng nhập
{
    system("cls");
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int checkLogin = 0;
    printf("\n\t=============== Login Page ===============\n\n");
    while (true)
    {
        printf("Username : ");
        fgets(username, sizeof(username), stdin);
        removeEnter(username);
        printf("Password : ");
        inputPassword(password);
        if (checkUsernameAndPassword(username, password))
        {
            printf("\n\n🎉 Chào mừng bạn đã trở lại!");
            Sleep(555);
            loading();
            system("cls");
            return true;
        }
        else
        {
            checkLogin++;
            if (checkLogin < 5)
                printf("\n\n⚠️  Sai Username hoặc Password. Hãy thử lại!\n\n");
        }
        if (checkLogin == 5)
            break;
    }
    printf("\n\n❌ Login failed!\n");
    return false;
}

void runProgram() // Chương trình chính
{
    inputCode();
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
        case 8:
            printf("\n👋  Hẹn gặp lại");
            break;
        default:
            printf("\n⚠️  Vui lòng chọn từ 1 đến 8\n");
            break;
        }
    } while (choice != 8);
}

#endif
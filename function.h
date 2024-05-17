#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>

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
#define and &&
#define or ||

char facultyCode[4];
char academicYear[3];

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

typedef struct
{
    char *facultyCode;
    char *className[15];
    int numClass;
} Faculty;

//------------------------------------------------------------------------------------------------------------------------

// Do hàm fgets lấy dấu enter nên phải xóa dấu enter ra
void removeEnter(char *string)
{
    size_t len = strlen(string);
    if (string[len - 1] == '\n')
    {
        string[len - 1] = '\0';
    }
}

// Chuyển thành chuỗi in thường
char *toLower(char *string)
{
    for (int i = 0; i < strlen(string); i++)
        if (string[i] >= 65 and string[i] <= 90)
            string[i] += 32;
    return string;
}

// Chuyển thành chuỗi in hoa
char *toUpper(char *string)
{
    for (int i = 0; i < strlen(string); i++)
        if (string[i] >= 97 and string[i] <= 122)
            string[i] -= 32;
    return string;
}

// Cắt khoảng trống bên trái
char *lTrim(char *string)
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

// Cắt khoảng trống bên phải
char *rTrim(char *string)
{
    int i = strlen(string) - 1;
    while (string[i] == ' ')
    {
        i--;
    }
    string[i + 1] = '\0';
    return string;
}

// Cắt khoảng trống dư thừa ở giữa và hai đầu
char *trim(char *string)
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

// Chuyển chuỗi thành tên
char *toName(char *string)
{
    trim(string);
    toLower(string);
    for (int i = 0; i < strlen(string); i++)
        if (i == 0 or (i > 0 and string[i - 1] == ' '))
            string[i] = string[i] - 32;
    return string;
}

//------------------------------------------------------------------------------------------------------------------------

// Tạo danh sách sinh viên
STUDENTLIST createClass()
{
    STUDENTLIST Class = malloc(sizeof(struct StudentList));
    Class->count = 0;
    Class->std = malloc(MAX_SIZE * sizeof(struct Student));
    return Class;
}

// Kiểm tra mã khoa
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

// In tên các lớp
void printListClassName()
{
    int numFaculty = 14;
    Faculty faculty[] = {
        {"101", {"C1A", "C1B", "C1C", "C1D", "CDT1", "CDT2", "CDT3", "CDT4", "CKHK"}, 9},
        {"102", {"T_DT1", "T_DT2", "T_DT3", "T_DT4", "T_KHDL1", "T_KHDL2", "T_NHAT1", "T_NHAT2"}, 8},
        {"103", {"C4A", "C4B", "C4C", "HTCN", "KTOTO1", "KTOTO2", "KTTT"}, 7},
        {"104", {"N1", "N2"}, 2},
        {"105", {"D1", "D2", "D3", "D4", "D5", "TDH1", "TDH2", "TDH3"}, 8},
        {"106", {"DT1", "DT2", "DT3", "DT4", "KTMT1", "KTMT2"}, 6},
        {"107", {"H2A", "H2B", "H2C", "H5", "KTHH1", "KTHH2", "SH1", "SH2", "SHYD"}, 9},
        {"109", {"BIM_AI", "CSHT", "VLXD", "X3"}, 4},
        {"110", {"X1A", "X1B", "X1C", "X1D"}, 4},
        {"111", {"DTTM", "THXD", "X2"}, 3},
        {"117", {"MT", "QLMT"}, 2},
        {"118", {"KX1", "KX2", "KX3", "QLCN1", "QLCN2", "QLCN3"}, 6},
        {"121", {"KT1", "KT2"}, 2},
        {"123", {"PFIEV1", "PFIEV2", "PFIEV3", "ES", "ECE"}, 5}};

    for (int i = 0; i < numFaculty; i++)
    {
        if (strcmp(facultyCode, faculty[i].facultyCode) == 0)
        {
            printf("\n");
            for (int j = 0; j < faculty[i].numClass; j++)
            {
                char className[15];
                sprintf(className, "%s%s", academicYear, faculty[i].className[j]);
                printf("📚 %s\n", className);
            }
            break;
        }
    }
}

// In tên khoa
void printFacultyName()
{
    printf("\n🏢 101: Khoa Cơ khí\n");
    printf("🏢 102: Khoa Công nghệ Thông tin\n");
    printf("🏢 103: Khoa Cơ khí Giao thông\n");
    printf("🏢 104: Khoa CN Nhiệt-Điện lạnh\n");
    printf("🏢 105: Khoa Điện\n");
    printf("🏢 106: Khoa Điện tử Viễn Thông\n");
    printf("🏢 107: Khoa Hóa\n");
    printf("🏢 109: Khoa Xây dựng Cầu-Đường\n");
    printf("🏢 110: Khoa Xây dựng Dân dụng - Công nghiệp\n");
    printf("🏢 111: Khoa Xây dựng công trình thủy\n");
    printf("🏢 117: Khoa Môi trường\n");
    printf("🏢 118: Khoa Quản lí dự án\n");
    printf("🏢 121: Khoa Kiến trúc\n");
    printf("🏢 123: Khoa Khoa học Công nghệ tiên tiến\n");
}

// Nhập mã khóa và mã khoa
void inputCode()
{
    printf("\n➡️  Mời bạn nhập vào mã khóa: ");
    scanf("%s", academicYear);

    printFacultyName();
    do
    {
        printf("\n➡️  Mời bạn nhập vào mã khoa: ");
        scanf("%s", facultyCode);
    } while (checkFacultyCode() == 0);

    system("cls");
}

// Kiểm tra tên lớp
bool checkClassName(char *className)
{
    int numFaculty = 14;
    Faculty faculty[] = {
        {"101", {"C1A", "C1B", "C1C", "C1D", "CDT1", "CDT2", "CDT3", "CDT4", "CKHK"}, 9},
        {"102", {"T_DT1", "T_DT2", "T_DT3", "T_DT4", "T_KHDL1", "T_KHDL2", "T_NHAT1", "T_NHAT2"}, 8},
        {"103", {"C4A", "C4B", "C4C", "HTCN", "KTOTO1", "KTOTO2", "KTTT"}, 7},
        {"104", {"N1", "N2"}, 2},
        {"105", {"D1", "D2", "D3", "D4", "D5", "TDH1", "TDH2", "TDH3"}, 8},
        {"106", {"DT1", "DT2", "DT3", "DT4", "KTMT1", "KTMT2"}, 6},
        {"107", {"H2A", "H2B", "H2C", "H5", "KTHH1", "KTHH2", "SH1", "SH2", "SHYD"}, 9},
        {"109", {"BIM_AI", "CSHT", "VLXD", "X3"}, 4},
        {"110", {"X1A", "X1B", "X1C", "X1D"}, 4},
        {"111", {"DTTM", "THXD", "X2"}, 3},
        {"117", {"MT", "QLMT"}, 2},
        {"118", {"KX1", "KX2", "KX3", "QLCN1", "QLCN2", "QLCN3"}, 6},
        {"121", {"KT1", "KT2"}, 2},
        {"123", {"PFIEV1", "PFIEV2", "PFIEV3", "ES", "ECE"}, 5}};

    for (int i = 0; i < numFaculty; i++)
    {
        if (strcmp(facultyCode, faculty[i].facultyCode) == 0)
        {
            for (int j = 0; j < faculty[i].numClass; j++)
            {
                char temp[15];
                sprintf(temp, "%s%s", academicYear, faculty[i].className[j]);
                if (strcmp(className, temp) == 0)
                {
                    return true;
                }
            }
        }
    }
    printf("\n ⚠️ Tên lớp không hợp lệ, mời nhập lại\n");
    return false;
}

// Thêm sinh viên vào danh sách
void insertStudent(STUDENTLIST Class, STUDENT std)
{
    if (Class->count >= MAX_SIZE)
    {
        printf("\n🔔 Lớp này đã đủ sinh viên\n");
        return;
    }
    Class->std[Class->count++] = std;
}

// In danh sách sinh viên ra file
void printClassToFile(STUDENTLIST class, FILE *f)
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
        fprintf(f, "+-----+-----------------+-----------------------------+-------------------------+--------------+--------------+---------------+\n");
        fprintf(f, "| %s |   %s  |          %s          |          %s          |   %s  |   %s  |    %s    |\n", "STT", "Mã sinh viên", "Họ và tên", "Email", "Giới tính", "Ngày sinh", "Địa chỉ");
        fprintf(f, "+-----+-----------------+-----------------------------+-------------------------+--------------+--------------+---------------+\n");
        for (int i = 0; i < class->count; i++)
        {
            fprintf(f, "| %-3d |    %-13s| %-28s| %-23s |     %-8s |  %-11s | %-13s |\n", i + 1, class->std[i]->ID, class->std[i]->fullName, class->std[i]->email, class->std[i]->gender, class->std[i]->birthDay, class->std[i]->address);
        }
        fprintf(f, "+-----+-----------------+-----------------------------+-------------------------+--------------+--------------+---------------+\n");
    }
}

// Thêm sinh viên mới vào file
void printNewStudentToFile(FILE *f, STUDENT newStudent)
{
    fprintf(f, "%s:%s:%s:%s:%s:%s:%s\n", newStudent->ID, newStudent->lastName, newStudent->firstName, newStudent->email, newStudent->gender, newStudent->birthDay, newStudent->address);
}

// Nhập thông tin sinh viên
void getStudentInfo(STUDENT student)
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
    toName(student->address);

    strcpy(student->ID, "");

    strcpy(student->email, "");

    sprintf(student->fullName, "%s %s", student->lastName, student->firstName);
}

// Kiểm tra danh sách đã được sắp xếp chưa
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

void sortClass()
{
    FILE *f = fopen("class.txt", "r");
    char class[50][20];
    int i = 0;
    while (fgets(class[i], sizeof(class[i]), f))
    {
        removeEnter(class[i]);
        i++;
    }
    fclose(f);
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (strcmp(class[j], class[k]) > 0)
            {
                char temp[20];
                strcpy(temp, class[j]);
                strcpy(class[j], class[k]);
                strcpy(class[k], temp);
            }
        }
    }
    f = fopen("class.txt", "w");
    for (int j = 0; j < i; j++)
    {
        fprintf(f, "%s\n", class[j]);
    }
    fclose(f);
}

// Đọc thông tin sinh viên từ file
void readStudentInfoFromFile(FILE *f, STUDENTLIST class)
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

// Xác nhận thoát
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

// Thêm sinh viên
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
        FILE *file = fopen("class.txt", "a");
        fprintf(file, "%s-%s.txt\n", facultyCode, className);
        fclose(file);
        sortClass();

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

// Đổi chỗ 2 sinh viên
void swapStudent(STUDENT *student1, STUDENT *student2)
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

// Sắp xếp sinh viên
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

// In danh sách sinh viên
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
        // In danh sách sinh viên ra file
        fprintf(f, "Danh sách sinh viên của lớp %s:\n\n", className);
        printClassToFile(class, f);
        printf("\n🎉 Đã in danh sách sinh viên của lớp %s\n", className);
        fclose(f);
    }
}

// Cấp mã sinh viên
void generateID()
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

// Cấp email
void generateEmail()
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

// Xóa sinh viên
void removeStudent()
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
                        printf("\n🎉 Đã xóa sinh viên có ID %s\n", ID);
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

// Menu tìm kiếm
void searchMenu()
{
    printf("\n┌─────────────────────────────────┐");
    printf("\n│ 1. Tìm kiếm theo tên            │");
    printf("\n│ 2. Tìm kiếm theo mã sinh viên   │");
    printf("\n└─────────────────────────────────┘");
    printf("\n\nMời bạn chọn: ");
}

// Tìm kiếm sinh viên theo tên
void searchStudentByName()
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

// Tìm kiếm sinh viên
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

// Tìm kiếm sinh viên
void searchStudent()
{
    searchMenu();
    char choice;
    scanf(" %c", &choice);
    switch (choice)
    {
    case '1':
        searchStudentByName();
        break;
    case '2':
        searchStudentByID();
        break;
    default:
        printf("\nChọn 1 hoặc 2\n");
        searchStudent();
        break;
    }
}

// Menu chính
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

//------------------------------------------------------------------------------------------------------------------------

// Loading
void loading()
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

// Mã hóa thành base64
void encrypt(char *string)
{
    int length = strlen(string);
    char *base64 = malloc(length * 2);
    char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int i = 0;
    int j = 0;
    while (i < length)
    {
        base64[j++] = base64_table[(string[i] & 0xFC) >> 2];                                                                                   // 0xFC = 11111100 = 252 lấy ra 6 bit đầu
        base64[j++] = base64_table[((string[i] & 0x03) << 4) | ((i + 1 < length ? string[i + 1] & 0xF0 : 0) >> 4)];                            // 0x03 = 00000011 = 3 lấy ra 2 bit cuối | 0xF0 = 11110000 = 240 lấy ra 4 bit đầu
        base64[j++] = i + 1 < length ? base64_table[((string[i + 1] & 0x0F) << 2) | ((i + 2 < length ? string[i + 2] & 0xC0 : 0) >> 6)] : '='; // 0x0F = 00001111 = 15 lấy ra 4 bit cuối | 0xC0 = 11000000 = 192 lấy ra 2 bit đầu
        base64[j++] = i + 2 < length ? base64_table[string[i + 2] & 0x3F] : '=';                                                               // 0x3F = 00111111 = 63 lấy ra 6 bit cuối
        i += 3;
    }
    base64[j] = '\0';
    strcpy(string, base64);
}

// Giải mã
void decrypt(char *string)
{
    int length = strlen(string);
    char *byte = malloc(length * 2);
    char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int i = 0;
    int j = 0;
    while (i < length)
    {
        byte[j++] = ((strchr(base64_table, string[i]) - base64_table) << 2) | ((i + 1 < length ? strchr(base64_table, string[i + 1]) - base64_table : 0) >> 4);
        if (string[i + 2] != '=')
            byte[j++] = ((strchr(base64_table, string[i + 1]) - base64_table) << 4) | ((i + 2 < length ? strchr(base64_table, string[i + 2]) - base64_table : 0) >> 2);
        if (string[i + 3] != '=')
            byte[j++] = ((strchr(base64_table, string[i + 2]) - base64_table) << 6) | (i + 3 < length ? strchr(base64_table, string[i + 3]) - base64_table : 0);
        i += 4;
    }
    byte[j] = '\0';
    strcpy(string, byte);
}

// Nhập password
void inputPassword(char *password)
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

// Kiểm tra password có đúng hay không
bool checkPassword(char *password, char *userInputPass)
{
    if (strcmp(password, userInputPass) == 0)
        return true;
    return false;
}

// Kiểm tra username có đúng hay không
bool checkUsername(char *userName, char *usernameInput)
{
    if (strcmp(userName, usernameInput) == 0)
        return true;
    return false;
}

// Đọc username và password từ file
bool readUsernameAndPasswordFromFile(FILE *f, char *username, char *password)
{
    char get;
    int index = 0;

    while ((get = fgetc(f)) != ':' and get != EOF)
    {
        username[index++] = get;
    }
    username[index] = '\0';

    if (strlen(username) == 0)
    {
        return false;
    }

    index = 0;
    while ((get = fgetc(f)) != '\n' and get != EOF)
    {
        password[index++] = get;
    }
    password[index] = '\0';

    return true;
}

// Kiểm tra username có hợp lệ hay không
bool isValidUsername(char *username)
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
    char user[MAX_USERNAME_LENGTH * 2], pass[MAX_PASSWORD_LENGTH * 2];
    while (true)
    {
        if (feof(f))
            break;

        readUsernameAndPasswordFromFile(f, user, pass);

        if (checkUsername(user, username))
        {
            printf("\n⚠️  Username đã tồn tại\n\n");
            return false;
        }
    }
    fclose(f);
    return true;
}

// Kiểm tra password có hợp lệ hay không
bool isValidPassword(char *password)
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
        else if (isupper(password[i]))
        {
            hasUppercase = true;
        }
        else if (islower(password[i]))
        {
            hasLowercase = true;
        }
        else if (isdigit(password[i]))
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

// Đăng kí tài khoản
void registerNewAccount()
{
    system("cls");
    char username[MAX_USERNAME_LENGTH * 2];
    char password[MAX_PASSWORD_LENGTH * 2];
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

// Đọc từ file và kiểm tra username và password
bool checkUsernameAndPassword(char *inputUsername, char *inputPassword)
{
    if (strlen(inputUsername) == 0 or strlen(inputPassword) == 0)
    {
        return false;
    }

    FILE *f = fopen("index.txt", "r");
    char username[MAX_PASSWORD_LENGTH * 2];
    char password[MAX_PASSWORD_LENGTH * 2];
    while (true)
    {
        if (feof(f))
            break;

        bool check = readUsernameAndPasswordFromFile(f, username, password);

        if (check)
        {
            decrypt(username);
            decrypt(password);
            if (checkUsername(username, inputUsername) and checkPassword(password, inputPassword))
            {
                fclose(f);
                return true;
            }
        }
    }
    fclose(f);
    return false;
}

// Đăng nhập
bool login()
{
    system("cls");
    char username[MAX_USERNAME_LENGTH * 2];
    char password[MAX_PASSWORD_LENGTH * 2];
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
            printf("\n\n🎉 Đăng nhập thành công");
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
            else
            {
                printf("\n\n❌  Đăng nhập thất bại. Hãy thử lại sau!\n\n");
                return false;
            }
        }
    }
}

// Chương trình chính
void runProgram()
{
    inputCode();
    int choice;
    printf("\n────────────CHƯƠNG TRÌNH QUẢN LÍ SINH VIÊN────────────\n\n");
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
            printf("\n👋  Hẹn gặp lại\n\n");
            system("pause");
            break;
        default:
            printf("\n⚠️  Vui lòng chọn từ 1 đến 8\n");
            break;
        }
    } while (choice != 8);
}

#endif
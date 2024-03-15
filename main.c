#include "function.h"
int main()
{
    // if (login() == 0)
    // {
    //     return 0;
    // }
    int choice, numberStudent = 0;
    STUDENTLIST *classList = malloc(MAX_CLASS * sizeof(struct StudentList));
    STUDENTLIST Class = createClass(MAX_SIZE);
    STUDENT std = malloc(sizeof(struct Student));
    printf("------------CHUONG TRINH QUAN LI SINH VIEN------------\n\n");
    do
    {
        menu();
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            addStudent(classList);
            break;
        case 2:
            sortStudent(classList);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            printListStudent(classList, Class);
            break;
        }
    } while (choice != 8);
    free(std);
    return 0;
}
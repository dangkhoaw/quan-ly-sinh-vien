#include "function.h"
int main()
{
    SetConsoleOutputCP(65001);
    // if (login() == 0)
    // {
    //     return 0;
    // }
    int choice;
    STUDENTLIST *classList = malloc(MAX_CLASS * sizeof(struct StudentList));
    // STUDENTLIST Class = createClass(MAX_SIZE);
    // STUDENT std = malloc(sizeof(struct Student));
    STUDENTLIST Class = createClass(MAX_SIZE);
    STUDENT std = malloc(sizeof(struct Student));
    printf("------------CHƯƠNG TRÌNH QUẢN LÍ SINH VIÊN------------\n\n");
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
            printListStudent(classList);
            break;
        }
    } while (choice != 8);
    // free(std);
    free(classList);
    return 0;
}
#include "function.h"
int main()
{
    SetConsoleOutputCP(65001);
    if (login() == 0)
    {
        return 0;
    }
    enterCode();
    int choice;
    STUDENTLIST *classList = malloc(MAX_CLASS * sizeof(struct StudentList));
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
    return 0;
}
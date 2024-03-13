#include "library.h"
int main()
{
    if (login() == 0)
    {
        return 0;
    }
    int choice, numberStudent = 0;
    CLASSLIST classList = createListClass(MAX_CLASS);
    STUDENTLIST Class = createClass(MAX_SIZE);
    STUDENT std = malloc(sizeof(struct Student));
    printf("------------CHUONG TRINH QUAN LI SINH VIEN------------\n\n");
    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addStudent(classList, Class, std);
            break;
        case 2:
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
            break;
        }
    } while (choice != 8 && choice < 8);
    free(std);
    return 0;
}

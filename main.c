#include "function.h"

int main()
{
    SetConsoleOutputCP(65001);
    system("cls");

    printf("❓ Do you have an account? (Y/N): ");
    char choice;
    scanf(" %c", &choice);
    fflush(stdin);

    if (choice == 'Y' || choice == 'y')
    {
        if (login())
        {
            runProgram();
        }
    }
    else if (choice == 'N' || choice == 'n')
    {
        registerNewAccount();
        if (login())
        {
            runProgram();
        }
    }
    return 0;
}
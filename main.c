#include "function.h"

int main()
{
    SetConsoleOutputCP(65001);
    system("cls");

    printf("❓ Bạn đã có tài khoản chưa? (Y/N):");
    char choice;
    scanf(" %c", &choice);
    fflush(stdin);

    if (choice == 'Y' || choice == 'y')
    {
        if (login())
            runProgram();
    }
    else if (choice == 'N' || choice == 'n')
    {
        registerNewAccount();
        if (login())
            runProgram();
    }
    else
    {
        printf("❌ Lựa chọn không hợp lệ! Vui lòng chọn lại\n");
        // main();
    }
    return 0;
}
#include "header.h"

int main()
{
    printf("Choose problem(0 to exit):\n");
    printf("1. problem 1 variant 4\n");
    printf("2. problem 2 variant 4\n");
    char c = '*';

    while (c <= '0' || c >= '3')
    {
        c = getch();
        if (c == '1')
            problem1();
        else if (c == '2')
            problem2();
        else if (c == '0')
        {
            printf("Successfully exit\n");
            break;
        }
        else
            printf("Error, try again\n");
    }
    printf("\nPress any key to exit\n");
    getch();
    return 0;
}
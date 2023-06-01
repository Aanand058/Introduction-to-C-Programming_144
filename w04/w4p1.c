/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  : Aanand Aman
Student ID#: 166125211
Email      : aaman8@myseneca.ca
Section    : ZDD
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int i;
    char a;
    int value;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");
    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &a, &value);
        if ((a == 'D' || a == 'W' || a == 'F'))
        {
            if (value < 3 || value > 20)
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            else if (a == 'W')
            {
                printf("WHILE   : ");
                for (i = 1; i <= value; i++)
                {
                    printf("%c", a);
                }
                printf("\n");
            }
            else if (a == 'D')
            {
                printf("DO-WHILE: ");
                for (i = 1; i <= value; i++)
                {
                    printf("%c", a);
                }
                printf("\n");
            }
            else if (a == 'F')
            {
                printf("FOR     : ");
                for (i = 1; i <= value; i++)
                {
                    printf("%c", a);
                }
                printf("\n");
            }
        }
        else if (a == 'Q')
        {
            if (value != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }
        }
        else
        {
            printf("ERROR: Invalid entered value(s)!\n");
        }
        printf("\n");

    } while (a != 'Q' || value != 0);
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}
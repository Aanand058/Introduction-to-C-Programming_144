

#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2012
#define MAX_YEAR 2022

#include <stdio.h>

int main(void)
{

    const int JAN = 1;
    const int DEC = 12;
    int year, month;
    char mon1, mon2, mon3;

    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year >= MIN_YEAR && year <= MAX_YEAR)
        {
            if (month == 0)
            {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
            }

            else if (month < JAN || month > DEC)
            {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
            }
            else if (month >= JAN && month <= DEC)
            {
                printf("\n");
                printf("*** Log date set! ***\n");
            }
        }

        else if (year < MIN_YEAR || year > MAX_YEAR)
        {

            if (month < JAN || month > DEC)
            {
                printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
            }
            else
            {
                printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            }
        }
        else
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }

    } while (year < MIN_YEAR || year > MAX_YEAR || month < JAN || month > DEC);
    printf("\n");

    if (month == 1)
    {
        mon1 = 'J';
        mon2 = 'A';
        mon3 = 'N';
    }
    if (month == 2)
    {
        mon1 = 'F';
        mon2 = 'E';
        mon3 = 'B';
    }
    if (month == 3)
    {
        mon1 = 'M';
        mon2 = 'A';
        mon3 = 'R';
    }
    if (month == 4)
    {
        mon1 = 'A';
        mon2 = 'P';
        mon3 = 'R';
    }
    if (month == 5)
    {
        mon1 = 'M';
        mon2 = 'A';
        mon3 = 'Y';
    }
    if (month == 6)
    {
        mon1 = 'J';
        mon2 = 'U';
        mon3 = 'N';
    }
    if (month == 7)
    {
        mon1 = 'J';
        mon2 = 'U';
        mon3 = 'L';
    }
    if (month == 8)
    {
        mon1 = 'A';
        mon2 = 'U';
        mon3 = 'G';
    }
    if (month == 9)
    {
        mon1 = 'S';
        mon2 = 'E';
        mon3 = 'P';
    }
    if (month == 10)
    {
        mon1 = 'O';
        mon2 = 'C';
        mon3 = 'T';
    }
    if (month == 11)
    {
        mon1 = 'N';
        mon2 = 'O';
        mon3 = 'V';
    }
    if (month == 12)
    {
        mon1 = 'D';
        mon2 = 'E';
        mon3 = 'C';
    }

    printf("Log starting date: %d-%c%c%c-01\n", year, mon1, mon2, mon3);
    printf("\n");

    return 0;
}
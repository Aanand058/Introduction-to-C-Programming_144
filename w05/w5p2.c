/*
*****************************************************************************
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

#include <stdio.h>

int main(void)
{
    int i;
    double mornRat1, eveRat1;
    double mornRat2, eveRat2;
    double mornRat3, eveRat3;
    const int JAN = 1;
    const int DEC = 12;
    int year, month;
    char mon1, mon2, mon3;
    double totalMornRat;
    double totalEveRat;
    double OverallTotalRating;
    double aveMornRat;
    double aveEveRat;
    double OverallAveRating;

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
        else if (year < MIN_YEAR ||  year > MAX_YEAR)
        {
           
            if ( month < JAN ||month > DEC)
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
    for (i = 1; i <= LOG_DAYS; i++)
    {
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

        printf("%d-%c%c%c-0%d\n", year, mon1, mon2, mon3, i);
        if (i == 1)
        {
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mornRat1);
                if (mornRat1 < 0.0 || mornRat1 > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }

            } while (mornRat1 < 0.0 || mornRat1 > 5.0);

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveRat1);
                if (eveRat1 < 0.0 || eveRat1 > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveRat1 < 0.0 || eveRat1 > 5.0);
            printf("\n");
        }
        else if (i == 2)
        {
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mornRat2);
                if (mornRat2 < 0.0 || mornRat2 > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }

            } while (mornRat2 < 0.0 || mornRat2 > 5.0);

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveRat2);
                if (eveRat2 < 0.0 || eveRat2 > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveRat2 < 0.0 || eveRat2 > 5.0);
            printf("\n");
        }
        else if (i == 3)
        {
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mornRat3);
                if (mornRat3 < 0.0 || mornRat3 > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }

            } while (mornRat3 < 0.0 || mornRat3 > 5.0);

            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveRat3);
                if (eveRat3 < 0.0 || eveRat3 > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveRat3 < 0.0 || eveRat3 > 5.0);
            printf("\n");
        }
    }
    printf("Summary\n");
    printf("=======\n");
    totalMornRat = mornRat1 + mornRat2 + mornRat3;
    totalEveRat = eveRat1 + eveRat2 + eveRat3;
    OverallTotalRating = totalEveRat + totalMornRat;
    printf("Morning total rating: %.3lf\n", totalMornRat);
    printf("Evening total rating:  %.3lf\n", totalEveRat);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", OverallTotalRating);
    printf("\n");
    aveMornRat = (totalMornRat) / LOG_DAYS;
    aveEveRat = (totalEveRat) / LOG_DAYS;
    OverallAveRating = (aveEveRat + aveMornRat) / 2;
    printf("Average morning rating:  %.1lf\n", aveMornRat);
    printf("Average evening rating:  %.1lf\n", aveEveRat);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", OverallAveRating);

    return 0;
}
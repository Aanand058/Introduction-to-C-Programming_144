/*
*****************************************************************************
                          Workshop - #6 (P1)
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

#define maxWishList 10
#define minItemCost 100 // the items cost should must be minimum $100

int main(void)
{
    const double minNetIncome = 500.00;
    const double maxNetIncome = 400000.00;
    double monIncome; // monthly net income
    int flag1 = 0, flag2 = 0, flag3 = 0;
    int i;
    int noOfWishList; // number of wish list items they want to use in the forecast
    double itemCost[maxWishList];
    int valueOfItem[maxWishList];
    char financeOption[maxWishList];
    double totalcost = 0; // A character value representing if an item has financing options (don’t need to pay entire value up-front)

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");
    for (i = 0; flag1 == 0; i++)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monIncome);
        if (monIncome < minNetIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
            printf("\n");
        }
        else if (monIncome > maxNetIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
            printf("\n");
        }
        else if (monIncome >= minNetIncome || monIncome <= maxNetIncome)
        {
            flag1 = 1;
        }
    }
    printf("\n");
    for (i = 0; flag2 == 0; i++)
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &noOfWishList);
        if (noOfWishList > maxWishList || noOfWishList == 0 || noOfWishList < 0)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
            printf("\n");
        }
        else
        {
            flag2 = 1;
        }
    }
    printf("\n");
    for (i = 0; i < noOfWishList; i++)
    {
        printf("Item-%d Details:\n", i + 1);
        do
        {

            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);
            if (itemCost[i] < minItemCost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (itemCost[i] < minItemCost);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &valueOfItem[i]);
            if (valueOfItem[i] > 3 || valueOfItem[i] == 0 || valueOfItem[i] < 0)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }

        } while (valueOfItem[i] > 3 || valueOfItem[i] == 0);

        do
        {
            flag3 = 0;
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%s", &financeOption[i]);
            if (financeOption[i] == 'y' || financeOption[i] == 'n')
            {
                flag3 = 1;
            }
            else
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }

        } while ((financeOption[i] != 'y' || financeOption[i] != 'n') && flag3 == 0);
        printf("\n");
    }
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < noOfWishList; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i+1, valueOfItem[i], financeOption[i], itemCost[i]);
    }

    printf("---- -------- -------- -----------\n");
    for (i = 0; i < noOfWishList; i++)
    {
        totalcost = itemCost[i] + totalcost;
    }

    printf("                      $%11.2lf\n\n", totalcost);
    printf("Best of luck in all your future endeavours!\n");
    return 0;
}
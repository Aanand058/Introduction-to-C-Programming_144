

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define maxWishList 10
#define minItemCost 100 // the items cost should must be minimum $100

int main(void)
{
    const double minNetIncome = 500.00;
    const double maxNetIncome = 400000.00;
    double monIncome; // monthly net income
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    
    int i;
    int noOfWishList; // number of wish list items they want to use in the forecast
    double itemCost[maxWishList];
    int valueOfItem[maxWishList];
    char financeOption[maxWishList];
    double totalcost = 0;
    int forecastSelection;
    int filterPriority;
    double filterAmount1 = 0, filterAmount2 = 0, filterAmount3 = 0; // A character value representing if an item has financing options (don’t need to pay entire value up-front)
    int calculation, years, months;
    int bool1 = 0;

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
            scanf(" %c", &financeOption[i]);
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
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, valueOfItem[i], financeOption[i], itemCost[i]);
    }

    printf("---- -------- -------- -----------\n");
    for (i = 0; i < noOfWishList; i++)
    {
        totalcost = itemCost[i] + totalcost;
    }

    printf("                      $%11.2lf\n\n", totalcost);

    for (i = 0; i < noOfWishList || flag4 == 0; i++)
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &forecastSelection);
        printf("\n");

        if (forecastSelection < 0 || forecastSelection > 2)
        {
            printf("ERROR: Invalid menu selection.\n\n");
        }
        else if (forecastSelection == 0)
        {
            flag4 = 1;
        }
        else if (forecastSelection == 1)
        {

            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalcost);

            calculation = totalcost / monIncome;
            years = calculation / 12;

            months = ((calculation % 12) + 1);

            printf("Forecast: %d years, %d months\n", years, months);
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");
        }
        else if (forecastSelection == 2)
        {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &filterPriority);
            printf("\n");

            if (filterPriority < 0 || filterPriority > 3)
            {
                printf("ERROR: Invalid filter selection.\n\n");
            }
            else if (filterPriority == 1)
            {
                for (i = 0; i < noOfWishList; i++)
                {
                    if (valueOfItem[i] == 1)
                    {
                        filterAmount1 = filterAmount1 + itemCost[i];
                    }
                }

                printf("====================================================\n");
                printf("Filter:   by priority (%d)\n", filterPriority);
                printf("Amount:   $%1.2lf\n", filterAmount1);
                calculation = filterAmount1 / monIncome;
                years = calculation / 12;

                months = ((calculation % 12) + 1);

                printf("Forecast: %d years, %d months\n", years, months);

                for (i = 0; i < noOfWishList; i++)
                {
                    if (valueOfItem[i] == 1)
                    {
                        if (financeOption[i] == 'y')
                        {
                            bool1 = bool1 || 1;
                        }
                        else
                        {
                            bool1 = bool1 || 0;
                        }
                    }
                }
                if (bool1)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }

                printf("====================================================\n\n");
            }
            else if (filterPriority == 2)
            {
                for (i = 0; i < noOfWishList; i++)
                {
                    if (valueOfItem[i] == 2)
                    {
                        filterAmount2 = filterAmount2 + itemCost[i];
                    }
                }

                printf("====================================================\n");
                printf("Filter:   by priority (%d)\n", filterPriority);
                printf("Amount:   $%1.2lf\n", filterAmount2);
                calculation = filterAmount2 / monIncome;
                years = calculation / 12;

                months = ((calculation % 12) + 1);

                printf("Forecast: %d years, %d months\n", years, months);

                for (i = 0; i < noOfWishList; i++)
                {
                    if (valueOfItem[i] == 2)
                    {
                        if (financeOption[i] == 'y')
                        {
                            bool1 = 1;
                        }
                        else
                        {
                            bool1 = 0;
                        }
                    }
                }
                if (bool1==1)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                
                printf("====================================================\n\n");
            }
            else if (filterPriority == 3)
            {
                for (i = 0; i < noOfWishList; i++)
                {
                    if (valueOfItem[i] == 3)
                    {
                        filterAmount3 = filterAmount3 + itemCost[i];
                    }
                }

                printf("====================================================\n");
                printf("Filter:   by priority (%d)\n", filterPriority);
                printf("Amount:   $%1.2lf\n", filterAmount3);
                calculation = filterAmount3 / monIncome;
                years = calculation / 12;

                months = ((calculation % 12) + 1);

                printf("Forecast: %d years, %d months\n", years, months);

                for (i = 0; i < noOfWishList; i++)
                {
                    if (valueOfItem[i] == 3)
                    {
                        if (financeOption[i] == 'y')
                        {
                            bool1 = bool1 || 1;
                        }
                        else
                        {
                            bool1 = bool1 || 0;
                        }
                    }
                }
                if (bool1)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }

                printf("====================================================\n\n");
            }
        }
    }

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
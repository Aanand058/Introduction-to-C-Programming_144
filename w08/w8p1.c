

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"



// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *intPositive)
{
    int input;
    int flag1 = 0;

    do
    {
        scanf("%d", &input);
        if (input <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag1 = 1;
        }
    } while (flag1 == 0);

    if (intPositive != NULL)
    {
        *intPositive = input;
    }
    return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *doublePositive)
{
    double input2;
    int flag2 = 0;

    do
    {
        scanf("%lf", &input2);
        if (input2 <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag2 = 1;
        }
    } while (flag2 == 0);

    if (doublePositive != NULL)
    {
        *doublePositive = input2;
    }
    return input2;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int productNo)
{
    
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");

    printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
    printf("NOTE: A 'serving' is %dg\n", GRAMS_NUMBER);
    printf("\n");
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productNo )
{
    struct CatFoodInfo cat_food;
    int flag3 = 0;
    printf("Cat Food Product #%d\n", productNo +1);
    printf("--------------------\n");
    flag3 = 1;

    printf("SKU           : ");
    flag3 = 0;
    do
    {
        scanf("%d", &cat_food.skuNumber);
        if (cat_food.skuNumber <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag3 = 1;
        }
    } while (flag3 == 0);

    printf("PRICE         : $");
    int flag4 = 0;
    do
    {
        scanf("%lf", &cat_food.productPrice);
        if (cat_food.productPrice <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag4 = 1;
        }
    } while (flag4 == 0);

    printf("WEIGHT (LBS)  : ");
    int flag5 = 0;
    do
    {
        scanf("%lf", &cat_food.productWeight);
        if (cat_food.productWeight <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag5 = 1;
        }
    } while (flag5 == 0);

    printf("CALORIES/SERV.: ");
    int flag6 = 0;
    do
    {
        scanf("%d", &cat_food.calories);
        if (cat_food.calories <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag6 = 1;
        }
    } while (flag6 == 0);

    printf("\n");

    return cat_food;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int skuNumber, double *productPrice, int caloriePerServing, double *productWeight)
{
    printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *productPrice, *productWeight, caloriePerServing);
}
// 7. Logic entry point
void start(void)
{
    int i;
    struct CatFoodInfo cat_food[MAX_PRODUCTS];
    openingMessage(MAX_PRODUCTS);

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        cat_food[i] = getCatFoodInfo(i);
    }

    displayCatFoodHeader();

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        displayCatFoodData(cat_food[i].skuNumber, &cat_food[i].productPrice, cat_food[i].calories, &cat_food[i].productWeight);
    }
}
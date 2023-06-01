

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    const int productId1= 111;
    const int productId2= 222;
    const int productId3= 111;

    const char taxed1= 'Y';
    const char taxed2= 'N';
    const char taxed3= 'N';

    const double price1 = 111.49;
    const double price2 = 222.99;
    const double price3 = 334.49;

    
    int decision;
    double average;
    
    
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", productId1);
    printf("  Taxed: %c\n",taxed1);
    printf("  Price: $%.4lf\n",price1);
    printf("\n");
    printf("Product-2 (ID:%d)\n",productId2);
    printf("  Taxed: %c\n",taxed2);
    printf("  Price: $%.4lf\n",price2);
    printf("\n");
    printf("Product-3 (ID:%d)\n",productId3);
    printf("  Taxed: %c\n",taxed3);
    printf("  Price: $%.4lf\n",price3);
    printf("\n");




    average = (price1 + price2 + price3) / 3;
    printf("The average of all prices is: $%.4lf\n", average);
    printf("\n");



    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");



    printf("Some Data Analysis...\n");
    printf("=====================\n");

    if (taxed1 == 'y' || taxed1 == 'Y')
    {
        decision = 1;
    }
    else
    {
        decision = 0;
    }
    printf("1. Is product 1 taxable? -> %d\n", decision);
    printf("\n");
    if (taxed2 == 'N' || taxed3 == 'N')
    {
        decision = 1;
    }
    else
    {
        decision = 0;
    }
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", decision);
    printf("\n");

    if (price3 < testValue)
    {
        decision = 1;
    }
    else
    {
        decision = 0;
    }
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n", testValue, decision);
    printf("\n");

    if (price3 > (price1 + price2))
    {
        decision = 1;
    }
    else
    {
        decision = 0;
    }
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", decision);
    printf("\n");

    if (price1 >= (price3 - price2))
    {
        decision = 1;
    }
    else
    {
        decision = 0;
    }
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n", decision, (price3 - price2));
    printf("\n");

    if (price2 >= average)
    {
        decision = 1;
    }
    else
    {
        decision = 0;
    }
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", decision);
    printf("\n");
    if (productId1 == productId2 || productId1 == productId3)
    {
        decision = 0;
    }
    else
    {
        decision = 1;
    }
    printf("7. Based on product ID, product 1 is unique -> %d\n", decision);
    printf("\n");
    if (productId2 == productId1 || productId2 == productId3)
    {
        decision = 0;
    }
    else
    {
        decision = 1;
    }
    printf("8. Based on product ID, product 2 is unique -> %d\n", decision);
    printf("\n");
    if (productId3 == productId1 || productId3 == productId2)
    {
        decision = 0;
    }
    else
    {
        decision = 1;
    }
    printf("9. Based on product ID, product 3 is unique -> %d\n", decision);

    return 0;
}
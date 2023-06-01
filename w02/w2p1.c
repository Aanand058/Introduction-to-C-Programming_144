/*
*****************************************************************************
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';

    int noOfShirts;
    float smallShirt, mediumShirt, largeshirt;
    float taxes, total, sub_total;

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &smallShirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &mediumShirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &largeshirt);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", smallShirt);
    printf("MEDIUM : $%.2f\n", mediumShirt);
    printf("LARGE  : $%.2f\n", largeshirt);
    printf("\n");

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &noOfShirts);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", noOfShirts);
    sub_total = (noOfShirts * smallShirt);

    int temp1;
    float temp2;
    taxes = (sub_total * TAX);
    temp1 = ((taxes * 100) + 1);
    temp2 = (float)temp1 / 100;
    taxes = temp2;

    int temp3;
    float temp4;
    total = (sub_total + taxes);
    temp3 = ((total * 100) + 1);
    temp4 = (float)temp3 / 100;
    total = temp4;

    printf("Sub-total: $%.4f\n", sub_total);
    printf("Taxes    : $ %.4lf\n", taxes);
    printf("Total    : $%.4lf\n", total);
    return 0;
}


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
   const double TAX = 0.13;
   const char patSize = 'S', salSize = 'M', tomSize = 'L';

   int noOfShirtsPat =6, noOfShirtsSal=4, noOfShirtsTom=3;
   float smallShirt, mediumShirt, largeshirt;
   float taxes1, taxes2, taxes3, total1, total2, total3, sub_total1, sub_total2, sub_total3;
   float grandTax, grandSub_total, grandTotal;
   
   

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
   scanf("%d", &noOfShirtsPat);
   printf("\n");

   printf("Tommy's shirt size is '%c'\n", tomSize);
   printf("Number of shirts Tommy is buying: ");
   scanf("%d", &noOfShirtsTom);
   printf("\n");

   printf("Sally's shirt size is '%c'\n", salSize);
   printf("Number of shirts Sally is buying: ");
   scanf("%d", &noOfShirtsSal);
   printf("\n");

   sub_total1 = noOfShirtsPat * smallShirt;
   sub_total2 = noOfShirtsSal * mediumShirt;
   sub_total3 = noOfShirtsTom * largeshirt;

   taxes1 = sub_total1 * TAX;
   float rounded1;
   int cents1;
   rounded1 = ((int)(taxes1 * 100 + 0.5) / 100.0);
   cents1 = (int)(rounded1 * 100);
   taxes1 = ((float)cents1) / 100;

   taxes2 = sub_total2 * TAX;
   float rounded2;
   int cents2;
   rounded2 = ((int)(taxes2 * 100 + 0.5) / 100.0);
   cents2 = (int)(rounded2 * 100);
   taxes2 = ((float)cents2) / 100;

   taxes3 = sub_total3 * TAX;
   float rounded3;
   int cents3;
   cents3 = ((taxes3* 100) +1);
   rounded3 = (float) cents3/ 100;
   taxes3= rounded3;


   total1 = sub_total1 + taxes1;
   total2 = sub_total2 + taxes2;
   total3 = sub_total3 + taxes3;

   grandSub_total = sub_total1 + sub_total2 + sub_total3;
   grandTax = taxes1 + taxes2 + taxes3;
   grandTotal = total1 + total2 + total3;

 

   printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
   printf("-------- ---- ----- --- --------- --------- ---------\n");
   printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallShirt, noOfShirtsPat, sub_total1, taxes1, total1);
   printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumShirt, noOfShirtsSal, sub_total2, taxes2, total2);
   printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largeshirt, noOfShirtsTom, sub_total3, taxes3, total3);
   printf("-------- ---- ----- --- --------- --------- ---------\n");
   printf("%33.4lf %9.4lf %9.4lf\n\n", grandSub_total, grandTax, grandTotal);

   

    
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");
    printf("\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", grandSub_total);

    int toonies, loonies, quarters, dimes, nickels, pennies;
    float ramt;

    toonies = grandSub_total / 2;
    ramt = grandSub_total - (2 * toonies);
    printf("Toonies  %3d %9.4lf\n", toonies, ramt);

    loonies = ramt ;
    ramt = ramt - loonies;
    printf("Loonies  %3d %9.4lf\n", loonies, ramt);

    ramt = (int)(ramt * 100);
    quarters = ramt / 25;
    ramt = (int)ramt % 25;
    printf("Quarters %3d %9.4lf\n", quarters, ramt / 100);

    dimes = ramt / 10;
    ramt = (int)ramt % 10;
    printf("Dimes    %3d %9.4lf\n", dimes, ramt/100);

    nickels = ramt / 5;
    ramt = (int)ramt%5;
    printf("Nickels  %3d %9.4lf\n", nickels, ramt/100);

    pennies = ramt/1;
    ramt= (int)ramt%1;
    printf("Pennies  %3d %9.4lf\n", pennies, ramt/100);

    printf("\n");

    float avg1;
    avg1= (grandSub_total) / (noOfShirtsPat+noOfShirtsSal+ noOfShirtsTom);

    printf("Average cost/shirt: $%.4f\n", avg1);
    printf("\n");

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", grandTotal);

    

    toonies = grandTotal / 2;
    ramt = grandTotal - (2 * toonies);
    printf("Toonies  %3d %9.4lf\n", toonies, ramt);

    loonies = ramt ;
    ramt = ramt - loonies;
    printf("Loonies  %3d %9.4lf\n", loonies, ramt);

    ramt = (int)(ramt * 100);
    quarters = ramt / 25;
    ramt = (int)ramt % 25;
    printf("Quarters %3d %9.4lf\n", quarters, ramt / 100);

    dimes = ramt / 10;
    ramt = (int)ramt % 10;
    printf("Dimes    %3d %9.4lf\n", dimes, ramt/100);

    nickels = ramt / 5;
    ramt = (int)ramt%5;
    printf("Nickels  %3d %9.4lf\n", nickels, ramt/100);

    pennies = ramt/1;
    ramt= (int)ramt%1;
    printf("Pennies  %3d %9.4lf\n", pennies, ramt/100);

    printf("\n");

    float avg2;
    avg2= (grandTotal) / (noOfShirtsPat+noOfShirtsSal+ noOfShirtsTom);

    printf("Average cost/shirt: $%.4f\n", avg2);
    printf("\n");


   return 0;
}
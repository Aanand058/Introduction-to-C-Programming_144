/*
*****************************************************************************
                          Workshop - #4 (P2)
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
    int noOfApples, noOfOranges, noOfTomatoes, noOfCabbage, noOfPears;
    int totalNoOfApples = 0, totalNoOfOranges = 0, totalNoOfTomatoes = 0, totalNoOfCabbage = 0, totalNoOfPears = 0;
    int done1 = 0, done2 = 0, done3 = 0, done4 = 0, done5 = 0;
    int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0, temp5 = 0;
    int noOfApplesPicked, noOfOrangesPicked, noOfTomatoesPicked, noOfCabbagePicked, noOfPearsPicked;
    
    int anoShop;

    
    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &noOfApples);
            if (noOfApples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            temp1 = noOfApples;
        } while (noOfApples < 0);
        printf("\n");

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &noOfOranges);
            if (noOfOranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            temp2 = noOfOranges;
        } while (noOfOranges < 0);
        printf("\n");

        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &noOfPears);
            if (noOfPears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            temp3 = noOfPears;
        } while (noOfPears < 0);
        printf("\n");

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &noOfTomatoes);
            if (noOfTomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            temp4 = noOfTomatoes;
        } while (noOfTomatoes < 0);
        printf("\n");

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &noOfCabbage);
            if (noOfCabbage < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            temp5 = noOfCabbage;
        } while (noOfCabbage < 0);

        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");

        if (noOfApples > 0)
        {
            while ((noOfApplesPicked != noOfApples) && done1 == 0)
            {

                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &noOfApplesPicked);

                if (noOfApplesPicked > noOfApples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", temp1);
                }
                else if (noOfApplesPicked < 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfApplesPicked == 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfApplesPicked <= noOfApples)
                {
                    totalNoOfApples = totalNoOfApples + noOfApplesPicked;

                    if (totalNoOfApples < noOfApples)
                    {
                        printf("Looks like we still need some APPLES...\n");
                        temp1 = noOfApples - totalNoOfApples;
                    }

                    else if (temp1 == noOfApplesPicked && done1 == 0)
                    {
                        printf("Great, that's the apples done!\n");
                        done1 = 1;
                    }
                }
            }
            printf("\n");
        }
       

        if (noOfOranges > 0)
        {
            while ((noOfOrangesPicked != noOfOranges) && done2 == 0)
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &noOfOrangesPicked);

                if (noOfOrangesPicked > noOfOranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", temp2);
                }
                else if (noOfOrangesPicked < 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfOrangesPicked == 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfOrangesPicked <= noOfOranges)
                {
                    totalNoOfOranges = totalNoOfOranges + noOfOrangesPicked;

                    if (totalNoOfOranges < noOfOranges)
                    {
                        printf("Looks like we still need some ORANGES...\n");
                        temp2 = noOfOranges - totalNoOfOranges;
                    }

                    else if (temp2 == noOfOrangesPicked && done2 == 0)
                    {
                        printf("Great, that's the oranges done!\n");
                        done2 = 1;
                        
                    }
                }
            }
            printf("\n");
        }
        

        if (noOfPears > 0)
        {
            while ((noOfPearsPicked != noOfPears) && done3 == 0)
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &noOfPearsPicked);

                if (noOfPearsPicked > noOfPears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", temp3);
                }
                else if (noOfPearsPicked < 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfPearsPicked == 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfPearsPicked <= noOfPears)
                {
                    totalNoOfPears = totalNoOfPears + noOfPearsPicked;

                    if (totalNoOfPears < noOfPears)
                    {
                        printf("Looks like we still need some PEARS...\n");
                        temp3 = noOfPears - totalNoOfPears;
                    }

                    else if (temp3 == noOfPearsPicked && done3 == 0)
                    {
                        printf("Great, that's the pears done!\n");
                        done3 = 1;
                        
                    }
                }
            }
            printf("\n");
        }
        

       if (noOfTomatoes > 0)
        {
            while ((noOfTomatoesPicked != noOfTomatoes) && done4 == 0)
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &noOfTomatoesPicked);

                if (noOfTomatoesPicked > noOfTomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", temp4);
                }
                else if (noOfTomatoesPicked < 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfTomatoesPicked == 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfTomatoesPicked <= noOfTomatoes)
                {
                    totalNoOfTomatoes = totalNoOfTomatoes + noOfTomatoesPicked;

                    if (totalNoOfTomatoes < noOfTomatoes)
                    {
                        printf("Looks like we still need some TOMATOES...\n");
                        temp4 = noOfTomatoes - totalNoOfTomatoes;
                    }

                    else if (temp4 == noOfTomatoesPicked && done4 == 0)
                    {
                        printf("Great, that's the tomatoes done!\n");
                        done4 = 1;
                        
                    }
                }
            }
            printf("\n");
        }
        

        if (noOfCabbage > 0)
        {
            while ((noOfCabbagePicked != noOfCabbage) && done5 == 0)
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &noOfCabbagePicked);

                if (noOfCabbagePicked > noOfCabbage)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", temp5);
                }
                else if (noOfCabbagePicked < 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfCabbagePicked == 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (noOfCabbagePicked <= noOfCabbage)
                {
                    totalNoOfCabbage = totalNoOfCabbage + noOfCabbagePicked;

                    if (totalNoOfCabbage < noOfCabbage)
                    {
                        printf("Looks like we still need some CABBAGES...\n");
                        temp5 = noOfCabbage - totalNoOfCabbage;
                    }

                    else if (temp5 == noOfCabbagePicked && done5 == 0)
                    {
                        printf("Great, that's the cabbages done!\n");
                        done5 = 1;
                        
                    }
                }
            }
            printf("\n");
        }
       
        
        printf("All the items are picked!\n");
        printf("\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &anoShop);
        printf("\n");

    } while (anoShop != 0);
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}
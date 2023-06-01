

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    int  bagWeight;
    char lightOrBlend;
    char grindSize;
    char yesOrNo;
    char commOrRes;
    char yesOrNo1;
    int noOfDialyServ;
    char mildOrRich;
    int light1, light2, light3, blend1, blend2, blend3, course1, course2;
    int course3, fine1, fine2, fine3, bagWeight1, bagWeight2, bagWeight3, cream1, cream2, cream3;
    double celsius,celsius1, fahrenheit1, lbs1,celsius2,fahrenheit2,lbs2,celsius3,fahrenheit3,lbs3;
    int i;
    int mild, rich, yes, no, comm, res;
    int flag1, flag2, flag3, flag4, flag5, flag6, flag7, flag8, flag9, flag10, flag11, flag12, flag13, flag14, flag15;
	// Note:
	// You can convert Celsius to Fahrenheit given the following formula:
	// fahrenheit = (celsius * 1.8) + 32.0);



    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    for (i = 1; i <= 3; i++)
    {
        printf("COFFEE-%d...\n", i);
        printf("Type ([L]ight,[B]lend): ");
        scanf(" %c", &lightOrBlend);

        printf("Grind size ([C]ourse,[F]ine): ");
        scanf(" %c", &grindSize);
        printf("Bag weight (g): ");
        scanf("%d", &bagWeight);
        if (i == 1)
        {
            bagWeight1 = bagWeight;
        }
        else if (i == 2)
        {
            bagWeight2 = bagWeight;
        }
        else if (i == 3)
        {
            bagWeight3 = bagWeight;
        }
        printf("Best served with cream ([Y]es,[N]o): ");
        scanf(" %c", &yesOrNo);
        printf("Ideal serving temperature (Celsius): ");
        scanf("%lf", &celsius);
        printf("\n");

        if (i == 1)
        {
            if ((lightOrBlend == 'l') || (lightOrBlend == 'L'))
            {
                light1 = 1;
                blend1 = 0;
            }
            else if ((lightOrBlend == 'b') || (lightOrBlend == 'B'))
            {
                light1 = 0;
                blend1 = 1;
            }

            if ((grindSize == 'c') || (grindSize == 'C'))
            {
                course1 = 1;
                fine1 = 0;
            }
            else if ((grindSize == 'f') || (grindSize == 'F'))
            {
                course1 = 0;
                fine1 = 1;
            }
            if ((yesOrNo=='Y')|| (yesOrNo=='y'))
            {
                cream1=1;
            }
            else if ((yesOrNo=='N')|| (yesOrNo=='n'))
            {
                cream1=0;
            }
            lbs1= bagWeight1/GRAMS_IN_LBS;
            celsius1= celsius;
            fahrenheit1 = ((celsius * 1.8) + 32.0);
        }

        if (i == 2)
        {
            if ((lightOrBlend == 'l') || (lightOrBlend == 'L'))
            {
                light2 = 1;
                blend2 = 0;
            }
            else if ((lightOrBlend == 'b') || (lightOrBlend == 'B'))
            {
                light2 = 0;
                blend2 = 1;
            }

            if ((grindSize == 'c') || (grindSize == 'C'))
            {
                course2 = 1;
                fine2 = 0;
            }
            else if ((grindSize == 'f') || (grindSize == 'F'))
            {
                course2 = 0;
                fine2 = 1;
            }
            if ((yesOrNo=='Y')|| (yesOrNo=='y'))
            {
                cream2=1;
            }
            else if ((yesOrNo=='N')|| (yesOrNo=='n'))
            {
                cream2=0;
            }
            lbs2= bagWeight2/GRAMS_IN_LBS;
            celsius2= celsius;
            fahrenheit2 = ((celsius * 1.8) + 32.0);
        }

        if (i == 3)
        {
            if ((lightOrBlend == 'l') || (lightOrBlend == 'L'))
            {
                light3 = 1;
                blend3 = 0;
            }
            else if ((lightOrBlend == 'b') || (lightOrBlend == 'B'))
            {
                light3 = 0;
                blend3 = 1;
            }

            if ((grindSize == 'c') || (grindSize == 'C'))
            {
                course3 = 1;
                fine3 = 0;
            }
            else if ((grindSize == 'f') || (grindSize == 'F'))
            {
                course3 = 0;
                fine3 = 1;
            }
            if ((yesOrNo=='Y')|| (yesOrNo=='y'))
            {
                cream3=1;
            }
            else if ((yesOrNo=='N')|| (yesOrNo=='n'))
            {
                cream3=0;
            }
            lbs3= bagWeight3/GRAMS_IN_LBS;
            celsius3= celsius;
            fahrenheit3 = ((celsius * 1.8) + 32.0);
        }
    }
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",light1,blend1,course1,fine1,bagWeight1, lbs1,cream1,celsius1,fahrenheit1);
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",light2,blend2,course2,fine2,bagWeight2, lbs2,cream2,celsius2,fahrenheit2);
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",light3,blend3,course3,fine3,bagWeight3, lbs3,cream3,celsius3,fahrenheit3);
    printf("\n");


  

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &mildOrRich);
    if (mildOrRich == 'm' || mildOrRich == 'M')
    {
        mild = 1;
    }
    else
    {
        rich = 1;
    }

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &yesOrNo1);
    if (yesOrNo1 == 'y' || yesOrNo1 == 'Y')
    {
        yes = 1;
    }
    else
    {
        no = 1;
    }
    printf("Typical number of daily servings: ");
    scanf("%d", &noOfDialyServ);

    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &commOrRes);
    if (commOrRes == 'C' || commOrRes == 'c')
    {
        comm = 1;
    }
    else
    {
        res = 1;
    }
    printf("\n");

    // for 1st coffee
    if (mild == 1 && light1 == 1)
    {
        flag1 = 1;
    }
    else
    {
        flag1 = 0;
    }

    if (comm == 1 && fine1 == 1)
    {
        flag2 = 1;
    }
    else
    {
        flag2 = 0;
    }

    if (noOfDialyServ <= 4 && bagWeight1 <= 250)
    {
        flag3 = 1;
    }
    else
    {
        flag3 = 0;
    }

    if (yes == 1 && cream1 == 1)
    {
        flag4 = 1;
    }
    else
    {
        flag4 = 0;
    }

    if (comm == 1 && (celsius1 > 70))
    {
        flag5 = 1;
    }
    else
    {
        flag5 = 0;
    }

    // for 2nd coffee
    if (mild == 1 && light2 == 1)
    {
        flag6 = 1;
    }
    else
    {
        flag6 = 0;
    }

    if (comm == 1 && fine2 == 1)
    {
        flag7 = 1;
    }
    else
    {
        flag7 = 0;
    }

    if (noOfDialyServ <= 9 && bagWeight2 <= 500)
    {
        flag8 = 1;
    }
    else
    {
        flag8 = 0;
    }
    if (yes == 1 && cream2 == 1)
    {
        flag9 = 1;
    }
    else
    {
        flag9 = 0;
    }

    if (comm == 1 && (celsius2 >= 70))
    {
        flag10 = 1;
    }
    else
    {
        flag10 = 0;
    }

    // for 3rd coffee
    if (mild == 1 && light3 == 1)
    {
        flag11 = 1;
    }
    else
    {
        flag11 = 0;
    }

    if (comm == 1 && fine3 == 1)
    {
        flag12 = 1;
    }
    else
    {
        flag12 = 0;
    }

    if (noOfDialyServ > 10 && bagWeight3 <= 1000)
    {
        flag13 = 1;
    }
    else
    {
        flag13 = 0;
    }

    if (yes == 1 && cream3 == 1)
    {
        flag14 = 1;
    }
    else
    {
        flag14 = 0;
    }

    if (comm == 1 && (celsius3 >= 70))
    {
        flag15 = 1;
    }
    else
    {
        flag15 = 0;
    }
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", flag1, flag2, flag3, flag4, flag5);
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", flag6, flag7, flag8, flag9, flag10);
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", flag11, flag12, flag13, flag14, flag15);
    printf("\n");

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &mildOrRich);
    if (mildOrRich == 'r' || mildOrRich == 'R')
    {
        rich = 1;
    }
    else
    {
        mild = 1;
    }

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &yesOrNo1);
    if (yesOrNo1 == 'n' || yesOrNo1 == 'N')
    {
        no = 1;
    }
    else
    {
        yes = 0;
    }
    printf("Typical number of daily servings: ");
    scanf("%d", &noOfDialyServ);

    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &commOrRes);
    if (commOrRes == 'R' || commOrRes == 'r')
    {
        res = 1;
    }
    else
    {
        comm = 1;
    }
    printf("\n");

    // for 1st coffee
    if (rich == 1 && blend1 == 1)
    {
        flag1 = 1;
    }
    else
    {
        flag1 = 0;
    }

    if (res == 1 && course1 == 1)
    {
        flag2 = 1;
    }
    else
    {
        flag2 = 0;
    }

    if (noOfDialyServ <= 4 && bagWeight1 <= 250)
    {
        flag3 = 1;
    }
    else
    {
        flag3 = 0;
    }

    if (no && cream1)
    {
        flag4 = 0;
    }
    else
    {
        flag4 = 1;
    }

    if (res == 1 && ((celsius1 >= 60) && (celsius1 <= 69.9)))
    {
        flag5 = 1;
    }
    else
    {
        flag5 = 0;
    }

    // for 2nd coffee
    if (rich == 1 && blend2 == 1)
    {
        flag6 = 1;
    }
    else
    {
        flag6 = 0;
    }

    if (res == 1 && course2 == 1)
    {
        flag7 = 1;
    }
    else
    {
        flag7 = 0;
    }

    if (noOfDialyServ <= 9 && bagWeight2 <= 500)
    {
        flag8 = 1;
    }
    else
    {
        flag8 = 0;
    }
    if (no && cream2)
    {
        flag9 = 0;
    }
    else
    {
        flag9 = 1;
    }

    if (res == 1 && ((celsius2 >= 60) && (celsius2 <= 69.9)))
    {
        flag10 = 1;
    }
    else
    {
        flag10 = 0;
    }

    // for 3rd coffee
    if (rich == 1 && blend3 == 1)
    {
        flag11 = 1;
    }
    else
    {
        flag11 = 0;
    }

    if (res == 1 && course3 == 1)
    {
        flag12 = 1;
    }
    else
    {
        flag12 = 0;
    }

    if (noOfDialyServ >= 10 && bagWeight3 <= 1000)
    {
        flag13 = 1;
    }
    else
    {
        flag13 = 0;
    }

    if (no && cream3)
    {
        flag14 = 0;
    }
    else
    {
        flag14 = 1;
    }

    if (res == 1 && ((celsius3 >= 60) && (celsius3 <= 69.9)))
    {
        flag15 = 1;
    }
    else
    {
        flag15 = 0;
    }
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", flag1, flag2, flag3, flag4, flag5);
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", flag6, flag7, flag8, flag9, flag10);
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", flag12, flag12, flag13, flag14, flag15);
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");


    return 0;
}
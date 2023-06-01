/*
*****************************************************************************
						  Workshop - #8 (P2)
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

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
void openingMessage(const int productNumber)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_NUMBER);
	printf("\n");
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productNumber)
{
	struct CatFoodInfo cat_food;
	int flag3 = 0;
	printf("Cat Food Product #%d\n", productNumber + 1);
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
void displayCatFoodData(int skuNumber, double *productPrice, int calories ,double *productWeight )
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *productPrice, *productWeight, calories);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *pounds, double *convertedResultToKg)
{
	double poundsToKg = (*pounds) / POUNDS_TO_KGS;
	
	if (convertedResultToKg != NULL)
	{
		*convertedResultToKg = poundsToKg;
	}

	return poundsToKg;
}
// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *pounds, int *convertedResultToG)
{
	int poundsToG = ((*pounds) / POUNDS_TO_KGS) * 1000;

	if (convertedResultToG != NULL)
	{
		*convertedResultToG = poundsToG;
	}

	return poundsToG;
}
// 10. convert lbs: kg and g
void convertLbs(const double *pounds, double *convertedResultToKg, int *convertedResultToG)
{

	double poundsToKg = (*pounds) / POUNDS_TO_KGS;
	int poundsToG = ((*pounds) / POUNDS_TO_KGS) * 1000;

	if (convertedResultToG != NULL && convertedResultToKg != NULL)
	{
		*convertedResultToG = poundsToG;
		*convertedResultToKg = poundsToKg;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double *numberOfServings)
{

	double servings = ((double)totalGrams) / servingSizeGrams;

	if (numberOfServings != NULL)
	{
		*numberOfServings = servings;
	}

	return servings;
}
// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *numberOfServings, double *result)
{

	double costPerServing = (*price) / (*numberOfServings);

	if (result != NULL)
	{
		*result = costPerServing;
	}

	return costPerServing;
}
// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *totalCalories, double *result)
{

	double costPerCalories = (*price) / (*totalCalories);

	if (result != NULL)
	{
		*result = costPerCalories;
	}

	return costPerCalories;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo cat_food)
{
	struct ReportData report;
	report.skuNumber = cat_food.skuNumber;
	report.productPrice = cat_food.productPrice;
	report.productWeightInPounds = cat_food.productWeight;
	report.calories = cat_food.calories;
	report.productWeightInKg = convertLbsKg(&report.productWeightInPounds, &report.productWeightInKg);
	report.productWeightInGrams = convertLbsG(&report.productWeightInPounds, &report.productWeightInGrams);
	report.servings = calculateServings(GRAMS_NUMBER, report.productWeightInGrams, &report.servings);
	double totalCalories = report.calories * report.servings;
	report.costPerServing = calculateCostPerServing(&report.productPrice, &report.servings, &report.costPerServing);
	report.costCaloriesPerServing = calculateCostPerCal(&report.productPrice, &totalCalories, &report.costCaloriesPerServing);

	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_NUMBER);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapestProduct)
{

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.skuNumber, report.productPrice, report.productWeightInPounds, report.productWeightInKg, report.productWeightInGrams, report.calories, report.servings, report.costPerServing, report.costCaloriesPerServing);
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cat_food)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cat_food.skuNumber, cat_food.productPrice);
	printf("\n");

	printf("Happy shopping!\n");
	printf("\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct ReportData report[MAX_PRODUCTS];
	struct CatFoodInfo cat_food[MAX_PRODUCTS];
	int i, cheapestProduct = 0;
	openingMessage(MAX_PRODUCTS);
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		cat_food[i] = getCatFoodInfo(i);
		report[i] = calculateReportData(cat_food[i]);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(cat_food[i].skuNumber, &cat_food[i].productPrice,cat_food[i].calories,  &cat_food[i].productWeight);
	}

	double cheapestProductPrice = report[0].costPerServing;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (report[i].costPerServing <= cheapestProductPrice)
		{
			cheapestProductPrice = report[i].costPerServing;
			cheapestProduct = i;
		}
	}
	printf("\n");
	displayReportHeader();

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayReportData(report[i], cheapestProduct);

		if (cheapestProduct == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (i == cheapestProduct)
		{
			displayFinalAnalysis(cat_food[i]);
		}
	}
}
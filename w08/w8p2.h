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

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define GRAMS_NUMBER 64
#define POUNDS_TO_KGS 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int skuNumber;
    double productPrice;
    int calories;
    double productWeight;
};

struct ReportData
{
    int skuNumber;
    double productPrice;
    int calories;
    double productWeightInPounds;
    double productWeightInKg;
    int productWeightInGrams;
    double servings;
    double costPerServing;
    double costCaloriesPerServing;
};
// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *intPositive);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *doublePositive);

// 3. Opening Message (include the number of products that need entering)
void openingMessage( const int productNumber);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int skuNumber, double *productPrice, int calories ,double *productWeight );

// 7. Logic entry point
void start(void);




// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *pounds, double *convertedResultToKg);
// 9. convert lbs: g
int convertLbsG(const double *pounds, int *convertedResultToG);
// 10. convert lbs: kg / g
void convertLbs(const double *pounds, double *convertedResultToKg, int *convertedResultToG);
// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double *numberOfServings);
// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *numberOfServings, double *result);
// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *totalCalories, double *result);
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo cat_food);
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapestProduct);
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cat_food);
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);
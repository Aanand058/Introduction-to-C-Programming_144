/*
*****************************************************************************
                          Workshop - #8 (P1)
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

#define MAX_PRODUCTS 3
#define GRAMS_NUMBER 64
// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo {
    int skuNumber;
    double productPrice;
    int calories;
    double productWeight;
};



// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *intPositive);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *doublePositive);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int productNo);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productNo );

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int skuNumber, double *productPrice, int caloriePerServing, double *productWeight);

// 7. Logic entry point
void start(void);


// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////
// This function will return integer value.
int inputInt(void);

// This function will return positive integer value.
int inputIntPositive(void);

// This function will return integer value within the specified range of the program.
int inputIntRange(int lowerBound, int upperBound);

// This function will return a character value within the list of valid characters.
char inputCharOption(char str1[]);

// This function will return a C string value containing the number of characters within the range specified by the 2nd and 3rd arguments.
void inputCString(char *str2, int minCharacter, int maxCharacter);

// This function is the same as inputCString but is exclusively for numbers
void inputCStringNumbers(char* str, int minCharacter, int maxCharacter);

// This function will display the 10-character digit phone number in formatted series.
void displayFormattedPhone(const char *str3);




// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H

/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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

#include <stdio.h>

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int lowerBound, int upperBound);

char inputCharOption(char str1[]);

void inputCString(char *str2, int minCharacter, int maxCharacter);

void displayFormattedPhone(const char *str3);
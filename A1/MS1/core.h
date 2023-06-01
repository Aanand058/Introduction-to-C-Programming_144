

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
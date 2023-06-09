

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
// This function will return integer value.
int inputInt(void)
{
    char character = 'x';
    int value;

    do
    {
        scanf("%d%c", &value, &character);

        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (character != '\n');

    return value;
}
// This function will return positive integer value.
int inputIntPositive(void)
{
    char character1 = 'x';
    int value1;

    do
    {
        scanf("%d%c", &value1, &character1);

        if (character1 != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a number: ");
        }

        if (value1 <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value1 <= 0);

    return value1;
}
// This function will return integer value within the specified range of the program.

int inputIntRange(int lowerBound, int upperBound)
{
    char character3 = 'x';
    int value2;

    do
    {
        scanf("%d%c", &value2, &character3);

        if (character3 != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        else if (value2 < lowerBound || value2 > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound,upperBound);
        }
    } while (value2 < lowerBound || value2 > upperBound);

    return value2;
}
// This function will return a character value within the list of valid characters.

char inputCharOption(char str1[])
{
    int i, count = 0;
    char input;

    do
    {
        scanf(" %c", &input);

        for (i = 0; str1[i] != '\0'; i++)
        {
            if (input == str1[i])
            {
                count++;
            }
        }

        if (count == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", str1);
        }
    } while (count == 0);

    clearInputBuffer();
    return input;
}
// This function will return a C string value containing the number of characters within the range specified by the 2nd and 3rd arguments.

void inputCString(char *str2, int minCharacter, int maxCharacter)
{
    int flag1 = 0;
    char ch = 'x';

    while (flag1 == 0)
    {
        int length = 0;

        while (ch != '\n' && length <= maxCharacter)
        {
            ch = getchar();
            str2[length] = ch;
            length++;
        }

        if (ch == '\n' && length <= (maxCharacter + 1))
        {
            length--;
            str2[length] = '\0';
        }

        else
        {
            str2[maxCharacter] = '\0';
            clearInputBuffer();
        }

        if (minCharacter == maxCharacter && length != minCharacter)
        {
            printf("ERROR: String length must be exactly %d chars: ", minCharacter);
            ch = 'x';
        }
        else if (length < minCharacter || length > maxCharacter)
        {
            if (length > maxCharacter)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxCharacter);
                ch = 'x';
            }
            else if (length < minCharacter)
            {
                printf("ERROR: String length must be between %d and %d chars: ", minCharacter, maxCharacter);
                ch = 'x';
            }
        }
        else
        {
            flag1 = 1;
        }
    }
}

void inputCStringNumbers(char *str, int minCharacter, int maxCharacter)
{
    char ch = 'x';
    int flag11 = 0;

    while (flag11 == 0)
    {
        int length = 0;
        while (ch != '\n' && length <= maxCharacter)
        {

            ch = getchar();
            str[length] = ch;
            length++;
        }
        if (ch == '\n' && length <= (maxCharacter + 1))
        {
            length--;
            str[length] = '\0';
        }

        else
        {
            str[maxCharacter] = '\0';
            clearInputBuffer();
        }

        if (minCharacter == maxCharacter && length != minCharacter)
        {
            printf("Invalid 10-digit number! Number: ");
            ch = 'x';
        }
        else
        {
            flag11 = 1;
        }
    }
}
// This function will display the 10-character digit phone number in formatted series.

void displayFormattedPhone(const char *str3)
{
    int length1 = 0;
    int i;

    while (str3 != NULL && isdigit(str3[length1]))
    {
        length1++;
    }
    if (length1 == 10)
    {
        i = 0;
        printf("(");
        while (i < 3)
        {
            printf("%c", str3[i]);
            i++;
        }
        printf(")");
        while (i < 6)
        {
            printf("%c", str3[i]);
            i++;
        }
        printf("-");
        while (i < 10)
        {
            printf("%c", str3[i]);
            i++;
        }
    }
    else
    {
        printf("(___)___-____");
    }
}


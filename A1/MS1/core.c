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
#include <ctype.h>
// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
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
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
    } while (value2 < lowerBound || value2 > upperBound);

    return value2;
}

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
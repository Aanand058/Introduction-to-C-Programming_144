/*
*****************************************************************************
                          Workshop - #7 (P1)
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

#define max_path_length 70
#define max_lives 10
int main(void)
{
    struct playerInfo
    {
        char playerName;
        int noOfLives;
        int noOfTreasures;
    };
    struct gameInfo
    {
        int pathLength;
        int noOfPositions;
        int noOfMoves;
        int maxNoOfMoves;
        int position[max_path_length];
        int treasure[max_path_length];
    };

    struct playerInfo player;
    struct gameInfo game;

    int i;
    int flag1 = 0, flag2 = 0, flag3 = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playerName);
    for (i = 0; flag1 == 0; i++)
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.noOfLives);
        if (player.noOfLives > max_lives || player.noOfLives < 1)
        {
            printf("     Must be between 1 and 10!\n");
        }
        else
        {
            flag1 = 1;
        }
    }
    printf("Player configuration set-up is complete\n");
    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    for (i = 0; flag2 == 0; i++)
    {
        printf("Set the path length (a multiple of 5 between %d-%d): ",max_lives,max_path_length);
        scanf("%d", &game.pathLength);
        if (game.pathLength % 5 == 0)
        {
            flag2 = 1;
        }
        else
        {
            printf("     Must be a multiple of 5 and between %d-%d!!!\n",max_lives,max_path_length );
        }
    }
    for (i = 0; flag3 == 0; i++)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.noOfMoves);
        game.maxNoOfMoves = ((game.pathLength * 75) / 100);
        if (game.noOfMoves < player.noOfLives || game.noOfMoves > game.maxNoOfMoves)
        {
            printf("    Value must be between %d and %d\n", player.noOfLives, game.maxNoOfMoves);
        }
        else
        {
            flag3 = 1;
        }
    }

    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i = i + 5)
    {

        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.position[i], &game.position[i + 1], &game.position[i + 2], &game.position[i + 3], &game.position[i + 4]);
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    for (i = 0; i < game.pathLength; i = i + 5)
    {

        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasure[i], &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4]);
    }
    printf("TREASURE placement set\n");
    printf("\n");
    printf("GAME configuration set-up is complete...\n");
    printf("\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.playerName);
    printf("   Lives      : %d\n", player.noOfLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength ; i++)
    {
        printf("%d", game.position[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength ; i++)
    {
        printf("%d", game.treasure[i]);
    }
    printf("\n");
    printf("\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return 0;
}
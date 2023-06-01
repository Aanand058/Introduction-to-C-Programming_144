

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

    int dot = 0; // for printing  . : represents a visited location that had neither a bomb nor a treasure
    int bt = 0;  // for printing   &: represents both a bomb and treasure
    int b = 0;   // for printing   ! : represents bombs
    int t = 0;   // for printing   $ : represents treasure

    int treasureFound = 0, movesRemaining;
    int playerMove;
    int counter[max_path_length]; // for storing history of values entered moves
    int value;
    char hipen[max_path_length]; // for printing - : (hyphen) represents undiscovered locations

    int i;
    int j = 0;
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0, flag8 = 0;

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
        printf("Set the path length (a multiple of 5 between %d-%d): ", max_lives, max_path_length);
        scanf("%d", &game.pathLength);
        if (game.pathLength % 5 == 0)
        {
            flag2 = 1;
        }
        else
        {
            printf("     Must be a multiple of 5 and between %d-%d!!!\n", max_lives, max_path_length);
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
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
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
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.position[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasure[i]);
    }
    printf("\n");
    printf("\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    printf("\n");
    for (i = 1; i <= game.pathLength; i++)
    {
        hipen[i] = '-';
    }
    for (i = 0; i < game.pathLength; i++)
    {
        counter[i] = 0;
    }
    movesRemaining = game.noOfMoves;
    printf("  ");
    for (i = 1; i <= game.pathLength; i++)
    {
        printf("%c", hipen[i]);
    }
    printf("\n");
    printf("  ");
    for (i = 1; i <= game.pathLength; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", i / 10);
        }
        else
        {
            printf("|");
        }
    }
    printf("\n");
    printf("  ");
    for (i = 1; i <= game.pathLength; i++)
    {
        printf("%d", i % 10);
    }

    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.noOfLives, treasureFound, movesRemaining);
    printf("+---------------------------------------------------+\n");
    do
    {

        do
        {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &playerMove);

            if (playerMove >= 1 && playerMove <= game.pathLength)
            {

                flag4 = 1;
            }
            else
            {
                printf("  Out of Range!!!\n");
            }

        } while (flag4 == 0);
        printf("\n");

        do
        {

            value = 0;

            for (i = 0; i < game.pathLength && flag8 == 0; i++)
            {

                if (counter[i] == playerMove)
                {

                    value = 1;
                    flag8 = 1;
                }
            }

            counter[j] = playerMove;
            j++;

            if (value == 1)
            {
                printf("===============> Dope! You've been here before!\n");
                flag6 = 1;
            }

            else if (game.position[playerMove - 1] == 0 && game.treasure[playerMove - 1] == 0)
            {
                printf("===============> [.] ...Nothing found here... [.]\n");
                movesRemaining = movesRemaining - 1;
                dot = 1;

                flag6 = 1;
            }
            else if (game.position[playerMove - 1] == 1 && game.treasure[playerMove - 1] == 1)
            {
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                movesRemaining = movesRemaining - 1;
                player.noOfLives = player.noOfLives - 1;
                treasureFound = treasureFound + 1;
                bt = 1;

                if (player.noOfLives <= 0)
                {
                    printf("No more LIVES remaining!\n");
                    flag6 = 1;
                }
            }
            else if (game.position[playerMove - 1] == 1 && game.treasure[playerMove - 1] == 0)
            {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                movesRemaining = movesRemaining - 1;
                player.noOfLives = player.noOfLives - 1;
                b = 1;

                if (player.noOfLives <= 0)
                {
                    printf("\nNo more LIVES remaining!\n");
                    flag6 = 1;
                }
            }
            else if (game.position[playerMove - 1] == 0 && game.treasure[playerMove - 1] == 1)
            {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                movesRemaining = movesRemaining - 1;
                treasureFound = treasureFound + 1;
                t = 1;

                flag6 = 1;
            }
            printf("\n");
        } while (flag6 == 0);

        printf("  ");

        for (i = 1; i <= playerMove; i++)
        {
            if (i == playerMove)
            {
                printf("%c", player.playerName);
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
        printf("  ");
        if (dot == 1)
        {

            hipen[playerMove] = '.';
            for (i = 1; i <= game.pathLength; i++)
            {
                printf("%c", hipen[i]);
            }
        }
        else if (bt == 1)
        {
            hipen[playerMove] = '&';
            for (i = 1; i <= game.pathLength; i++)
            {
                printf("%c", hipen[i]);
            }
        }
        else if (b == 1)
        {
            hipen[playerMove] = '!';
            for (i = 1; i <= game.pathLength; i++)
            {
                printf("%c", hipen[i]);
            }
        }
        else if (t == 1)
        {
            hipen[playerMove] = '$';
            for (i = 1; i <= game.pathLength; i++)
            {
                printf("%c", hipen[i]);
            }
        }
        else
        {
            for (i = 1; i <= game.pathLength; i++)
            {
                printf("%c", hipen[i]);
            }
        }

        bt = 0;
        b = 0;
        t = 0;
        dot = 0;
        printf("\n  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            printf("%d", i % 10);
        }

        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.noOfLives, treasureFound, movesRemaining);
        printf("+---------------------------------------------------+\n");

        if (player.noOfLives == 0 || movesRemaining == 0)
        {
            flag5 = 1;
        }

    } while (flag5 == 0);

    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");

    return 0;
}
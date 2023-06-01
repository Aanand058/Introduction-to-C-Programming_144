







#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cosewic.h"

// Main Program start heading
void mainLogic(struct FileData data[], int max)
{

    int selection, flag = 0;

    while (flag == 0)
    {
        printf("=======================================================\n");
        printf("         Canada Species at Risk Analysis\n");
        printf("            (Data Years: 2010 - 2019)\n");
        printf("=======================================================\n");
        printf("1. View by year (sorted ASCENDING by year)\n");
        printf("2. View by province (sorted DESCENDING by totals)\n");
        printf("3. View by taxon (sorted ASCENDING by totals)\n");
        printf("4. View by province and taxon\n");
        printf("-------------------------------------------------------\n");
        printf("0. Exit\n");
        printf("-------------------------------------------------------\n");
        printf("Selection: ");
        scanf("%d", &selection);

        if (selection == 0)
        {
            printf("\nApplication Terminated!\n");
            flag = 1;
        }
        else if (selection > 0 && selection <= 4)
        {
            if (selection == 1)
            {
                year(data, max);
            }
            if (selection == 2)
            {
                province(data, max);
            }
            if (selection == 3)
            {
                taxon(data, max);
            }
            if (selection == 4)
            {
                taxonprovince(data, max);
            }
        }
        else
        {
            printf("\nInvalid menu selection!\n\n");
        }
    }
}

void year(struct FileData data[], int max)
{

    printf("\n");
    printf("YEAR EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("---- ------- ---------- ---------- ---------- ------- ---------\n");
    statusCal(data, max); // calling for calculation of data accordingly 
}

// Function for calculation of data by year
void statusCal(struct FileData data[], int max)
{
    struct status status;
    struct totalStatus totalStatus;
    char EXTINCT[STATUS_LEN] = "EXTINCT";
    char EXTIRPATED[STATUS_LEN] = "EXTIRPATED";
    char ENDANGERED[STATUS_LEN] = "ENDANGERED";
    char THREATENED[STATUS_LEN] = "THREATENED";
    char CONCERN[STATUS_LEN] = "SPECIAL CONCERN";
    totalStatus.totalconcern = 0;
    totalStatus.totalendangered = 0;
    totalStatus.totalextinct = 0;
    totalStatus.totalthreatened = 0;
    totalStatus.totalextirpated = 0;
    totalStatus.alltotal = 0;

    int year = 2010;
    int i, j; // Iteration variables

    for (j = 0; j <= 9; j++)
    {
        status.extinct = 0;
        status.extirpated = 0;
        status.endangered = 0;
        status.threatened = 0;
        status.concern = 0;
        status.total1 = 0;
        for (i = 0; i < max; i++)
        {

            if (data[i].year == year)
            {
                if (strcmp(data[i].status, EXTINCT) == 0)
                {
                    status.extinct = status.extinct + data[i].count;
                    totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
                }
                if (strcmp(data[i].status, EXTIRPATED) == 0)
                {
                    status.extirpated = status.extirpated + data[i].count;
                    totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
                }
                if (strcmp(data[i].status, ENDANGERED) == 0)
                {
                    status.endangered = status.endangered + data[i].count;
                    totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
                }
                if (strcmp(data[i].status, THREATENED) == 0)
                {
                    status.threatened = status.threatened + data[i].count;
                    totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
                }
                if (strcmp(data[i].status, CONCERN) == 0)
                {
                    status.concern = status.concern + data[i].count;
                    totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
                }
                status.total1 = status.extinct + status.extirpated + status.endangered + status.threatened + status.concern;
            }
            totalStatus.alltotal = totalStatus.totalextinct + totalStatus.totalextirpated + totalStatus.totalendangered + totalStatus.totalconcern + totalStatus.totalthreatened;
        }

        printf("%d    %d       %d       %d       %d    %d     %d\n", year, status.extinct, status.extirpated, status.endangered, status.threatened, status.concern, status.total1);
        year++;
    }

    printf("     ------- ---------- ---------- ---------- ------- ---------\n");
    printf("       %d      %d      %d      %d   %d    %d  \n\n", totalStatus.totalextinct, totalStatus.totalextirpated, totalStatus.totalendangered, totalStatus.totalthreatened, totalStatus.totalconcern, totalStatus.alltotal);
}

void province(struct FileData data[], int max)
{
    printf("\nPROVINCE             EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");
    struct status province;
    struct totalStatus totalStatus;
    int i;

    char Ontario[PROVINCE_LEN] = "ON"; // creating separate each variables so that the values can match with their respective corresponding data correctly. 
    char Nunavut[PROVINCE_LEN] = "NU";
    char Manitoba[PROVINCE_LEN] = "MB";
    char YuokanTerritory[PROVINCE_LEN] = "YT";
    char NewBrunswick[PROVINCE_LEN] = "NB";
    char Quebec[PROVINCE_LEN] = "QC";
    char Saskatchewan[PROVINCE_LEN] = "SK";
    char NovaScotia[PROVINCE_LEN] = "NS";
    char Newfoundland[PROVINCE_LEN] = "NL";
    char Alberta[PROVINCE_LEN] = "AB";
    char PrinceEdwardIsland[PROVINCE_LEN] = "PE";
    char BritishColumbia[PROVINCE_LEN] = "BC";
    char NorthestTerritory[PROVINCE_LEN] = "NT";
    char EXTINCT[STATUS_LEN] = "EXTINCT";
    char EXTIRPATED[STATUS_LEN] = "EXTIRPATED";
    char ENDANGERED[STATUS_LEN] = "ENDANGERED";
    char THREATENED[STATUS_LEN] = "THREATENED";
    char CONCERN[STATUS_LEN] = "SPECIAL CONCERN";
    totalStatus.totalextinct = 0;
    totalStatus.totalextirpated = 0;
    totalStatus.totalendangered = 0;
    totalStatus.totalthreatened = 0;
    totalStatus.totalconcern = 0;
    totalStatus.alltotal = 0;

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, Ontario) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Ontario                 %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, Nunavut) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Nunavut                 %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, Manitoba) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Manitoba                %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, YuokanTerritory) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Yukon Territory         %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, NewBrunswick) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("New Brunswick           %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, Quebec) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Quebec                  %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, Saskatchewan) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Saskatchewan            %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, NovaScotia) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Nova Scotia             %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, Newfoundland) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Newfoundland            %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, Alberta) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Alberta                 %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, PrinceEdwardIsland) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Prince Edward Island    %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, BritishColumbia) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("British Columbia        %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);

    province.extinct = 0;
    province.extirpated = 0;
    province.endangered = 0;
    province.threatened = 0;
    province.concern = 0;
    province.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].province, NorthestTerritory) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                province.extinct = province.extinct + data[i].count;
                totalStatus.totalextinct = totalStatus.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                province.extirpated = province.extirpated + data[i].count;
                totalStatus.totalextirpated = totalStatus.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                province.endangered = province.endangered + data[i].count;
                totalStatus.totalendangered = totalStatus.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                province.threatened = province.threatened + data[i].count;
                totalStatus.totalthreatened = totalStatus.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                province.concern = province.concern + data[i].count;
                totalStatus.totalconcern = totalStatus.totalconcern + data[i].count;
            }
            province.total1 = province.extinct + province.extirpated + province.endangered + province.threatened + province.concern;
        }
    }

    printf("Northwest Territory     %d       %d       %d       %d    %d     %d\n", province.extinct, province.extirpated, province.endangered, province.threatened, province.concern, province.total1);
    totalStatus.alltotal = totalStatus.totalextinct + totalStatus.totalextirpated + totalStatus.totalendangered + totalStatus.totalthreatened + totalStatus.totalconcern;
    printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");
    printf("                       %d      %d      %d      %d   %d    %d\n\n", totalStatus.totalextinct, totalStatus.totalextirpated, totalStatus.totalendangered, totalStatus.totalthreatened, totalStatus.totalconcern, totalStatus.alltotal);
}

void taxon(struct FileData data[], int max)
{
    printf("\nTAXON           EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("--------------- ------- ---------- ---------- ---------- ------- ---------\n");

    struct status taxon;
    struct totalStatus totalStatus1;

    char Molluscs[STATUS_LEN] = "Molluscs";
    char Lichens[STATUS_LEN] = "Lichens";
    char Amphibians[STATUS_LEN] = "Amphibians";
    char VascularPlants[STATUS_LEN] = "Vascular Plants";
    char Reptiles[STATUS_LEN] = "Reptiles";
    char Mammals[STATUS_LEN] = "Mammals";
    char Arthropods[STATUS_LEN] = "Arthropods";
    char Mosses[STATUS_LEN] = "Mosses";
    char Birds[STATUS_LEN] = "Birds";
    char Fishes[STATUS_LEN] = "Fishes";

    char EXTINCT[STATUS_LEN] = "EXTINCT";
    char EXTIRPATED[STATUS_LEN] = "EXTIRPATED";
    char ENDANGERED[STATUS_LEN] = "ENDANGERED";
    char THREATENED[STATUS_LEN] = "THREATENED";
    char CONCERN[STATUS_LEN] = "SPECIAL CONCERN";
    totalStatus1.totalextinct = 0;
    totalStatus1.totalextirpated = 0;
    totalStatus1.totalendangered = 0;
    totalStatus1.totalthreatened = 0;
    totalStatus1.totalconcern = 0;
    totalStatus1.alltotal = 0;
    int i;
    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;

    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, Molluscs) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Molluscs           %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);

    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, Lichens) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Lichens            %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);

    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, Amphibians) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Amphibians         %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);

    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, VascularPlants) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Vascular Plants    %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);

    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, Reptiles) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Reptiles           %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);

    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, Mammals) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Mammals            %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);

    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, Arthropods) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Arthropods         %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);

    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, Mosses) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Mosses             %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);

    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, Birds) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Birds              %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);

    taxon.extinct = 0;
    taxon.extirpated = 0;
    taxon.endangered = 0;
    taxon.threatened = 0;
    taxon.concern = 0;
    taxon.total1 = 0;
    for (i = 0; i < max; i++)
    {
        if (strcmp(data[i].taxon, Fishes) == 0)
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxon.extinct = taxon.extinct + data[i].count;
                totalStatus1.totalextinct = totalStatus1.totalextinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxon.extirpated = taxon.extirpated + data[i].count;
                totalStatus1.totalextirpated = totalStatus1.totalextirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxon.endangered = taxon.endangered + data[i].count;
                totalStatus1.totalendangered = totalStatus1.totalendangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxon.threatened = taxon.threatened + data[i].count;
                totalStatus1.totalthreatened = totalStatus1.totalthreatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxon.concern = taxon.concern + data[i].count;
                totalStatus1.totalconcern = totalStatus1.totalconcern + data[i].count;
            }
            taxon.total1 = taxon.extinct + taxon.extirpated + taxon.endangered + taxon.threatened + taxon.concern;
        }
    }
    printf("Fishes             %d       %d       %d       %d    %d     %d\n", taxon.extinct, taxon.extirpated, taxon.endangered, taxon.threatened, taxon.concern, taxon.total1);
    totalStatus1.alltotal = totalStatus1.totalextinct + totalStatus1.totalextirpated + totalStatus1.totalendangered + totalStatus1.totalthreatened + totalStatus1.totalconcern;

    printf("                ------- ---------- ---------- ---------- ------- ---------\n");
    printf("                  %d      %d      %d      %d   %d    %d\n\n", totalStatus1.totalextinct, totalStatus1.totalextirpated, totalStatus1.totalendangered, totalStatus1.totalthreatened, totalStatus1.totalconcern, totalStatus1.alltotal);
}

void taxonprovince(struct FileData data[], int max)
{

    int provinceSelection, taxonSelection;
    struct status taxonprovince;
    struct province1 provinceName[NO_OF_STATES +1] = {{"AB"}, {"BC"}, {"MB"}, {"NB"}, {"NL"}, {"NS"}, {"NT"}, {"NU"}, {"ON"}, {"PE"}, {"QC"}, {"SK"}, {"YT"}};
    struct taxon1 taxonName[NO_OF_STATES] = {{"Mammals"}, {"Birds"}, {"Reptiles"}, {"Amphibians"}, {"Fishes"}, {"Arthropods"},{"Molluscs"}, {"Vascular Plants"}, {"Mosses"}, {"Lichens"}};
    struct province1 provinceFullName[PROVINCE_NAME] = {{"Alberta"},{"British Columbia"},{"Manitoba"},{"New Brunswick"},{"Newfoundland"},{"Nova Scotia"},{"Northwest Territory"},{"Nunavut"},{"Ontario"},{"Prince Edward Island"},{"Quebec"},{"Saskatchewan"},{"Yukon Territory"}};
    int i;
    int flag = 0, flag2 = 0;

    char EXTINCT[STATUS_LEN] = "EXTINCT";
    char EXTIRPATED[STATUS_LEN] = "EXTIRPATED";
    char ENDANGERED[STATUS_LEN] = "ENDANGERED";
    char THREATENED[STATUS_LEN] = "THREATENED";
    char CONCERN[STATUS_LEN] = "SPECIAL CONCERN";

    taxonprovince.extinct = 0;
    taxonprovince.extirpated = 0;
    taxonprovince.endangered = 0;
    taxonprovince.threatened = 0;
    taxonprovince.concern = 0;
    taxonprovince.total1 = 0;

    for (i = 0; flag == 0; i++)
    {
        printf("Choose a Province\n");
        printf("----------------------------------\n");
        printf(" 1) AB (Alberta)\n");
        printf(" 2) BC (British Columbia)\n");
        printf(" 3) MB (Manitoba)\n");
        printf(" 4) NB (New Brunswick)\n");
        printf(" 5) NL (Newfoundland)\n");
        printf(" 6) NS (Nova Scotia)\n");
        printf(" 7) NT (Northwest Territories)\n");
        printf(" 8) NU (Nunavut)\n");
        printf(" 9) ON (Ontario)\n");
        printf("10) PE (Prince Edward Island)\n");
        printf("11) QC (Quebec)\n");
        printf("12) SK (Saskatchewan)\n");
        printf("13) YT (Yukon Territory)\n");
        printf("Selection: ");
        scanf("%d", &provinceSelection);

        printf("\n");
        if (provinceSelection <= 0 || provinceSelection > 13)
        {
            printf("Invalid menu selection!\n\n");
        }
        else
        {
            flag = 1;
        }
    }

    for (i = 0; flag2 == 0; i++)
    {

        printf("Choose a Taxon\n");
        printf("---------------\n");
        printf(" 1) Mammals\n");
        printf(" 2) Birds\n");
        printf(" 3) Reptiles\n");
        printf(" 4) Amphibians\n");
        printf(" 5) Fishes\n");
        printf(" 6) Arthropods\n");
        printf(" 7) Molluscs\n");
        printf(" 8) Vascular Plants\n");
        printf(" 9) Mosses\n");
        printf("10) Lichens\n");
        printf("Selection: ");
        scanf("%d", &taxonSelection);
        printf("\n");
        if (taxonSelection <= 0 || taxonSelection > 10)
        {
            printf("Invalid menu selection!\n\n");
        }
        else
        {
            flag2 = 1;
        }
    }

    printf("*** Data filtered by PROVINCE and TAXON ***\n");
    printf("\n");
    printf("    Province: %s\n", provinceFullName[provinceSelection - 1].name);
    printf("    Taxon   : %s\n\n", taxonName[taxonSelection - 1].taxname);
    taxonprovinceheader();

    for (i = 0; i < max; i++)
    {
        if ((strcmp(data[i].province, provinceName[provinceSelection - 1].name) == 0) && (strcmp(data[i].taxon, taxonName[taxonSelection - 1].taxname) == 0))
        {
            if (strcmp(data[i].status, EXTINCT) == 0)
            {
                taxonprovince.extinct = taxonprovince.extinct + data[i].count;
            }
            if (strcmp(data[i].status, EXTIRPATED) == 0)
            {
                taxonprovince.extirpated = taxonprovince.extirpated + data[i].count;
            }
            if (strcmp(data[i].status, ENDANGERED) == 0)
            {
                taxonprovince.endangered = taxonprovince.endangered + data[i].count;
            }
            if (strcmp(data[i].status, THREATENED) == 0)
            {
                taxonprovince.threatened = taxonprovince.threatened + data[i].count;
            }
            if (strcmp(data[i].status, CONCERN) == 0)
            {
                taxonprovince.concern = taxonprovince.concern + data[i].count;
            }
            taxonprovince.total1 = taxonprovince.extinct + taxonprovince.extirpated + taxonprovince.endangered + taxonprovince.threatened + taxonprovince.concern;
        }
    }
    printf("    %d        %d        %d        %d     %d      %d\n\n", taxonprovince.extinct, taxonprovince.extirpated, taxonprovince.endangered, taxonprovince.threatened, taxonprovince.concern, taxonprovince.total1);
}

void taxonprovinceheader(void)
{
    printf("EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
    printf("------- ---------- ---------- ---------- ------- ---------\n");
}

//  Importing data from file data.txt into an struct FileData array
int loadData(const char *datafile, struct FileData data[], int max)
{
    int i = 0; 
    int count = 0;
    
    int record;
    FILE *fp = NULL;

    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        fscanf(fp, "%*[^\n]");
        while (i < max)
        {
            record = fscanf(fp, "%4d,%[^,],%[^,],%2d,%[^\n]", &data[i].year, data[i].taxon, data[i].status, &data[i].count, data[i].province);

            if (record > 0)
            {
                count++;
            }
            i++;
        }
        fclose(fp);
    }
    return count;
};

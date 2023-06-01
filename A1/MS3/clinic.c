

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include <string.h>

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
    int selection;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0, records = 0;
    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            records = 1;
        }
    }
    if (records != 1)
    {
        printf("*** No records found ***\n\n");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int selectionOption = 0;
    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &selectionOption);
        printf("\n");

        if (selectionOption == 1)
        {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (selectionOption == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (selectionOption != 0);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i, index;
    int location = 0;
    int value;
    for (i = 0; i < max && location == 0; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            location = 1;
            index = i;
        }
    }
    if (location == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        value = nextPatientNumber(patient, max);
        patient[index].patientNumber = value;
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int patNumber, arrayIndex, edit;
    printf("Enter the patient number: ");
    scanf("%d", &patNumber);
    printf("\n");
    edit = findPatientIndexByPatientNum(patNumber, patient, max);
    if (edit != -1)
    {

        arrayIndex = edit;
        menuPatientEdit(patient + arrayIndex);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int patNumber2, arrayindex2, remove;
    int flag = 0;
    int i;

    char choice;
    char ch;
    printf("Enter the patient number: ");
    scanf("%d", &patNumber2);
    printf("\n");
    remove = findPatientIndexByPatientNum(patNumber2, patient, max);
    if (remove != -1)
    {
        arrayindex2 = remove;
        printf("Name  : %s\n", patient[arrayindex2].name);
        printf("Number: %05d\n", patient[arrayindex2].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[arrayindex2].phone.number);
        printf(" (%s)", patient[arrayindex2].phone.description);
        printf("\n\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");

        for (i = 0; flag == 0; i++)
        {
            scanf(" %c%c", &choice, &ch);
            if ((choice == 'N' || choice == 'n') && (ch == '\n'))
            {
                printf("Operation aborted.\n\n");
                flag = 1;
                clearInputBuffer();
            }
            else if ((choice == 'y' || choice == 'Y') && (ch == '\n'))
            {

                patient[arrayindex2].patientNumber = 0;
                printf("Patient record has been removed!\n\n");
                flag = 1;
            }
            else
            {
                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// function for sorting the data 
void sort(struct Appointment appoints[], int max)
{
    struct Appointment appoint2;
    int i, j;
    for (i = 0; i < max; i++)
    {
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60) + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.min;
    }
    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appoints[j].time.min > appoints[j + 1].time.min)
            {
                appoint2 = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = appoint2;
            }
        }
    }
    for (i = 0; i < max; i++)
    {
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60) - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }
}
// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData *data)
{
    int i;
    int j;

    sort(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData *data)
{
    int monthEnd = 31;
    struct Date date;
    int i, j;

    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    printf("Day (1-");
    if (date.month == 2)
    {
        monthEnd = 28;
    }

    if (date.month == 4 || date.month == 9 || date.month == 11)
    {
        monthEnd = 30;
    }

    if (date.year % 4 == 0 && date.month == 2)
    {
        monthEnd = 29;
    }
    printf("%d)  : ", monthEnd);
    date.day = inputIntRange(1, monthEnd);
    printf("\n");

    sort(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(&date, 0);

    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }
    printf("\n");
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment *appointment, int maxAppointments, struct Patient *patient, int maxPatients)
{
    struct Date date;
    struct Time time;
    int monthEnd = 31;
    int patientNumber1;
    int index1;
    int nonEmptyElement = 1;

    printf("Patient Number: ");
    patientNumber1 = inputIntPositive();
    index1 = findPatientIndexByPatientNum(patientNumber1, patient, maxPatients);

    if (index1 >= 0)
    {
        while (nonEmptyElement == 1)
        {
            printf("Year        : ");
            date.year = inputIntPositive();

            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);

            printf("Day (1-");
            if (date.month == 2)
            {
                monthEnd = 28;
            }
            if (date.month == 4 || date.month == 9 || date.month == 11)
            {
                monthEnd = 30;
            }

            if (date.year % 4 == 0 && date.month == 2)
            {
                monthEnd = 29;
            }

            printf("%d)  : ", monthEnd);
            date.day = inputIntRange(1, monthEnd);

            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            if (timeSlot(date, time, appointment, maxAppointments))
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else
            {
                while ((time.hour < START_HOUR || time.hour > END_HOUR) || (time.hour == END_HOUR && time.min > 0) || (time.min % MINUTE_INTERVAL != 0))
                {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);
                }
                nonEmptyElement = 0;
            }
        }
        index1 = availableAppointment(appointment, maxAppointments);
        appointment[index1].date = date;
        appointment[index1].time = time;
        appointment[index1].patientNumber = patientNumber1;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    return;
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment *appointment, int maxAppointments, struct Patient *patient, int maxPatients)
{
    struct Date date;
    int index2;
    int patientNumber2;
    int MonthEnd1 = 31;
    int appointmentIndex;

    printf("Patient Number: ");
    patientNumber2 = inputIntPositive();
    index2 = findPatientIndexByPatientNum(patientNumber2, patient, maxPatients);
    if (index2 >= 0)
    {
        printf("Year        : ");
        date.year = inputIntPositive();

        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);

        printf("Day (1-");
        if (date.month == 2)
        {
            MonthEnd1 = 28;
        }
        if (date.month == 4 || date.month == 9 || date.month == 11)
        {
            MonthEnd1 = 30;
        }
        if (date.year % 4 == 0 && date.month == 2)
        {
            MonthEnd1 = 29;
        }
        printf("%d)  : ", MonthEnd1);
        date.day = inputIntRange(1, MonthEnd1);
        appointmentIndex = validationApp(patientNumber2, date, appointment, maxAppointments);

        if (appointmentIndex >= 0)
        {
            printf("\n");
            displayPatientData(&patient[index2], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y')
            {
                appointment[appointmentIndex].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }
            else
            {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

int timeSlot(struct Date date, struct Time time, struct Appointment *appointment, int maxAppointments)
{
    int i;
    int timeSlot = 0;
    for (i = 0; i < maxAppointments; i++)
    {
        if (date.year == appointment[i].date.year && date.month == appointment[i].date.month && date.day == appointment[i].date.day && time.hour == appointment[i].time.hour && time.min == appointment[i].time.min)
        {
            timeSlot = 1;
        }
    }
    return timeSlot;
}

int availableAppointment(struct Appointment *appointment, int maxAppointments)
{
    int i = 0;
    int available = 0;
    while (available == 0 && i < maxAppointments)
    {
        if (appointment[i].patientNumber < 1)
        {
            available = 1;
        }
        i++;
    }
    return i;
}
int validationApp(int patientNumber, struct Date date, struct Appointment *appointment, int maxAppointments)
{
    int i = 0;
    int validation = 0;
    while (validation == 0 && i < maxAppointments)
    {
        if ((appointment[i].patientNumber == patientNumber) && (appointment[i].date.day == date.day) && (appointment[i].date.month == date.month) && (appointment[i].date.year == date.year))
        {
            validation = 1;
        }
        i++;
    }
    return i - 1;
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patNumber3, arrayindex3, search;
    printf("Search by patient number: ");
    scanf("%d", &patNumber3);
    printf("\n");
    search = findPatientIndexByPatientNum(patNumber3, patient, max);
    if (search != -1)
    {
        arrayindex3 = search;
        printf("Name  : %s\n", patient[arrayindex3].name);
        printf("Number: %05d\n", patient[arrayindex3].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[arrayindex3].phone.number);
        printf(" (%s)", patient[arrayindex3].phone.description);
        printf("\n\n");
    }

    else
    {
        printf("*** No records found ***\n\n");
    }
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, record2 = 0;
    char phoneNumber[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    // scanf("%s", phoneNumber);
    printf("\n");

    displayPatientTableHeader();

    for (i = 0; i < max + 1; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            record2++;
            // clearInputBuffer();
            // suspend();
        }
    }
    printf("\n");

    if (record2 == 0)
    {
        printf("*** No records found ***\n\n");
    }
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int nextPatNum, highestpatNum, i;
    highestpatNum = patient[0].patientNumber;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > highestpatNum)
        {
            highestpatNum = patient[i].patientNumber;
        }
    }

    nextPatNum = highestpatNum + 1;
    return nextPatNum;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }

    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient *patient)
{

    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone *phone)
{
    int selection3;
    char inputNumber[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection3 = inputIntRange(1, 4);
    printf("\n");

    switch (selection3)
    {

    case 1:
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(inputNumber, 10, 10);
        strcpy(phone->number, inputNumber);
        printf("\n");
        break;

    case 2:
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(inputNumber, 10, 10);
        strcpy(phone->number, inputNumber);
        printf("\n");
        break;

    case 3:
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(inputNumber, 10, 10);
        strcpy(phone->number, inputNumber);
        printf("\n");
        break;

    case 4:
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        *phone->number = '\0';
        break;

    default:
        printf("Error: \n");
        break;
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char *datafile, struct Patient patients[], int max)
{
    int i = 0;
    int flag = 0;
    FILE *fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        i = 0;
        while (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description,
                      patients[i].phone.number) != EOF &&
               flag == 0)
        {
            i++;
            if (i >= max)
            {
                flag = 1;
            }
            
        }
        fclose(fp);
        fp = NULL;
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }
    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char *datafile, struct Appointment appoints[], int max)
{
    int i = 0;
    int endFile = 0;

    FILE *fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        for (i = 0; i < max && !feof(fp); i++)
        {
            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);

            if (!feof(fp)) // search for the end of file is reached 
            {
                endFile++;
            }
        }
        fclose(fp);
    }
    else
    {
        printf("ERROR: File could not be read\n");
    }
    return endFile;
}
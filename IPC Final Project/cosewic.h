



// macro defining
#define PROVINCE_LEN 3
#define TAXON_LEN 20
#define STATUS_LEN 20
#define PROVINCE_NAME 30
#define NO_OF_STATES 13

// STRUCTURES
struct FileData // structure for storing data of data.txt file
{
    int year;
    char taxon[TAXON_LEN];
    char status[STATUS_LEN];
    int count;
    char province[PROVINCE_LEN];
};

struct status // structure for storing the calculated count of species
{
    int extinct;
    int threatened;
    int concern;
    int endangered;
    int extirpated;
    int total1;
};

struct totalStatus // structure for storing the calculated total count of species
{
    int totalextinct;
    int totalthreatened;
    int totalconcern;
    int totalendangered;
    int totalextirpated;
    int alltotal;
};

struct province1 // structure for holding name of provinces
{
    char name[PROVINCE_NAME];
};

struct taxon1 // structure for holding name of taxons 
{
    char taxname[PROVINCE_NAME];
};

// Reading data from data.txt files
int loadData(const char *datafile, struct FileData data[], int max);

// Starting of the program for option selection
void mainLogic(struct FileData data[], int max);

// function to display sorted data by year
void year(struct FileData data[], int max);

// function to display sorted data by province
void province(struct FileData data[], int max);

// function to display sorted data by taxon
void taxon(struct FileData data[], int max);

// function to display specific selected data of province and taxon
void taxonprovince(struct FileData data[], int max);

// function to calculate the year data
void statusCal(struct FileData data[], int max);

// function to display the header table of taxona province
void taxonprovinceheader(void);
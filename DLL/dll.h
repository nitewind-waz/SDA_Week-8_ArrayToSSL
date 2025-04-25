#ifndef dll_h
#define dll_h
#define MAX_NAME 50

typedef struct Citizen* address;
typedef struct Citizen {
    char nm[MAX_NAME];
    address q;
} Citizen;

typedef struct City {
    char kt[MAX_NAME];        
    Citizen* p;              
    struct City* next;
    struct City* prev;
} City;

// Function prototypes
City* createCity(char* city);
void insertCity(City** head, char* city);
void deleteCity(City** head, char* city);
City* findCity(City* head, char* city);
void displayAllCities(City* head);

void addName(City* head, char* city, char* name);
void deleteName(City* head, char* city, char* name);
void displayNames(Citizen* head);
void freeNameList(Citizen* head);

#endif


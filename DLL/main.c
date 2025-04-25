#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

int main() {
    City* cityList = NULL;
    int choice;
    char city[MAX_NAME], name[MAX_NAME];

    do {
        printf("\n||CITY AND CITIZENS||\n\n");
        printf("1. Add a City\n");
        printf("2. Add a Citizen to a City\n");
        printf("3. Delete a City\n");
        printf("4. Delete a Citizen Name from a City\n");
        printf("5. Display All Current Cities and Citizen Names\n");
        printf("6. Exit\n");
        printf("Enter a Desired Choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline after number input

        switch (choice) {
            case 1:
                printf("Enter a city name to add: ");
                fgets(city, MAX_NAME, stdin);
                city[strcspn(city, "\n")] = '\0';  // Remove newline
                insertCity(&cityList, city);
                break;

            case 2:
                printf("Enter a city name: ");
                fgets(city, MAX_NAME, stdin);
                city[strcspn(city, "\n")] = '\0';

                printf("Enter the name of the citizen to add: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';

                addName(cityList, city, name);
                break;

            case 3:
                printf("Enter a city name to be deleted: ");
                fgets(city, MAX_NAME, stdin);
                city[strcspn(city, "\n")] = '\0';

                deleteCity(&cityList, city);
                break;

            case 4:
                printf("Enter a city name: ");
                fgets(city, MAX_NAME, stdin);
                city[strcspn(city, "\n")] = '\0';

                printf("Enter a citizen name to be deleted: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';

                deleteName(cityList, city, name);
                break;

            case 5:
                displayAllCities(cityList);
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please Try Again...\n");
        }

    } while (choice != 6);

    return 0;
}

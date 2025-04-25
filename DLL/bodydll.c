#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

City* createCity(char* city) {
    City* newCity = (City*)malloc(sizeof(City));
    strcpy(newCity->kt, city);
    newCity->p = NULL;
    newCity->next = NULL;
    newCity->prev = NULL;
    return newCity;
}
//creates an empty list of cities and citizens
// this function creates a new city node and initializes it with the given city name.


void insertCity(City** head, char* city) {

    // we have to first check if the city added already exists in the list
    if (findCity(*head, city)) { //which means if city already exists
        printf("City '%s' already exists.\n", city);
        return;
    }

    // if the city does not exist, the user is able to add the city name to the list
    City* newCity = createCity(city);
    if (*head == NULL) {
        *head = newCity;
    } else {
        City* tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newCity;
        newCity->prev = tail;
    }
    printf("\nCity '%s' has been added.\n", city);
}

void deleteCity(City** head, char* city) {
    City* search = findCity(*head, city);
    if (!search) {
        printf("\nCity '%s' has not been found.\n", city);
        return;
    }

    if (search->prev != NULL)
        search->prev->next = search->next;
    else
        *head = search->next;

    if (search->next != NULL)
        search->next->prev = search->prev;

    freeNameList(search->p);
    free(search);
    printf("\nCity '%s' and all its names have been deleted.\n", city);
}

City* findCity(City* head, char* city) {
    while (head != NULL) {
        if (strcmp(head->kt, city) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void addName(City* head, char* city, char* name) {
    City* c = findCity(head, city);
    if (!c) {
        printf("\nCity '%s' has not been found.\n", city);
        return;
    }

    Citizen* newNode = (Citizen*)malloc(sizeof(Citizen));
    strcpy(newNode->nm, name);
    newNode->q = c->p;
    c->p = newNode;
    printf("\nName '%s' has been added to the city '%s'.\n", name, city);
}

void deleteName(City* head, char* city, char* name) {
    City* c = findCity(head, city);
    if (!c) {
        printf("\nCity '%s' has not been found.\n", city);
        return;
    }

    Citizen *curr = c->p, *prev = NULL;
    while (curr != NULL && strcmp(curr->nm, name) != 0) {
        prev = curr;
        curr = curr->q;
    }

    if (!curr) {
        printf("\nName '%s' not been found in the city '%s'.\n", name, city);
        return;
    }

    if (prev == NULL)
        c->p = curr->q;
    else
        prev->q = curr->q;

    free(curr);
    printf("\nName '%s' has been deleted from the city '%s'.\n", name, city);
}

void displayAllCities(City* head) {
    printf("\n||Cities and Citizen Names|| \n");
    while (head != NULL) {
        printf("City: %s\n", head->kt);
        displayNames(head->p);
        head = head->next;
    }
    printf("------------------------\n");
}

void displayNames(Citizen* head) {
    while (head != NULL) {
        printf("  - %s\n", head->nm);
        head = head->q;
    }
}

void freeNameList(Citizen* head) {
    Citizen* temp;
    while (head != NULL) {
        temp = head;
        head = head->q;
        free(temp);
    }
}



#include "namesarchive.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static Person archive[MAX_PERSONS];
static int numPersons = 0;

// Fügt eine Person hinzu.
int addPerson(const Person newPerson)
{
    if(numPersons < MAX_PERSONS)
    {
        archive[numPersons] = newPerson;
        numPersons++;
        return 1;
    }
    return 0;
}

// Entfernt eine Person aus dem Archiv, nur wenn Name und Alter in einem Eintrag übereinstimmen.
int removePerson(const Person person)
{
    int idx = -1;
    for(int i = 0; i < numPersons; i++) {
        if(archive[i].age == person.age && strcmp(archive[i].name, person.name) == 0) {
            idx = i;
            break;
        }
    }

    if(idx == -1)
        return 0;

    for(int i = idx; i < numPersons-1; i++)
        archive[i] = archive[i+1];

    numPersons--;

    return 1;
}

// Gibt die enthaltenen Personen zeilenweise in der Form "<Name> ist <Alter> Jahre alt." aus.
void printPersons()
{
    for(int i = 0; i < numPersons; i++) {
        printf("%s ist %d Jahre alt.\n", archive[i].name, archive[i].age);
    }
}

int compareByAge(const void* p1, const void* p2)
{
    return ((Person*)p1)->age - ((Person*)p2)->age;
}

int compareByName(const void* p1, const void* p2)
{
    Person* pers1 = (Person*)p1; // optional!
    return strcmp(pers1->name, ((Person*)p2)->name); 
}

// Sortiert das Archiv je nach Sortierungsart entweder nach Name und bei Übereinstimmung nach Alter oder umgekehrt.
void sortPersons(SortType type)
{
    if(type == SORT_BY_AGE)
        qsort(archive, numPersons, sizeof(Person), compareByAge);
    else if(type == SORT_BY_NAME)
        qsort(archive, numPersons, sizeof(Person), compareByName);
}
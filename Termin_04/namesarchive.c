#include "namesarchive.h"
#include <stdio.h>
#include <string.h>

static Person people[MAX_PERSONS];
static int count = 0;

int addPerson(const Person newPerson)
{
    if(count < MAX_PERSONS) {
        people[count] = newPerson;
        count++;
        return 1;
    }
    return 0;
}

int removePerson(const Person person)
{
    for(int i = 0; i < count; i++) {
        if(people[i].age == person.age && strcmp(people[i].name, person.name) == 0) {
            for(int j = i; j < count-1; j++) {
                people[j] = people[j+1];
            }
            count--;
            return 1;
        }
    }
    return 0;
}

void printPersons()
{
    for(int i = 0; i < count; i++) {
        const Person *p = &people[i];

        printf("%s ist %d Jahre alt.\n", p->name, p->age);
    }
}

void swap(Person *p1, Person *p2)
{
    Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sortPersons(SortType type)
{
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count-1; j++) {
            if(type == SORT_BY_AGE) {
                if(people[j].age > people[j+1].age) {
                    swap(&people[j], &people[j+1]);
                }
            }
            else if(type == SORT_BY_NAME) {
                if(strcmp(people[j].name, people[j+1].name) > 0) {
                    swap(&people[j], &people[j+1]);
                } 
            }
        }
    }
}

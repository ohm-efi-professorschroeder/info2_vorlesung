#include "namesarchive.h"

#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char** names = NULL;
static int numNames = 0;

int addName(const char *name)
{
    // Schritt 1: String kopieren
    char* myName = (char*) malloc(strlen(name)+1);
    if(myName == NULL) {
        return 0;
    }
    strncpy(myName, name, strlen(name)+1);

    // Schritt 2: Kopie abspeichern
    names = (char**) realloc(names, (numNames+1) * sizeof(char*));
    if(names == NULL) {
        return 0;
    }
    names[numNames] = myName;

    numNames++;
    return 1;
}

int removeName(const char *name)
{
    for(int i = 0; i < numNames; i++) {
        if(strcmp(names[i], name) == 0) {
            free(names[i]);
            for(int j = i; j < numNames-1; j++) {
                names[j] = names[j+1];
            }
            numNames--;
            return 1;
        }
    }
    return 0;
}

void clearArchive()
{
    for(int i = 0; i < numNames; i++) {
        free(names[i]);
    }
    free(names);
}

void swap(char **p1, char **p2)
{
    char* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sortNames()
{
    for(int i = 0; i < numNames; i++) {
        for(int j = 0; j < numNames-1; j++) {
            if(strcmp(names[j], names[j+1]) > 0) {
                swap(&names[j], &names[j+1]);
            } 
        }
    }
}

void printNames()
{
    for(int i = 0; i < numNames; i++) {
        printf("%s\n", names[i]);
    }
}
#include "namesarchive.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static char** names = 0;
static int numNames = 0;

// Fügt einen Namen hinzu. Im Fehlerfall (kein Speicher mehr) soll 0, ansonsten 1 zurückgegeben werden.
int addName(const char *name)
{
    char* nameCopy = malloc(strlen(name)+1);
    if(!nameCopy)
        return 0;
    strcpy(nameCopy, name);
    

    names = realloc(names, (numNames+1) * sizeof(char*));
    if(!names) {
        free(nameCopy);
        return 0;
    }

    names[numNames] = nameCopy;
    numNames++;

    return 1;
}

// Wie addName. Fügt Namen aber direkt sortiert hinzu. Voraussetzung ist ein bereits sortiertes Archiv.
int addNameSorted(const char *name)
{
    return 0;
}

// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeName(const char *name)
{
    int idx = -1;
    for(int i = 0; i < numNames; i++) {
        if(strcmp(names[i], name) == 0) {
            idx = i;
            break;
        }
    }

    if(idx == -1)
        return 0;

    free(names[idx]);

    for(int i = idx; i < numNames-1; i++)
        names[i] = names[i+1];

    numNames--;

    return 1;
}

// Sortiert die Namen im Archiv aufsteigend.
void sortNames()
{}

// Gibt die Namen zeilenweise aus.
void printNames()
{
    for(int i = 0; i < numNames; i++)
        printf("%s\n", names[i]);
}

// Leert das Archiv
void clearArchive()
{
    for(int i = 0; i < numNames; i++)
        free(names[i]);
    free(names);
    numNames = 0;
    names = 0;
}
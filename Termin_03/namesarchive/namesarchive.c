// TODO
#include "namesarchive.h"
#include <string.h>
#include <stdio.h>

static char archive[MAX_NAMES][MAX_NAME_LEN];
static int numNames = 0;

int addName(const char *name)
{
    if(numNames < MAX_NAMES)
    {
        strncpy(archive[numNames], name, MAX_NAME_LEN);
        archive[numNames][MAX_NAME_LEN-1] = '\0';
        numNames++;
        return 1;
    }
    return 0;
}

int addNameSorted(const char *name)
{
    return 0;
}

int removeName(const char *name)
{
    return 0;
}

void printNames()
{
    for(int i = 0; i < numNames; i++)
        printf("%s\n", archive[i]);
}

// Lädt den Inhalt einer Textdatei zeilenweise in das Archiv. Gibt 1 bei Erfolg zurück.
int loadArchive(const char *path)
{
    FILE* f = fopen(path, "r");
    if(f) 
    {
        while(fgets(archive[numNames], MAX_NAME_LEN, f) && numNames < MAX_NAMES)
        {
            archive[numNames][MAX_NAME_LEN-1] = '\0';
            char* newline = strchr(archive[numNames], '\n');
            if(newline)
            {
                *newline = '\0';
            }
        }
        fclose(f);
        return 1;
    }
    return 0;
}

// Speichert das Archiv zeilenweise in einer Textdatei. Gibt 1 bei Erfolg zurück.
int saveArchive(const char *path)
{
    FILE* f = fopen(path, "w");
    if(f) 
    {
        for(int i = 0; i < numNames; i++)
        {
            fprintf(f, "%s\n", archive[i]);
        }

        fclose(f);
        return 1;
    }
    return 0;
}
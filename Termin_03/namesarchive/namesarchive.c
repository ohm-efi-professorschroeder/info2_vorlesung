#include "namesarchive.h"
#include <string.h>
#include <stdio.h>

#define MAX_NAMES 99

static char names[MAX_NAMES][MAX_NAME_LEN];
static int numNames = 0;

int addName(const char *name)
{
    if(numNames < MAX_NAMES) {
        strncpy(names[numNames], name, MAX_NAME_LEN);
        numNames+=1;
        return 1;
    }
    return 0;
}

void printNames()
{
    for(int i = 0; i < numNames; i++) {
        printf("%s\n", names[i]);
    }
}

int loadArchive(const char *path)
{
    FILE* f = fopen(path, "r");
    if(f) {
        char name[MAX_NAME_LEN];
        while(fgets(name, MAX_NAME_LEN, f)) {
            name[strlen(name)-1] = '\0';
            addName(name);
        }
        fclose(f);
    }
    else {
        return 0;
    }
    return 1;
}

int saveArchive(const char *path)
{
    FILE* f = fopen(path, "w");
    if(f) {
        for(int i = 0; i < numNames; i++) {
            fprintf(f, "%s\n", names[i]);
        }
        fclose(f);
        return 1;
    }
    return 0;
}

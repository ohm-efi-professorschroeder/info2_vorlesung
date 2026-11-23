#include "namesarchive.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
    // Nutzdaten/Wert
    char *name;

    // Vor-/Nachfolgezeiger
    struct node *next;
    struct node *prev;
} node_t;

static node_t* head = 0;


int addName(const char *name)
{
    node_t* newNode = (node_t*) calloc(1, sizeof(node_t));
    if(!newNode)
        return 0;

    char* newName = (char*) calloc(strlen(name)+1, sizeof(char));
    if(!newName) {
        free(newNode);
        return 0;
    }

    strncpy(newName, name, strlen(name)+1);
    newNode->name = newName;
    if(!head)
        head = newNode;
    else {
        node_t *cur = head;
        while(cur->next)
            cur = cur->next;
        
        cur->next = newNode;
        newNode->prev = cur;
    }

    return 1;
}

// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeName(const char *name)
{
    node_t *found = 0;
    node_t *cur = head;
    if(cur) {
        if(strcmp(cur->name, name) == 0)
            found = cur;
        else
            while(cur->next) {
                cur = cur->next;
                if(strcmp(cur->name, name) == 0) {
                    found = cur;
                    break;
                }
            }
    }

    if(!found)
        return 0;
    
    if(found->prev) {
        found->prev->next = found->next;
    }
    else
        head = found->next;
    if(found->next) {
        found->next->prev = found->prev;
    }

    free(found->name);
    free(found);

    return 1;
}

// Gibt die Namen zeilenweise aus.
void printNames()
{
    node_t *cur = head;
    if(cur) {
        printf("%s\n", cur->name);
        while(cur->next) {
            cur = cur->next;
            printf("%s\n", cur->name);
        }
    }
}

// Leert das Archiv
void clearArchive()
{
    node_t *next = head;
    do {
        if(next->prev) {
            free(next->prev->name);
            free(next->prev);
        }
        next = next->next;
    } while(next);

    head = 0;
}
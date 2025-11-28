#include "namesarchive.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    const char* name;
    struct node* next;
    struct node* prev;
} node_t;

static node_t *createNode(const char* name)
{
    node_t *newNode = calloc(1, sizeof(node_t));
    if(!newNode)
        return 0;

    newNode->name = malloc(strlen(name)+1);
    if(!newNode->name) {
        free(newNode);
        return 0;
    }
    strcpy(newNode->name, name);
    return newNode;
}

static node_t *pushBack(node_t *head, node_t *newNode)
{
    if(!head) {
        head = newNode;
        return head;
    }

    node_t *curNode = head;
    while(curNode->next)
        curNode = curNode->next;

    curNode->next = newNode;
    newNode->prev = curNode;

    return head;
}

static node_t *head = NULL;

int addName(const char *name)
{
    node_t* newNode = createNode(name);
    if(!newNode)
        return 0;

    head = pushBack(head, newNode);
    return 1;
}

void printNames()
{
    node_t *curNode = head;

    while(curNode) {
        printf("%s\n", curNode->name);
        curNode = curNode->next;
    }
}

int removeName(const char *name)
{
    node_t *curNode = head;

    while(curNode) {
        if(strcmp(curNode->name, name) == 0)
        {
            node_t *next = curNode->next;
            node_t *prev = curNode->prev;
            free(curNode->name);
            free(curNode);

            if(next) {
                next->prev = prev;
            }
            if(prev) {
                prev->next = next;
            }
            else {
                head = next;
            }
            return 1;
        }

        curNode = curNode->next;
    }

    return 0;
}

void clearArchive()
{
    node_t *curNode = head;

    while(curNode) {
        free(curNode->name);
        node_t *nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
    head = NULL;
}
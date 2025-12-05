#include "namesarchive.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct treenode 
{
    char* name;
    struct treenode* left;
    struct treenode* right;
} treenode_t;


static treenode_t* createNode(const char* name)
{
    treenode_t* newNode = calloc(1, sizeof(treenode_t));
    if(!newNode) return NULL;

    newNode->name = malloc(strlen(name)+1);
    if(!newNode->name) {
        free(newNode);
        return 0;
    }
    strcpy(newNode->name, name);
    return newNode;
}

static treenode_t* insert(treenode_t* root, const char* name)
{
    if(!root) {
        treenode_t* newNode = createNode(name);
        return newNode;
    }

    if(strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name);
    }
    else if(strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name);
    }
    return root;
}

static void inorderTraversal(const treenode_t *root)
{
    if(root) {
        inorderTraversal(root->left);
        printf("%s\n", root->name);
        inorderTraversal(root->right);
    }
}

static void freeNode(treenode_t *node)
{
    if(node) {
        free(node->name);
        free(node);
    }
}

static void destroyTree(treenode_t *root)
{
    if(root) {
        destroyTree(root->left);
        destroyTree(root->right);
        freeNode(root);
    }
}

static treenode_t* findMinimum(treenode_t *root)
{
    if(root && root->left)
        return findMinimum(root->left);
    return root;
}

static treenode_t* deleteNode(treenode_t* root, const char* name, int* success)
{
    if(!root) return NULL;

    if(strcmp(name, root->name) < 0) 
        root->left = deleteNode(root->left, name, success);
    else if(strcmp(name, root->name) > 0)
        root->right = deleteNode(root->right, name, success);
    else {
        *success = 1;
        // 1 Kind
        if(!root->right) {
            treenode_t *tempNode = root->left;
            freeNode(root);
            return tempNode;
        }
        else if(!root->left) {
            treenode_t *tempNode = root->right;
            freeNode(root);
            return tempNode;
        }
        // 2 Kinder
        else {
            treenode_t *successor = findMinimum(root->right);
            char *rootName = root->name;
            root->name = successor->name;
            successor->name = rootName;
            root->right = deleteNode(root->right, rootName, success);
        }
    }

    return root;
}

static treenode_t *root = NULL;

int addName(const char *name)
{
    root = insert(root, name);
    if(!root)
        return 0;
    return 1;
}

int removeName(const char *name)
{
    int success = 0;
    root = deleteNode(root, name, &success);
    return success;
}

void printNamesSorted()
{
    inorderTraversal(root);
}

void clearArchive()
{
    destroyTree(root);
    root = NULL;
}
/*
 * Was gibt folgendes Programm aus? Erst überlegen, dann ausführen.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LEN 100

typedef struct
{
    char text1[MAX_TEXT_LEN];
    char *text2;
    int number;
} MyStruct;

void modify1(MyStruct arg);
void modify2(MyStruct *arg);
void printStruct(const MyStruct *someStruct);

int main()
{
    char text[MAX_TEXT_LEN] = "Text 2";
    MyStruct someStruct = {"Text 1", text, 15};
    
    printStruct(&someStruct);

    modify1(someStruct);

    printf("\nNach modify1:\n");
    printStruct(&someStruct);

    modify2(&someStruct);

    printf("\nNach modify2:\n");
    printStruct(&someStruct);

    return EXIT_SUCCESS;
}

void modify1(MyStruct arg)
{
    strncpy(arg.text1, "Neuer Text 1", MAX_TEXT_LEN);
    strncpy(arg.text2, "Neuer Text 2", MAX_TEXT_LEN);
    arg.number = 100;
}

void modify2(MyStruct *arg)
{
    strncpy(arg->text1, "Wieder neuer Text 1", MAX_TEXT_LEN);
    strncpy(arg->text2, "Wieder neuer Text 2", MAX_TEXT_LEN);
    arg->number = 200;
}

void printStruct(const MyStruct* someStruct)
{
    printf("someStruct.text1  = %s\n", someStruct->text1);
    printf("someStruct.text2  = %s\n", someStruct->text2);
    printf("someStruct.number = %d\n", someStruct->number);
}

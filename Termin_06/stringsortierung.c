/*
 * Erweitern Sie das folgende Programm, sodass es die Funktion qsort der Standard-Bibliothek verwendet, 
 * um das enthaltene String-Array sortiert auszugeben. Es sollen zuerst die Strings ohne Zahlen ausgegeben werden 
 * und am Ende die mit Zahlen. Die Strings ohne Zahlen sollen aufsteigend sortiert werden, die mit Zahlen absteigend.
 * Sie können davon ausgehen, dass die im Array enthaltenen Strings immer nur aus Buchstaben oder nur aus Zahlen bestehen.
 * Es ist also ausreichend, das erste Zeichen mittels isdigit(...) zu prüfen.
 * 
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void gibStringsAus(const char *strings[], int anzahl);

int myCompare(const void* a, const void* b)
{
    const char* strA = *((const char**)a);
    const char* strB = *((const char**)b);

    if(isdigit(strA[0]) && !isdigit(strB[0])) // strA Zahl, strB Name
        return 1;
    else if(!isdigit(strA[0]) && isdigit(strB[0])) // strA Name, strB Zahl
        return -1;
    else if(isdigit(strA[0]) && isdigit(strB[0])) // beides Zahl
        return -strcmp(strA, strB);
    else // beides Name
        return strcmp(strA, strB);
}

int main()
{
    const char *strings[] = {"789", "Zorro", "Adam", "Werner", "123", "Bernd", "Hubert", "456"};
    unsigned int anzahlStrings = sizeof(strings)/sizeof(strings[0]);

    printf("Vor Sortierung:\n");
    gibStringsAus(strings, anzahlStrings);

    // TODO: Hier sortieren
    qsort(strings, anzahlStrings, sizeof(char*), &myCompare);

    printf("\nNach Sortierung:\n");
    gibStringsAus(strings, anzahlStrings);

    return EXIT_SUCCESS;
}

void gibStringsAus(const char *strings[], int anzahl)
{
    for(int i = 0; i < anzahl; i++)
    {
        printf("%s\n", strings[i]);
    }
}

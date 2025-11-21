/*
 * Im folgenden Programm soll eine Eingabe nur bestehend aus Zahlen als String eingelesen werden. Die einzelnen Zahlen sollen extrahiert, konvertiert 
 * und deren Summe ausgegeben werden.
 * 
 * 1. Ergänzen Sie in den vorhandenen Funktionen zunächst das Schlüsselwort const bei geeigneten Parametern.
 * 2. Implementieren Sie nun die Funktion konvertiereZahlen, die einen String übergeben bekommt, die enthaltenen Zahlen nach int konvertiert und in einem 
 *    int-Array speichert. Der String soll nicht verändert werden. Die Funktion soll die Anzahl an extrahierten Zahlen zurückgeben oder 0, falls Wörter enthalten 
 *    sind, die keine Zahlen sind. Sehen Sie sich für die genauen Anforderung an die Funktion auch unten deren Verwendung in der main-Funktion an. Vergessen Sie 
 *    nicht, Parameter mit dem Schlüsselwort const zu markieren, wenn es Sinn ergibt.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUFFER_GROESSE 100


char *gibTextEin(const char *ausgabeText, char *puffer, unsigned int groesse);
void gibSummeAus(const unsigned int zahlen[], unsigned int anzahl);
unsigned int konvertiereZahlen(const char* eingabe, unsigned int zahlen[], unsigned int anzahl);

int main()
{
    char eingabe[PUFFER_GROESSE];
    unsigned int zahlen[PUFFER_GROESSE];
    unsigned int vorhandeneZahlen = 0;
    
    gibTextEin("Geben Sie Zahlen ein: ", eingabe, PUFFER_GROESSE);

    vorhandeneZahlen = konvertiereZahlen(eingabe, zahlen, PUFFER_GROESSE);

    gibSummeAus(zahlen, vorhandeneZahlen);

    return EXIT_SUCCESS;
}

char *gibTextEin(const char *ausgabeText, char *puffer, unsigned int groesse)
{
    printf("%s", ausgabeText);
    fgets(puffer, groesse, stdin);

    if(puffer[strlen(puffer)-1] == '\n')
        puffer[strlen(puffer)-1] = '\0';
    else
        while(getchar() != '\n') {}

    return puffer;
}

void gibSummeAus(const unsigned int zahlen[], unsigned int anzahl)
{
    int summe = 0;

    if(anzahl > 0)
    {
        printf("%d", zahlen[0]);
        summe = zahlen[0];
    }

    for(int i = 1; i < anzahl; i++)
    {
        printf(" + %d", zahlen[i]);
        summe += zahlen[i];
    }

    if(anzahl > 0)
        printf(" = %d\n", summe);
    else
        printf("%s", "Keine Werte vorhanden!\n");
}

unsigned int konvertiereZahlen(const char* eingabe, unsigned int zahlen[], unsigned int anzahl)
{
    unsigned int numZahlen = 0;

    char *eingabeCpy = malloc(strlen(eingabe)+1); 
    if(!eingabeCpy)
        return 0;
    strcpy(eingabeCpy, eingabe);

    char* zahlStr = strtok(eingabeCpy, ", ");

    while(zahlStr && numZahlen < anzahl) {
        // Zahl auslesen
        char *endPtr;
        zahlen[numZahlen] = strtol(zahlStr, &endPtr, 10);
        if(*endPtr != '\0') {
            free(eingabeCpy);
            return 0;
        }
        numZahlen++;
        // nächste Zahl holen
        zahlStr = strtok(NULL, ", ");
    }
    free(eingabeCpy);
    return numZahlen;
}
/************************************************************************************************
 * Implementieren Sie die folgenden Sortieralgorithmen und vergleichen Sie deren Laufzeit mit 
 * untenstehendem Programm:
 * 1. Nutzen Sie zunächst die bereitgestellte und aus Informatik 1 bekannte Lösung für SelectionSort.
 * 2. Erweitern Sie nun sortierung.h bzw. sortierung.c um MergeSort.
 * 3. Erweitern Sie nun sortierung.h bzw. sortierung.c um Quicksort.
 * 4. Nutzen Sie abschließend die von der C-Standardbibliothek bereitgestellte qsort-Funktion.
 * 
 * Hinweis: Das Array wird nur ausgegeben, wenn die Anzahl an Elementen noch klein genug für 
 *          eine Darstellung ist. Standardmäßig wird eine sehr große Anzahl an Elementen sortiert, um 
 *          eine spürbare Laufzeit zu erzwingen, und somit das Array nicht ausgegeben. Genaueres ist 
 *          im Quellcode unten ersichtlich.
 * 
 * Welche Laufzeit-Unterschiede ergeben sich?
 *************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortierung.h"
#include "zufallsarray.h"
#include "stoppuhr.h"

#define ANZAHL_MAX 100000
#define ANZAHL ANZAHL_MAX
#define ANZEIGE_MAX 100

void gibArrayAus(int array[], int anzahl)
{
    for(int i = 0; i < anzahl; i++)
    {
        printf(" %3d", array[i]);
    }
    printf("\n");
}

int main()
{
    int zufallszahlen[ANZAHL];
    srand(0);

    fuelleArray(zufallszahlen, ANZAHL, -ANZAHL, ANZAHL);

    if(ANZAHL <= ANZEIGE_MAX)
        gibArrayAus(zufallszahlen, ANZAHL);

    starteUhr();
    // Nutzen Sie später hier die von Ihnen implementierte Funktion für MergeSort bzw. QuickSort.
    selectionSort(zufallszahlen, ANZAHL);

    printf("Zahlen sortiert nach %lf Sekunden.\n", messeZeitInSek());

    if(ANZAHL <= ANZEIGE_MAX)
        gibArrayAus(zufallszahlen, ANZAHL);

    return 0;
}

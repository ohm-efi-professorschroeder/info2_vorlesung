#include "sortierung.h"

static void tausche(int *zahl1, int *zahl2)
{
    int tmp = *zahl1;
    *zahl1 = *zahl2;
    *zahl2 = tmp;
}

void selectionSort(int array[], int anzahl)
{
    for(int i = 0; i < anzahl - 1; i++)
    {
        int minIdx = i;
        for(int j = i + 1; j < anzahl; j++)
        {
            if(array[j] < array[minIdx])
                minIdx = j;
        }
        tausche(&array[i], &array[minIdx]);
    }
}

int *teile(int* links, int *rechts)
{
    // Pivotelement bestimmen
    int *pivot = rechts;
    rechts--;

    // Linke und rechtes Teilarray um Pivot partitionieren
    while(links < rechts)
    {
        while(*links <= *pivot && links < rechts)
            links++;
        while(*rechts > *pivot && links < rechts)
            rechts--;

        if(*links > *rechts)    
            tausche(links, rechts);
    }

    // Pivotelement an die richtige Stelle schieben
    if(*links > *pivot)
        tausche(links, pivot);
    else
        links = pivot;

    return links;
}

void quicksortRek(int* links, int* rechts)
{
    if(links < rechts) {
        int *pivot = teile(links, rechts);
        quicksortRek(links, pivot-1);
        quicksortRek(pivot+1, rechts);
    }
}

void quickSort(int array[], int anzahl)
{
    quicksortRek(array, array+anzahl-1);
}
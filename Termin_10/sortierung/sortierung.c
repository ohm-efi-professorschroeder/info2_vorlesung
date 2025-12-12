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
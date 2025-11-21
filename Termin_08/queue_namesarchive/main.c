/*
 * Ergänzen Sie das untenstehende Programm, indem Sie wieder ein Namensarchiv-Modul in der namesarchive.h und der namesarchive.c 
 * implementieren. Es sollen diesmal wieder nur Namen gespeichert werden. Allerdings sollen diese nun als verkettete Liste 
 * implementiert werden. Die geforderten Funktionalitäten sowie weitere Details können wieder der namesarchive.h entnommen werden.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "namesarchive.h"

void testAdd(const char *name);
void testRemove(const char *name);

int main()
{
    testAdd("Zorro");
    testAdd("Werner");
    testAdd("Susi");
    testAdd("Adam");
    testAdd("Berta");
    testAdd("Aaron");

    printf("\nNach Hinzufuegen:\n");
    printNames();
    printf("\n");

    testRemove("Zorro");
    testRemove("Aaron");
    testRemove("Susi");
    testRemove("Gerd");

    printf("\nNach Entfernen:\n");
    printNames();

    clearArchive();

    printf("\nNach Leeren des Archivs:\n");
    printNames();

    printf("\nEnde\n");

    return EXIT_SUCCESS;
}

void testAdd(const char *name)
{    
    printf("Versuche %s hinzuzufuegen.\n", name);
    
    if(addName(name))
        printf("Erfolgreich hinzugefuegt!\n");
    else
        printf("Fehler beim Hinzufuegen!\n");
}

void testRemove(const char *name)
{
    printf("Versuche %s zu entfernen.\n", name);

    if(removeName(name))
        printf("Erfolgreich entfernt!\n");
    else
        printf("%s konnte nicht im Archiv gefunden werden!\n", name);

}

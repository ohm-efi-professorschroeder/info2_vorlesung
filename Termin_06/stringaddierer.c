/*
 * Ergänzen Sie im untenstehenden Programm die fehlenden Funktionen. addiereText bekommt dabei eine Folge von 
 * Zahlenwörtern kleiner zehn übergeben und ermittelt daraus die Summe. Groß- und Kleinschreibung soll keine Rolle spielen. 
 * Zudem liefert die Funktion 0, wenn ein Zahlenwort nicht aufgelöst werden konnte, ansonsten 1.
 * 
 * 1. Beispielhafter Programmablauf:
 * >> Addiere: Fuenf achT SIEBEN
 * Das Ergebnis lautet 20.
 * 
 * 2. Beispielhafter Programmablauf:
 * >> Addiere: fuenf achtzehn sieben
 * Falsche Eingabe.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <eingabe.h>

#define MAX_EINGABE_LEN 100

char *wandleKlein(char *text);
int wandleZahl(const char *wort);
int addiereText(const char *text, int *erg);

int main()
{
    char eingabeText[MAX_EINGABE_LEN];
    int erg;

    gibTextEin("Addiere: ", eingabeText, MAX_EINGABE_LEN);

    if(addiereText(eingabeText, &erg))
        printf("Das Ergebnis lautet %d.\n", erg);
    else
        printf("Falsche Eingabe.\n");

    return EXIT_SUCCESS;
}

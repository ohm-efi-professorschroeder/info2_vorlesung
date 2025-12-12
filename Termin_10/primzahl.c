/*
 * Das folgende Programm prüft auf einfache Weise, ob die eingegebene Zahl eine Primzahl ist. 
 * Ergänzen Sie eine rekursive Prüffunktion istPrimzahlRek, die innerhalb der istPrimzahl-Funktion 
 * aufgerufen wird und den iterativen vorhandenen Ansatz ersetzt.
 */

#include <stdio.h>

int gibPositiveZahlEin(const char *text)
{
    int zahl;

    printf("%s", text);

    while((scanf("%d", &zahl) != 1) || (zahl <= 0))
    {
        while(getchar() != '\n') {}
        printf("Fehler! %s", text);
    }

    return zahl;
}

int istPrimzahl(unsigned int zahl)
{
    for(int i = 2; i < zahl/2; i++)
    {
        if(zahl % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    unsigned int zahl = 0;

    zahl = gibPositiveZahlEin("Geben Sie eine ganze, positive Zahl ein: ");

    printf("Die Zahl %d ist ", zahl);

    if(!istPrimzahl(zahl))
        printf("k");
    
    printf("eine Primzahl.\n");

    return 0;
}
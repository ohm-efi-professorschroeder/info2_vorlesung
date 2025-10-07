/*
 * Schreiben Sie eine Funktion schreibeAnfangGross, die eine Zeichenkette übergeben bekommt, den Anfangsbuchstaben jedes Wortes groß 
 * schreibt und einen Zeiger auf den Anfang dieser Zeichenkette zurückgibt. Nutzen Sie für die Eingabe die Eingabefunktion aus 
 * einer der vorherigen Übungen.
 * 
 * Möglicher Programmablauf:
 * >> Geben Sie einen Text nur mit Kleinbuchstaben ein: das ist das haus vom nikolaus. und nebendran wohnt der weihnachtsmann.
 * Der bearbeitete Text lautet:
 * "Das Ist Das Haus Vom Nikolaus. Und Nebendran Wohnt Der Weihnachtsmann."
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "eingabe.h"

#define MAX_TEXT_LEN 100

char *schreibeAnfangGross(char *text, int maxZeichen);

int main()
{
    char text[MAX_TEXT_LEN] = "";

    gibTextEin("Geben Sie einen Text nur mit Kleinbuchstaben ein: ", text, MAX_TEXT_LEN);

    printf("Der bearbeitete Text lautet:\n\"%s\"\n", schreibeAnfangGross(text, MAX_TEXT_LEN));

    return EXIT_SUCCESS;
}

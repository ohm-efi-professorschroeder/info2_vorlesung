/* 
Erweitertes Beispiel für Systeme, bei denen die Aufrufkonvention die Rücksprungadresse vor die lokalen Variablen schreibt.
Getestet auf Ubuntu 24.04. ARM64.
*/

#include <stdio.h>
#include <string.h>

void showSecretInformation()
{
    printf("Erfolg! Sie haben die geheime Funktion erreicht!\n");
}

int enterPassword()
{
    char buffer[4]; 

    gets(buffer);

    return strcmp(buffer, "abc") == 0;
}

void passwordPrompt()
{
   printf("Bitte geben Sie das Passwort ein: ");

   int correct = enterPassword();

   if (correct)
      showSecretInformation();
}

int main()
{
    printf("Programm gestartet.\n");
    passwordPrompt(); 
    printf("Zurück in main.\n");

    return 0;
}
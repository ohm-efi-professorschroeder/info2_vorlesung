/* 
Beispiel aus den Vorlesungsfolien. Setzt voraus, dass die Rücksprungadresse hinter den lokalen Variablen auf dem Stack liegt.
Getestet auf Windows x64.
*/
#include <stdio.h>
#include <string.h>

void showSecretInformation()
{
   printf("Erfolg!\n");
}

int checkPassword()
{
   char buffer[5];

   printf("Bitte Passwort eingeben: ");
   scanf("%s", buffer);

   return strcmp(buffer, "pass") == 0;
}

int main()
{
   if(checkPassword())
      showSecretInformation();
   else
      printf("Falsches Passwort!\n");

   return 0;
}

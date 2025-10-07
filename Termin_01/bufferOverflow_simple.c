#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[9];
    int passed = 0;

    printf("Bitte Passwort eingeben: ");
    scanf("%s", buffer);

    if(strcmp(buffer, "Passwort!"))
        printf("Falsches Passwort\n");
    else
    {
        printf("richtiges Passwort!\n");
        passed = 1;
    }

    if(passed)
        printf("Erfolg!");
}
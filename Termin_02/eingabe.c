// TODO
#include "eingabe.h"

#include <stdio.h>
#include <string.h>

int gibTextEin(const char* output, char buffer[], int len)
{
    printf("%s", output);

    if(fgets(buffer, len, stdin))
    {
        buffer[strlen(buffer)-1] = '\0';
        while(getchar() != '\n');
        buffer[len-1] = '\0';
        return 1;
    }

    return 0;
}
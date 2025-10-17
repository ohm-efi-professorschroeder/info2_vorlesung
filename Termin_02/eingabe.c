// TODO
#include "eingabe.h"
#include <stdio.h>
#include <string.h>

int gibTextEin(const char *aufforderung, char* eingabe, int maxLen)
{
    printf("%s", aufforderung);

    if(fgets(eingabe, maxLen, stdin) != NULL)
    {
        char* newline = strchr(eingabe, '\n');
        if(newline)
        {
            *newline = '\0';
        }

        if(strlen(eingabe) >= (size_t)maxLen-1)
            while(getchar() != '\n');
        
        return 1;
    }
    else
        return 0;

}
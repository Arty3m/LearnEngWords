#include "getch.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
void enter(int* m)
{
    char out[1000];
    int c, i = 0;
    while ((c = getch()) != 10) {
        if (isdigit(c)) {
            if ((char)c != '\n')
                out[i++] = (char)c;
            printf("%c", c);
        }
    }
    printf("\n");
    out[i] = '\0';
    *m = atoi(out);
}

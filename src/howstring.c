#include <stdio.h>
#include <stdlib.h>
int howstring(FILE* f)
{
    char k;
    int c = 0;
    if (f == NULL) {
        perror("");
        return -1;
    }
    while (!feof(f)) {
        k = getc(f);
        if (k == '\n' || k == ' ')
            c++;
    }
    rewind(f);
    return c;
}

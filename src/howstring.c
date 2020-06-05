#include <stdio.h>
#include <stdlib.h>
int howstring(FILE* f)
{
    char k;
    int c = 0;
    if (f == NULL) {
        perror("");
        exit(1);
    }
    while (!feof(f)) {
        k = getc(f);
        if (k == '\n')
            c++;
    }
    rewind(f);
    return c;
}

#include <stdio.h>
#include <stdlib.h>
int getstring(FILE* f, char* p)
{
    char k;
    int i = 0, count = 0;
    if (f == NULL) {
        perror("");
        return -1;
    }
    while (!feof(f)) {
        k = getc(f);
        count++;
    }
    count -= 2;
    rewind(f);
    for (i = 0; i < count; i++) {
        if ((k = getc(f)) == '\n')
            p[i] = ' ';
        else
            p[i] = k;
    }
    p[i] = '\0';
    return 0;
}

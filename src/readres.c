#include <stdio.h>
#include <stdlib.h>
int readres(FILE* f, int strok, int* p)
{
    int i = 0;
    char s[100];
    if (f == NULL) {
        perror("");
        return -1;
    }
    for (i = 0; i < strok; i++) {
        if (fgets(s, 30, f) != NULL)
            p[i] = atoi(s);
    }
    rewind(f);
    fclose(f);
    return 0;
}

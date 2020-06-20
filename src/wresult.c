#include <stdio.h>
int wresult(FILE* f, int strok, int* p)
{
    int i = 0;
    for (i = 0; i < strok; i++) {
        fprintf(f, "%d\n", p[i]);
    }
    rewind(f);
    return 0;
}

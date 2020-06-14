#include <stdio.h>
void wresult(int strok, int* p)
{
    int i = 0;
    FILE* f = fopen("Results.txt", "w");
    for (i = 0; i < strok; i++) {
        fprintf(f, "%d\n", p[i]);
    }
    rewind(f);
    fclose(f);
}

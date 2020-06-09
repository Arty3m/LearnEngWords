#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randword(int strok, int* p, int c)
{
    int r = 0, i = 0;
    srand(time(NULL));
    int arr[strok];
    for (i = 0; i < strok; i++) {
        arr[i] = c - p[i];
        printf("%d\n", arr[i]);
    }
    i = 0;
    while (1) {
        r = random() % strok;
        printf("[%d]r=%d\n", i + 1, r);
        if ((arr[r] != 0) && (p[r] < c)) {
            i++;
            arr[r] -= 1;
            printf("P[r]=%d", p[r]);
            return r;
        } else if (i == 0)
            return -1;
    }
}

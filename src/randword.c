#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randword(int strok, int* p, int c)
{
    int r = 0, i = 0, j = 0, k = 0;
    srand(time(NULL));
    for (i = 0; i < strok; i++) {
        if (p[i] < c) {
            k += c - p[i];
            j++;
        }
    }
    int arr[j];
    j = 0;
    for (i = 0; i < strok; i++)
        if (p[i] < c) {
            arr[j++] = i;
        }
    i = 0;
    while (k != 0) {
        r = random() % j;
        if (p[arr[r]] < c) {
            return arr[r];
        }
    }
    return -1;
}

#include <stdlib.h>
#include <time.h>
int randposition(int arr[], int n, int r)
{
    int i = 0, k = 0, j = 0, ind = 0, V[n];
    for (i = 0; i < n; i++) {
        if (i == r)
            V[i] = -1;
        else
            V[i] = i;
    }
    for (i = 0; i < 4; i++)
        arr[i] = 0;
    srand(time(NULL));
    k = rand() % 4 + 1;
    arr[k - 1] = r;
    for (i = 0; i < 4; i++) {
        if (i != k - 1) {
            ind = rand() % n;
            if (V[ind] != -1) {
                arr[i] = V[ind];
                V[ind] = -1;
            } else {
                for (j = 0; j < n; j++)
                    if (V[j] != -1) {
                        arr[i] = V[j];
                        V[j] = -1;
                        break; // maybe
                    }
            }
        } else
            continue;
    }
    int k1 = k - 1;
    for (i = 0; i < 4; i++)
        if ((arr[k1] == arr[i]) && (i != k1)) {
            for (j = 0; j < n; j++)
                if (V[j] != -1 && V[j] != arr[i]) {
                    arr[i] = V[j];
                    V[j] = -1;
                    break;
                } else
                    continue;
        }

    return k;
}

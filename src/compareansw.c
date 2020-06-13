#include <string.h>
int compareansw(char answ[], char* arr[], int r)
{
    char* exit = "Exit";
    if (strcmp(exit, answ) != 0) {
        if (strcmp(arr[r], answ) == 0)
            return 1;
        else
            return 2;
    } else
        return 0;
}

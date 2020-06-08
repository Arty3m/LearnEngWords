#include <string.h>
void convert(char *p, char *arr[]) {
  int i = 0;
  char *t;
  t = strtok(p, " ");
  while (t != NULL) {
    strcpy(arr[i], t);
    i++;
    t = strtok(NULL, " ");
  }
  t = NULL;
}

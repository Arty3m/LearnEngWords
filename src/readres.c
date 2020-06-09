#include <stdio.h>
#include <stdlib.h>
void readres(int strok, int *p) {
  int i = 0;
  char s[100];
  FILE *f = fopen("Results.txt", "r");
  if (f == NULL) {
    perror("Ошибка открытия файла");
    // return -1;
  }
  for (i = 0; i < strok; i++) {
    if (fgets(s, 30, f) != NULL)
      p[i] = atoi(s);
  }
  rewind(f);
  fclose(f);
}

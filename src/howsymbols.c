#include <stdio.h>
#include <stdlib.h>
int howsymbols(FILE *f) {
  int count = 0;
  if (f == NULL) {
    perror("");
    exit(1);
  }
  while (!feof(f)) {
    getc(f);
    count++;
  }
  count -= 2;
  rewind(f);
  return count;
}

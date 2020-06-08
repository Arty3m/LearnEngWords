#include "convert.h"
#include "getch.h"
#include "getstring.h"
#include "howstring.h"
#include "howsymbols.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int i = 0, strok = 0, simvEng = 0, simvRus = 0;
    FILE* fEng = fopen("EngWords.txt", "r");
    FILE* fRus = fopen("RusWords.txt", "r");
    strok = howstring(fEng);
    if (strok == (howstring(fRus))) {
        simvEng = howsymbols(fEng);
        simvRus = howsymbols(fRus);
    } else {
        printf("Количество строк в файлах не совпадает! Обновите ваши файлы\n");
        return 0;
    }
    char pEng[simvEng], pRus[simvRus];
    getstring(fEng, pEng);
    getstring(fRus, pRus);
    char *eng[strok], *rus[strok];
    for (i = 0; i < strok; i++)
        eng[i] = (char*)malloc(sizeof(char));
    for (i = 0; i < strok; i++)
        rus[i] = (char*)malloc(sizeof(char));
    printf("PENG:%s\n", pEng);
    printf("PRUS:%s\n", pRus);
    convert(pEng, eng);
    convert(pRus, rus);
    printf("PENG:%s\n", pEng);
    printf("PRUS:%s\n", pRus);
    printf("%d\n", simvEng);
    printf("%d", simvRus);
    rewind(fEng);
    rewind(fRus);
    fclose(fEng);
    fclose(fRus);
    return 0;
}

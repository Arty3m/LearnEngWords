#include "convert.h"
#include "enter.h"
#include "getch.h"
#include "getstring.h"
#include "howstring.h"
#include "howsymbols.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int i = 0, strok = 0, simvEng = 0, simvRus = 0, menu = 0;
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
    printf("Добро пожаловать в приложение для заучивания английских "
           "слов!\nВведите 1 чтобы проверить свои знания в переводе "
           "английских слов\nВведите 2 чтобы проверить свои занния в переводе "
           "русских слов\nВведите 3 чтобы проверить знание написания "
           "слов\nВведите 4 чтобы открыть словарь\nВведите 5 "
           "чтобы выйти\n");
    printf("->");
    enter(&menu);
    sleep(1);
    system("clear");
    while (1) {
        switch (menu) {
        case 1: {
            break;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            printf("Пока! Заходи еще!\n");
            return 0;
        }
        }
    }
    return 0;
}

#include "compareansw.h"
#include "convert.h"
#include "enter.h"
#include "getch.h"
#include "getstring.h"
#include "howstring.h"
#include "howsymbols.h"
#include "randposition.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
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
    convert(pEng, eng);
    convert(pRus, rus);
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
        int k = 0, r = 0, answ = 0;
        switch (menu) {
        case 1: {
            int f1 = 1, score = 0;
            while (f1) {
                int pr[4];
                srand(time(NULL));
                r = rand() % strok;
                printf("Для выхода в меню введите 0 или просто нажмите "
                       "Enter\nВыберите правильный перевод для слова\t\t\tВаш "
                       "счёт:%d\n%s\n",
                       score,
                       eng[r]);
                k = randposition(pr, strok, r);

                printf("\n1.%s\n2.%s\n3.%s\n4.%s\n",
                       rus[pr[0]],
                       rus[pr[1]],
                       rus[pr[2]],
                       rus[pr[3]]);
                printf("->");
                enter(&answ);
                while (answ != 0 && answ != 1 && answ != 2 && answ != 3
                       && answ != 4) {
                    printf("Такого варианта нет, попробуйте еще\n");
                    printf("->");
                    enter(&answ);
                }
                switch (answ) {
                case 0: {
                    system("clear");
                    f1 = 0;
                    printf("Добро пожаловать в приложение для заучивания "
                           "английских слов!\nВведите 1 чтобы проверить свои "
                           "знания в переводе английских слов\nВведите 2 чтобы "
                           "проверить свои знания в переводе русских "
                           "слов\nВведите 3 чтобы проверить знание написания "
                           "слов\nВведите 4 чтобы открыть словарь\nВведите 5 "
                           "чтобы выйти\n");
                    printf("->");
                    enter(&menu);
                    break;
                }
                case 1: {
                    if (answ == k) {
                        printf("Верно!\n");
                        score++;
                    } else {
                        printf("Ошибочка!\nПравильный перевод-> %s\n",
                               rus[pr[k - 1]]);
                        score -= 2;
                        sleep(2);
                    }
                    break;
                }
                case 2: {
                    if (answ == k) {
                        printf("Верно!\n");
                        score++;
                    } else {
                        printf("Ошибочка!\nПравильный перевод-> %s\n",
                               rus[pr[k - 1]]);
                        score -= 2;
                        sleep(2);
                    }
                    break;
                }
                case 3: {
                    if (answ == k) {
                        printf("Верно!\n");
                        score++;
                    } else {
                        printf("Ошибочка!\nПравильный перевод-> %s\n",
                               rus[pr[k - 1]]);
                        score -= 2;
                        sleep(2);
                    }
                    break;
                }
                case 4: {
                    if (answ == k) {
                        printf("Верно!\n");
                        score++;
                    } else {
                        printf("Ошибочка!\nПравильный перевод-> %s\n",
                               rus[pr[k - 1]]);
                        score -= 2;
                        sleep(2);
                    }
                    break;
                }
                }
                sleep(1);
                system("clear");
            }
            break;
        }
        case 2: {
            int f2 = 1, score = 0;
            while (f2) {
                system("clear");
                int pr[4];
                srand(time(NULL));
                r = rand() % strok;
                printf("Для выхода в меню введите 0 или просто нажмите "
                       "Enter\nВыберите правильный перевод для слова\t\t\tВаш "
                       "счёт:%d\n%s\n",
                       score,
                       rus[r]);
                k = randposition(pr, strok, r);

                printf("\n1.%s\n2.%s\n3.%s\n4.%s\n",
                       eng[pr[0]],
                       eng[pr[1]],
                       eng[pr[2]],
                       eng[pr[3]]);
                printf("->");
                enter(&answ);
                while (answ != 0 && answ != 1 && answ != 2 && answ != 3
                       && answ != 4) {
                    printf("Такого варианта нет, попробуйте еще\n");
                    printf("->");
                    enter(&answ);
                }
                switch (answ) {
                case 0: {
                    system("clear");
                    f2 = 0;
                    printf("Добро пожаловать в приложение для заучивания "
                           "английских слов!\nВведите 1 чтобы проверить свои "
                           "знания в переводе английских слов\nВведите 2 чтобы "
                           "проверить свои знания в переводе русских "
                           "слов\nВведите 3 чтобы проверить знание написания "
                           "слов\nВведите 4 чтобы открыть словарь\nВведите 5 "
                           "чтобы выйти\n");
                    printf("->");
                    enter(&menu);
                    break;
                }
                case 1: {
                    if (answ == k) {
                        printf("Верно!\n");
                        score++;
                    } else {
                        printf("Ошибочка!\nПравильный перевод-> %s\n",
                               eng[pr[k - 1]]);
                        score -= 2;
                        sleep(2);
                    }
                    break;
                }
                case 2: {
                    if (answ == k) {
                        printf("Верно!\n");
                        score++;
                    } else {
                        printf("Ошибочка!\nПравильный перевод-> %s\n",
                               eng[pr[k - 1]]);
                        score -= 2;
                        sleep(2);
                    }
                    break;
                }
                case 3: {
                    if (answ == k) {
                        printf("Верно!\n");
                        score++;
                    } else {
                        printf("Ошибочка!\nПравильный перевод-> %s\n",
                               eng[pr[k - 1]]);
                        score -= 2;
                        sleep(2);
                    }
                    break;
                }
                case 4: {
                    if (answ == k) {
                        printf("Верно!\n");
                        score++;
                    } else {
                        printf("Ошибочка!\nПравильный перевод-> %s\n",
                               eng[pr[k - 1]]);
                        score -= 2;
                        sleep(2);
                    }
                    break;
                }
                }
                sleep(1);
                system("clear");
            }
            break;
        }
        case 3: {
            int ans = 0, f3 = 1;
            char str[1000];
            while (f3) {
                system("clear");
                srand(time(NULL));
                r = rand() % strok;
                printf("Для выхода в меню введите <Выход>\nНапишите правильный "
                       "перевод "
                       "слова\n*Ответ вводить с большой буквы*\n\n%s "
                       "--> ",
                       eng[r]);
                scanf("%s", str);
                ans = compareansw(str, rus, r);
                switch (ans) {
                case 0: {
                    f3 = 0;
                    system("clear");
                    printf("Добро пожаловать в приложение для заучивания "
                           "английских "
                           "слов!\nВведите 1 чтобы проверить свои знания в "
                           "переводе "
                           "английских слов\nВведите 2 чтобы проверить свои "
                           "занния в "
                           "переводе "
                           "русских слов\nВведите 3 чтобы проверить знание "
                           "написания "
                           "слов\nВведите 4 чтобы открыть словарь\nВведите 5 "
                           "чтобы выйти\n");
                    printf("->");
                    enter(&menu);
                    break;
                }
                case 1: {
                    printf("\nВерно!\n");
                    sleep(1);
                    break;
                }
                case 2:
                    printf("\nОшибочка! Правильно-> %s\n", rus[r]);
                    sleep(2);
                    break;
                }
            }
            enter(&menu);
            system("clear");
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

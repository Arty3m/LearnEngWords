#include "compareansw.h"
#include "convert.h"
#include "enter.h"
#include "getch.h"
#include "getstring.h"
#include "howstring.h"
#include "howsymbols.h"
#include "randposition.h"
#include "randword.h"
#include "readres.h"
#include "rres.h"
#include "wresult.h"
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
    int i = 0, strok = 0, simvEng = 0, simvRus = 0, menu = 0, lim = 10;
    FILE* fEng = fopen("EngWords.txt", "r");
    FILE* fRus = fopen("RusWords.txt", "r");
    FILE* fRes = fopen("Results.txt", "r");
    strok = howstring(fEng);
    if (strok == (howstring(fRus))) {
        simvEng = howsymbols(fEng);
        simvRus = howsymbols(fRus);
    } else {
        printf("Количество строк в файлах не совпадает! Обновите ваши файлы\n");
        return 0;
    }
    char pEng[simvEng], pRus[simvRus];
    int res[strok];
    readres(fRes, strok, res);
    fclose(fRes);
    FILE* fRes1 = fopen("Results.txt", "w");
    getstring(fEng, pEng);
    getstring(fRus, pRus);
    char *eng[strok], *rus[strok];
    for (i = 0; i < strok; i++) {
        eng[i] = (char*)malloc(sizeof(char));
        rus[i] = (char*)malloc(sizeof(char));
    }
    convert(pEng, eng);
    convert(pRus, rus);
    rewind(fEng);
    rewind(fRus);
    fclose(fEng);
    fclose(fRus);
    system("clear");
    printf(">-----------------------------------------------------------------<"
           "\n   Добро пожаловать в приложение для заучивания английских "
           "слов!\n>-----------------------------------------------------------"
           "------<\n\n1. Заучивание перевода английских слов\n2. Заучивание "
           "перевода русских слов\n3. Заучивание написания английских слов\n4. "
           "Открыть словарь\n5. Посмотреть прогресс\n6. Выйти\n");
    printf("\n-->");
    enter(&menu);
    sleep(1);
    system("clear");
    while (1) {
        int k = 0, r = 0, answ = 0;
        switch (menu) {
        case 1: {
            int f1 = 1, score = 0;
            while (f1) {
                system("clear");
                int pr[4], key = 0;
                r = randword(strok, res, lim);
                if (r == -1) {
                    printf("\tВСЕ СЛОВА ВЫУЧЕНЫ\n\n");
                    printf("Введите 1, чтобы сбросить весь прогрес и начать "
                           "заного\nВведите 2, чтобы выйти в главное "
                           "меню\n-->");
                    enter(&key);
                    while (key != 1 && key != 2) {
                        printf("Такого варианта нет, попробуйте еще\n");
                        printf("\n-->");
                        enter(&key);
                    }
                    switch (key) {
                    case 1: {
                        rres(strok, res);
                        wresult(fRes1, strok, res);
                        printf("Прогресс успешно удалён\n");
                        sleep(3);
                        break;
                    }
                    case 2: {
                        system("clear");
                        f1 = 0;
                        printf(">----------------------------------------------"
                               "-------------------<\n   Добро пожаловать в "
                               "приложение для заучивания английских "
                               "слов!\n>---------------------------------------"
                               "--------------------------<\n\n1. Заучивание "
                               "перевода английских слов\n2. Заучивание "
                               "перевода русских слов\n3. Заучивание написания "
                               "английских слов\n4. Открыть словарь\n5. "
                               "Посмотреть прогресс\n6. Выйти\n");
                        printf("\n-->");
                        enter(&menu);
                        break;
                    }
                    default: {
                        printf("Неверный ввод. Попробуйте еще.\n");
                        sleep(1);
                        system("clear");
                        printf("\tВСЕ СЛОВА ВЫУЧЕНЫ\n\n");
                        printf("Введите 1, чтобы сбросить весь прогрес и "
                               "начать заного\nВведите 2, чтобы выйти в "
                               "главное меню\n-->");
                        enter(&key);
                        break;
                    }
                    }
                } else {
                    printf("Для выхода в меню введите 0 или просто нажмите "
                           "Enter\nСлово считается выученным, если на него дан "
                           "правильный ответ 10 раз\n\nВыберите правильный "
                           "перевод для слова\t\t\tВаш счёт:%d\n%s\n",
                           score,
                           eng[r]);
                    k = randposition(pr, strok, r);

                    printf("\n1.%s\n2.%s\n3.%s\n4.%s\n",
                           rus[pr[0]],
                           rus[pr[1]],
                           rus[pr[2]],
                           rus[pr[3]]);
                    printf("\n-->");
                    enter(&answ);
                    while (answ != 0 && answ != 1 && answ != 2 && answ != 3
                           && answ != 4) {
                        printf("Такого варианта нет, попробуйте еще\n");
                        printf("\n-->");
                        enter(&answ);
                    }
                    switch (answ) {
                    case 0: {
                        system("clear");
                        f1 = 0;
                        wresult(fRes1, strok, res);
                        printf(">----------------------------------------------"
                               "-------------------<\n   Добро пожаловать в "
                               "приложение для заучивания английских "
                               "слов!\n>---------------------------------------"
                               "--------------------------<\n\n1. Заучивание "
                               "перевода английских слов\n2. Заучивание "
                               "перевода русских слов\n3. Заучивание написания "
                               "английских слов\n4. Открыть словарь\n5. "
                               "Посмотреть прогресс\n6. Выйти\n");
                        printf("\n-->");
                        enter(&menu);
                        break;
                    }
                    case 1: {
                        if (answ == k) {
                            printf("Верно!\n");
                            score++;
                            res[r] += 1;
                        } else {
                            printf("Ошибочка!\nПравильный перевод-> %s\n",
                                   rus[pr[k - 1]]);
                            score -= 2;
                            res[r] = 0;
                            sleep(2);
                        }
                        break;
                    }
                    case 2: {
                        if (answ == k) {
                            printf("Верно!\n");
                            score++;
                            res[r] += 1;
                        } else {
                            printf("Ошибочка!\nПравильный перевод-> %s\n",
                                   rus[pr[k - 1]]);
                            score -= 2;
                            res[r] = 0;
                            sleep(2);
                        }
                        break;
                    }
                    case 3: {
                        if (answ == k) {
                            printf("Верно!\n");
                            score++;
                            res[r] += 1;
                        } else {
                            printf("Ошибочка!\nПравильный перевод-> %s\n",
                                   rus[pr[k - 1]]);
                            score -= 2;
                            res[r] = 0;
                            sleep(2);
                        }
                        break;
                    }
                    case 4: {
                        if (answ == k) {
                            printf("Верно!\n");
                            score++;
                            res[r] += 1;
                        } else {
                            printf("Ошибочка!\nПравильный перевод-> %s\n",
                                   rus[pr[k - 1]]);
                            score -= 2;
                            res[r] = 0;
                            sleep(2);
                        }
                        break;
                    }
                    }
                    sleep(1);
                    system("clear");
                }
            }
            break;
        }
        case 2: {
            int f2 = 1, score = 0;
            while (f2) {
                system("clear");
                int pr[4], key = 0;
                r = randword(strok, res, lim);
                if (r == -1) {
                    printf("\tВСЕ СЛОВА ВЫУЧЕНЫ\n\n");
                    printf("Введите 1, чтобы сбросить весь прогрес и начать "
                           "заного\nВведите 2, чтобы выйти в главное "
                           "меню\n-->");
                    enter(&key);
                    while (key != 1 && key != 2) {
                        printf("Такого варианта нет, попробуйте еще\n");
                        printf("\n-->");
                        enter(&key);
                    }
                    switch (key) {
                    case 1: {
                        rres(strok, res);
                        wresult(fRes1, strok, res);
                        printf("Прогресс успешно удалён\n");
                        sleep(1);
                        break;
                    }
                    case 2: {
                        system("clear");
                        f2 = 0;
                        printf(">----------------------------------------------"
                               "-------------------<\n   Добро пожаловать в "
                               "приложение для заучивания английских "
                               "слов!\n>---------------------------------------"
                               "--------------------------<\n\n1. Заучивание "
                               "перевода английских слов\n2. Заучивание "
                               "перевода русских слов\n3. Заучивание написания "
                               "английских слов\n4. Открыть словарь\n5. "
                               "Посмотреть прогресс\n6. Выйти\n");
                        printf("\n-->");
                        enter(&menu);
                        break;
                    }
                    default: {
                        printf("Неверный ввод. Попробуйте еще.\n");
                        sleep(1);
                        system("clear");
                        printf("\tВСЕ СЛОВА ВЫУЧЕНЫ\n\n");
                        printf("Введите 1, чтобы сбросить весь прогрес и "
                               "начать "
                               "заного\nВведите 2, чтобы выйти в главное "
                               "меню\n-->");
                        enter(&key);
                        break;
                    }
                    }
                } else {
                    printf("Для выхода в меню введите 0 или просто нажмите "
                           "Enter\nСлово считается выученным, если на него дан "
                           "правильный ответ 10 раз\n\nВыберите правильный "
                           "перевод для слова\t\t\tВаш счёт:%d\n%s\n",
                           score,
                           rus[r]);
                    k = randposition(pr, strok, r);

                    printf("\n1.%s\n2.%s\n3.%s\n4.%s\n",
                           eng[pr[0]],
                           eng[pr[1]],
                           eng[pr[2]],
                           eng[pr[3]]);
                    printf("\n-->");
                    enter(&answ);
                    while (answ != 0 && answ != 1 && answ != 2 && answ != 3
                           && answ != 4) {
                        printf("Такого варианта нет, попробуйте еще\n");
                        printf("\n-->");
                        enter(&answ);
                    }
                    switch (answ) {
                    case 0: {
                        system("clear");
                        f2 = 0;
                        wresult(fRes1, strok, res);
                        printf(">----------------------------------------------"
                               "-------------------<\n   Добро пожаловать в "
                               "приложение для заучивания английских "
                               "слов!\n>---------------------------------------"
                               "--------------------------<\n\n1. Заучивание "
                               "перевода английских слов\n2. Заучивание "
                               "перевода русских слов\n3. Заучивание написания "
                               "английских слов\n4. Открыть словарь\n5. "
                               "Посмотреть прогресс\n6. Выйти\n");
                        printf("\n-->");
                        enter(&menu);
                        break;
                    }
                    case 1: {
                        if (answ == k) {
                            printf("Верно!\n");
                            score++;
                            res[r]++;
                        } else {
                            printf("Ошибочка!\nПравильный перевод-> %s\n",
                                   eng[pr[k - 1]]);
                            score -= 2;
                            res[r] = 0;
                            sleep(2);
                        }
                        break;
                    }
                    case 2: {
                        if (answ == k) {
                            printf("Верно!\n");
                            score++;
                            res[r]++;
                        } else {
                            printf("Ошибочка!\nПравильный перевод-> %s\n",
                                   eng[pr[k - 1]]);
                            score -= 2;
                            res[r] = 0;
                            sleep(2);
                        }
                        break;
                    }
                    case 3: {
                        if (answ == k) {
                            printf("Верно!\n");
                            score++;
                            res[r]++;
                        } else {
                            printf("Ошибочка!\nПравильный перевод-> %s\n",
                                   eng[pr[k - 1]]);
                            score -= 2;
                            res[r] = 0;
                            sleep(2);
                        }
                        break;
                    }
                    case 4: {
                        if (answ == k) {
                            printf("Верно!\n");
                            score++;
                            res[r]++;
                        } else {
                            printf("Ошибочка!\nПравильный перевод-> %s\n",
                                   eng[pr[k - 1]]);
                            score -= 2;
                            res[r] = 0;
                            sleep(2);
                        }
                        break;
                    }
                    }
                    sleep(1);
                    system("clear");
                }
            }
            break;
        }
        case 3: {
            int ans = 0, f3 = 1, score = 0;
            char str[1000];
            while (f3) {
                system("clear");
                srand(time(NULL));
                r = rand() % strok;
                printf("Для выхода в меню введите <Exit>\nНапишите правильный "
                       "перевод слова\t\t\tВаш счёт:%d\n*Ответ вводить с "
                       "большой буквы*\n\n%s --> ",
                       score,
                       rus[r]);
                scanf("%s", str);
                ans = compareansw(str, eng, r);
                switch (ans) {
                case 0: {
                    f3 = 0;
                    system("clear");
                    printf(">--------------------------------------------------"
                           "---------------<\n   Добро пожаловать в приложение "
                           "для заучивания английских "
                           "слов!\n>-------------------------------------------"
                           "----------------------<\n\n1. Заучивание перевода "
                           "английских слов\n2. Заучивание перевода русских "
                           "слов\n3. Заучивание написания английских слов\n4. "
                           "Открыть словарь\n5. Посмотреть прогресс\n6. "
                           "Выйти\n");
                    printf("\n-->");
                    enter(&menu);
                    break;
                }
                case 1: {
                    printf("\nВерно!\n");
                    score++;
                    sleep(1);
                    break;
                }
                case 2:
                    printf("\nОшибочка! Правильно-> %s\n", eng[r]);
                    score -= 2;
                    sleep(2);
                    break;
                }
            }
            enter(&menu);
            system("clear");
            break;
        }
        case 4: {
            int q = 1;
            system("clear");
            for (i = 0; i < strok; i++)
                printf("%s - %s\n", eng[i], rus[i]);
            printf("\nДля выхода в главное меню введите 0\n-->");
            enter(&q);
            switch (q) {
            case 0: {
                system("clear");
                printf(">------------------------------------------------------"
                       "-----------<\n   Добро пожаловать в приложение для "
                       "заучивания английских "
                       "слов!\n>-----------------------------------------------"
                       "------------------<\n\n1. Заучивание перевода "
                       "английских слов\n2. Заучивание перевода русских "
                       "слов\n3. Заучивание написания английских слов\n4. "
                       "Открыть словарь\n5. Посмотреть прогресс\n6. Выйти\n");
                printf("\n-->");
                enter(&menu);
                break;
            }
            }
            break;
        }
        case 5: {
            int q = 1, k = 0;
            system("clear");
            printf("Выученные слова:\n");
            for (i = 0; i < strok; i++)
                if (res[i] == 10) {
                    printf("%s\n", eng[i]);
                    k++;
                }
            printf("\nВыучено %d слов(а) из %d\n", k, strok);
            printf("\nДля выхода в главное меню введите 0\n-->");
            enter(&q);
            switch (q) {
            case 0: {
                system("clear");
                printf(">------------------------------------------------------"
                       "-----------<\n   Добро пожаловать в приложение для "
                       "заучивания английских "
                       "слов!\n>-----------------------------------------------"
                       "------------------<\n\n1. Заучивание перевода "
                       "английских слов\n2. Заучивание перевода русских "
                       "слов\n3. Заучивание написания английских слов\n4. "
                       "Открыть словарь\n5. Посмотреть прогресс\n6. Выйти\n");
                printf("\n-->");
                enter(&menu);
                break;
            }
            }
            break;
        }
        case 6: {
            system("clear");
            printf("Всего доброго! Заходите еще!\n");
            wresult(fRes1, strok, res);
            fclose(fRes1);
            return 0;
        }
        default: {
            printf("Неверный ввод. Попробуйте еще.\n");
            sleep(1);
            system("clear");
            printf(">----------------------------------------------------------"
                   "-------<\n   Добро пожаловать в приложение для заучивания "
                   "английских "
                   "слов!\n>---------------------------------------------------"
                   "--------------<\n\n1. Заучивание перевода английских "
                   "слов\n2. Заучивание перевода русских слов\n3. Заучивание "
                   "написания английских слов\n4. Открыть словарь\n5. "
                   "Посмотреть прогресс\n6. Выйти\n");
            printf("\n-->");
            enter(&menu);
            system("clear");
            break;
        }
        }
    }
    return 0;
}

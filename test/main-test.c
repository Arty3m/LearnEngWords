#define CTEST_MAIN
#include <compareansw.h>
#include <ctest.h>
#include <getstring.h>
#include <howstring.h>
#include <howsymbols.h>
#include <randposition.h>
#include <randword.h>
#include <rres.h>
CTEST(howstring, correct_1)
{
    FILE* f;
    f = fopen("test/testfiles/test1.txt", "r");
    int result = 0;
    result = howstring(f);
    rewind(f);
    fclose(f);
    ASSERT_EQUAL(4, result);
}
CTEST(howstring, correct_2)
{
    FILE* f;
    f = fopen("test/testfiles/test1_1.txt", "r");
    int result = 0;
    result = howstring(f);
    rewind(f);
    fclose(f);
    ASSERT_EQUAL(4, result);
}
CTEST(howstring, nonexistentfile)
{
    FILE* f;
    f = fopen("test/testfiles/filenotexist.txt", "r");
    int result = 0;
    result = howstring(f);
    ASSERT_EQUAL(-1, result);
}
CTEST(howsymbols, correct)
{
    FILE* f;
    f = fopen("test/testfiles/test1.txt", "r");
    int result = 0;
    result = howsymbols(f);
    rewind(f);
    fclose(f);
    ASSERT_EQUAL(22, result);
}
CTEST(howsymbols, nonexistentfile)
{
    FILE* f;
    f = fopen("test/testfiles/filenotexist.txt", "r");
    int result = 0;
    result = howsymbols(f);
    ASSERT_EQUAL(-1, result);
}
CTEST(randposition, correct)
{
    int pr[4], strok = 16, k = 0, r = 5, result = 0;
    k = randposition(pr, strok, r);
    if (pr[k - 1] == r)
        result = 0;
    ASSERT_EQUAL(0, result);
}
CTEST(randposition, incorrect)
{
    int p[4], strok = 16, k = 0, r = 3, result = 0;
    k = randposition(p, strok, r);
    if (p[k] != r)
        result = 1;
    ASSERT_EQUAL(1, result);
}
CTEST(randword, correct_1)
{
    int p[10], strok = 10, result = 0;
    for (int i = 0; i < strok; i++)
        p[i] = 0;
    result = randword(strok, p, 10);
    if (result != -1)
        result = 0;
    ASSERT_EQUAL(0, result);
}
CTEST(randword, correct_2)
{
    int p[10], strok = 10, result = 0;
    for (int i = 0; i < strok; i++)
        p[i] = 5;
    result = randword(strok, p, 10);
    if (result != -1)
        result = 0;
    ASSERT_EQUAL(0, result);
}
CTEST(randword, correct_3)
{
    int p[10], strok = 10, result = 0;
    for (int i = 0; i < strok; i++)
        p[i] = 10;
    result = randword(strok, p, 10);
    if (result != -1)
        result = 0;
    ASSERT_EQUAL(-1, result);
}
CTEST(rres, correct)
{
    int p[10], i = 0, result = 0;
    for (i = 0; i < 10; i++)
        p[i] = 20;
    rres(10, p);
    for (i = 0; i < 10; i++)
        if (p[i] == 0)
            result++;
    ASSERT_EQUAL(10, result);
}
CTEST(getstring, correct)
{
    FILE* f;
    f = fopen("test/testfiles/test1.txt", "r");
    int result = 0;
    char p[30], *right = "Hello Man Girl Weather";
    if ((getstring(f, p) == 0) && (strcmp(p, right) == 0))
        result = 0;
    else
        result = -1;
    rewind(f);
    fclose(f);
    ASSERT_EQUAL(0, result);
}
CTEST(getstring, incorrect_1)
{
    FILE* f;
    f = fopen("test/testfiles/test1.txt", "r");
    int result = 0;
    char p[30], *right = "HelloBen";
    if ((getstring(f, p) == 0) && (strcmp(p, right) == 0))
        result = 0;
    else
        result = -1;
    rewind(f);
    fclose(f);
    ASSERT_EQUAL(-1, result);
}
CTEST(getstring, incorrect_2)
{
    FILE* f;
    f = fopen("test/testfiles/test1.txt", "r");
    int result = 0;
    char p[30], *right = "Hallo";
    if ((getstring(f, p) == 0) && (strcmp(p, right) == 0))
        result = 0;
    else
        result = -1;
    rewind(f);
    fclose(f);
    ASSERT_EQUAL(-1, result);
}
CTEST(getstring, incorrect_3)
{
    FILE* f;
    f = fopen("test/testfiles/nonexistentfile.txt", "r");
    int result = 0;
    char p[30];
    result = getstring(f, p);
    ASSERT_EQUAL(-1, result);
}
CTEST(convert, correct)
{
    int result = 0;
    char p[] = "Hello Man Girl Weather";
    char* eng[4];
    for (int i = 0; i < 4; i++)
        eng[i] = (char*)malloc(sizeof(char));
    convert(p, eng);
    if (strcmp(eng[0], "Hello") == 0)
        result++;
    if (strcmp(eng[1], "Man") == 0)
        result++;
    if (strcmp(eng[2], "Girl") == 0)
        result++;
    if (strcmp(eng[3], "Weather") == 0)
        result++;
    ASSERT_EQUAL(4, result);
}
CTEST(convert, incorrect)
{
    int result = 0;
    char p[] = "Hello Man Girl Weather";
    char* eng[4];
    for (int i = 0; i < 4; i++)
        eng[i] = (char*)malloc(sizeof(char));
    convert(p, eng);
    if (strcmp(eng[0], "Hello") == 0)
        result++;
    if (strcmp(eng[1], "Man") == 0)
        result++;
    if (strcmp(eng[2], "Book") == 0)
        result++;
    if (strcmp(eng[3], "Weather") == 0)
        result++;
    ASSERT_EQUAL(3, result);
}
CTEST(compareansw, correct_1)
{
    int r = 1, result = 0;
    char answ[] = "Weather", *arr[4];
    arr[r] = (char*)malloc(sizeof(char));
    arr[r] = "Weather";
    result = compareansw(answ, arr, r);

    ASSERT_EQUAL(1, result);
}
CTEST(compareansw, correct_2)
{
    int r = 1, result = 0;
    char answ[] = "Exit", *arr[4];
    arr[r] = (char*)malloc(sizeof(char));
    arr[r] = "Weather";
    result = compareansw(answ, arr, r);

    ASSERT_EQUAL(0, result);
}
CTEST(compareansw, incorrect)
{
    int r = 1, result = 0;
    char answ[] = "Hello", *arr[4];
    arr[r] = (char*)malloc(sizeof(char));
    arr[r] = "Weather";
    result = compareansw(answ, arr, r);
    ASSERT_EQUAL(2, result);
}
int main(int argc, const char* argv[])
{
    return ctest_main(argc, argv);
}

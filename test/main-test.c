#define CTEST_MAIN
#include <ctest.h>
#include <howstring.h>
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
int main(int argc, const char* argv[])
{
    return ctest_main(argc, argv);
}

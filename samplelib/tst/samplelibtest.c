#include "common/MinUnit.h"
#include "samplelib/src/samplelib.h"

int tests_run = 0;

static PCHAR test1() {
    MU_ASSERT("justATestMethod", 1==1);
    return 0;
}

static PCHAR test2() {
    MU_ASSERT("It should failed", 1==1);
    return 0;
}

static PCHAR all_tests() {
    MU_RUN_TEST(test1);
    MU_RUN_TEST(test2);
    return 0;
}

int main (int argc, char** argv) {
    PCHAR result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}


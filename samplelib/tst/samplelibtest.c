#include "common/MinUnit.h"
#include "samplelib/src/samplelib.h"

int tests_run = 0;

static PCHAR test1() {
    MU_ASSERT("justATestMethod", 1==1);
    return NULL;
}

static PCHAR test2() {
    MU_ASSERT("It should failed", 1==1);
    return NULL;
}

static PCHAR all_tests() {
    MU_RUN_TEST(test1);
    MU_RUN_TEST(test2);
    return NULL;
}

MU_RUN_TESTS(all_tests);


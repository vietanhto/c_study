#ifndef COMMON_MINUNIT_H
#define COMMON_MINUNIT_H

#include "CommonDefinitions.h"

#define MU_ASSERT(message, test) do{if(!(test)) return message;} while (0)
#define MU_RUN_TEST(test) do { PCHAR message = test(); tests_run++; \
                            if (message) return message; } while (0)

#define MU_RUN_TESTS(name) int main (int argc, char** argv) { \
    printf("Running test %s\n", argv[0]); \
    PCHAR result = all_tests(); \
    if (result != 0) { \
        printf("%s\n", result); \
    } else { \
        printf("ALL TESTS PASSED\n"); \
    } \
    printf("Tests run: %d\n", tests_run); \
    return result != 0;\
}

extern int tests_run;

#endif // COMMON_MINUNIT_H
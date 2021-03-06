#ifndef COMMON_MINUNIT_H
#define COMMON_MINUNIT_H

#include "CommonDefinitions.h"
#include "Debug.h"

#define MU_ASSERT(message, test) do{if(!(test)) return message;} while (0)
#define MU_RUN_TEST(test) do { PCHAR message = test(); tests_run++; \
                            if (message) return message; } while (0)

#define MU_RUN_TESTS(name) int main (int argc, char** argv) { \
    printf("Running test %s\n", argv[0]); \
    PCHAR result = all_tests(); \
    if (result != 0) { \
        printf(COLOR_RED "%s\n" COLOR_RESET, result); \
    } else { \
        printf(COLOR_GREEN "ALL TESTS PASSED\n" COLOR_RESET); \
    } \
    printf("Tests run: %d\n", tests_run); \
    return result != 0;\
}

extern int tests_run;

#endif // COMMON_MINUNIT_H
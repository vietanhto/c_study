#include "samplelib.h"

int main () {
    CHAR message[9] = "It works";
    printf("Hello world!\n");
    printf("%s\n", message);
    return 0;
}

UINT32 justATestMethod(UINT32 first, UINT32 second) {
    return first + second;
}
#include "string.h"

void rm_left_space(char *s) {
    char *sPtr = s;
    while (*sPtr == ' ') {
        ++sPtr;
    }

    while (*sPtr != '\0') {
        *s = *sPtr;
        ++s;
        ++sPtr;
    }

    *s = '\0';
}

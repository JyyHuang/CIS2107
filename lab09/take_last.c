#include "string.h"

void take_last(char *s, int n) {
    int length = 0;
    for (char *sPtr = s; *sPtr != '\0'; ++sPtr) {
        ++length;
    }
    if (n >= length) {
        return;
    }

    int i = 0;
    int j = length - n;
    while (j < length) {
        s[i] = s[j];
        ++i;
        ++j;
    }
    s[i] = '\0';
}

#include "string.h"

int num_in_range(char *s1, char b, char t) {
    int count = 0;
    for (char *sPtr = s1; *sPtr != '\0'; ++sPtr) {
        if (*sPtr >= b && *sPtr <= t) {
            ++count;
        }
    }
    return count;
}

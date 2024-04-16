#include "string.h"

int diff(char *s1, char *s2) {
    int count = 0;
    char *s1Ptr = s1;
    char *s2Ptr = s2;

    while (*s1Ptr != '\0' && *s2Ptr != '\0') {
        if (*s1Ptr != *s2Ptr) {
            ++count;
        }
        ++s1Ptr;
        ++s2Ptr;
    }

    // If one string is larger than the other
    while (*s1Ptr != '\0') {
        ++count;
        ++s1Ptr;
    }

    while (*s2Ptr != '\0') {
        ++count;
        ++s2Ptr;
    }

    return count;
}

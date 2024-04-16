#include "string.h"

int len_diff(char *s1, char *s2) {
    int s1_len = 0, s2_len = 0;

    for (char *s1Ptr = s1; *s1Ptr != '\0'; ++s1Ptr) {
        ++s1_len;
    }

    for (char *s2Ptr = s2; *s2Ptr != '\0'; ++s2Ptr) {
        ++s2_len;
    }
    
    return s1_len - s2_len;
}

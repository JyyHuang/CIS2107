#include "string.h"

void rm_right_space(char *s) {
    int s_len = 0;
    while (*s != '\0') {
        ++s;
        ++s_len;
    }

    while (*(s - 1) == ' ' && s_len > 0) {
        --s;
        --s_len;
    }

    *s = '\0';
}

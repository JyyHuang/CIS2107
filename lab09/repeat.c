#include "string.h"
#include <stdlib.h>

char *repeat(char *s, int x, char sep) {
    if (s == NULL) {
        return NULL;
    }

    int s_len = 0;
    for (int i = 0; s[i] != '\0'; ++i)
        ++s_len;

    char *str_builder = (char *)malloc((s_len * x) + x);
    int index = 0;

    for (int i = 0; i < x; ++i) {
        for (int j = 0; s[j] != '\0'; ++j) {
            str_builder[index] = s[j];
            ++index;
        }
        if (i < x - 1) {
            str_builder[index] = sep;
            ++index;
        }
    }

    str_builder[index] = '\0';

    return str_builder;
}

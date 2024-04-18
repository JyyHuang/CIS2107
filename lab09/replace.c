#include "string.h"
#include <stdlib.h>

char *replace(char *s, char *pat, char *rep) {
    if (s == NULL || pat == NULL || rep == NULL)
        return NULL;

    int occurences = 0, pat_len = 0, rep_len = 0, s_len = 0;

    // Get occurences
    for (int i = 0; s[i]; ++i) {
        int j;
        for (j = 0; pat[j]; ++j) {

            if (s[i + j] != pat[j]) {
                break;
            }
        }
        if (pat[j] == '\0') {
            ++occurences;
            i = i + j - 1;
        }
    }

    // Get lengths
    for (int i = 0; s[i]; ++i)
        ++s_len;
    for (int i = 0; pat[i]; ++i)
        ++pat_len;
    for (int i = 0; rep[i]; ++i)
        ++rep_len;

    int str_builder_len = s_len + (occurences * (rep_len - pat_len)) + 1;
    char *str_builder = (char *)malloc(str_builder_len);
    int str_builder_index = 0;

    for (int i = 0; s[i]; ++i) {
        int j;
        for (j = 0; pat[j]; ++j) {
            if (s[i + j] != pat[j]) {
                break;
            }
        }

        if (pat[j] == '\0') {
            for (int k = 0; rep[k]; ++k) {
                str_builder[str_builder_index] = rep[k];
                ++str_builder_index;
            }

            i += j - 1;
        } else {
            str_builder[str_builder_index] = s[i];
            ++str_builder_index;
        }
    }

    str_builder[str_builder_index] = '\0';

    return str_builder;
}

#include "string.h"
#include <stdlib.h>

char *str_zip(char *s1, char *s2) {
    int total_length = 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        ++total_length;
    }

    for (int i = 0; s2[i] != '\0'; ++i) {
        ++total_length;
    }

    char *new_string = (char *)malloc((total_length + 1) * sizeof(char));

    char * temp = new_string;

    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != '\0') {
            *new_string = *s1;
            ++s1;
            ++new_string;
        }
        if (*s2 != '\0') {
            *new_string = *s2;
            ++s2;
            ++new_string;
        }
    }
    *new_string = '\0';

    return temp;
}

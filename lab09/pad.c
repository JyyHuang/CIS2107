#include "string.h"
#include <stdlib.h>

char *pad(char *s, int d) {
    if (s == NULL) {
        return NULL;
    }
    int length = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        ++length;
    }

    int spaces = d - (length % d);

    int new_length = length + spaces;

    char *str_builder = (char *)malloc((new_length + 1) * sizeof(char));

    if (str_builder == NULL) {
        return NULL;
    }

    for (int i = 0; s[i] != '\0'; ++i) {
        str_builder[i] = s[i];
    }

    if (length % d == 0) {
        return str_builder;
    }

    for (int i = length; i < new_length; ++i) {
        str_builder[i] = ' ';
    }

    str_builder[new_length] = '\0';

    return str_builder;
}

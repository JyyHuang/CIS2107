#include "string.h"
#include <stdlib.h>

void rm_empties(char **words) {
    int curr = 0;

    for (int i = 0; words[i] != NULL; ++i) {
        int length = 0;
        for (int j = 0; words[i][j] != '\0'; ++j) {
            ++length;
        }
        if (length > 0) {
            words[curr] = words[i];
            ++curr;
        }
    }
    words[curr] = NULL;
}

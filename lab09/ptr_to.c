#include "string.h"
#include <stdlib.h>

char *ptr_to(char *h, char *n) {
    for (int i = 0; h[i] != '\0'; ++i) {
        int j;
        for (j = 0; n[j] != '\0'; ++j) {
            if (h[i + j] != n[j]) {
                break;
            }
        }
        if (n[j] == '\0') {
            return &h[i];
        }
    }
    return NULL;
}

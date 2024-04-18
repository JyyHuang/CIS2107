#include "string.h"

int find(char *h, char *n) {
    for (int i = 0; h[i] != '\0'; ++i) {
        int j;
        for (j = 0; n[j] != '\0'; ++j) {
            if (h[i + j] != n[j]) {
                break;
            }
        }
        if (n[j] == '\0') {
            return i;
        }
    }
    return -1;
}

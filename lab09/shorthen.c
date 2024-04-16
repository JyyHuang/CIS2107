#include "string.h"

void shorten(char *s, int new_len){
    int curr_len = 0;
    while (*s != '\0') {
        ++curr_len;
    }

    if (curr_len > new_len) {
        *(s + new_len) = '\0';
    }
    
}

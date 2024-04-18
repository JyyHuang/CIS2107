#include "string.h"

void shorten(char *s, int new_len){
    int curr_len = 0;
    char* sPtr = s;
    while (*sPtr != '\0') {
        ++curr_len;
        ++sPtr;
    }

    if (curr_len > new_len) {
        *(s + new_len) = '\0';
    }
    
}

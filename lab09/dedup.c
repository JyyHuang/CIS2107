#include "string.h"
#include <stdlib.h>

char *dedup(char *s) {
    // array for seen chars
    int seen[256] = {0};

    // get size of s
    int length = 0;
    for (int i = 0; s[i] != '\0'; ++i){
        ++length;
    }
    
    char* str_builder = (char*)malloc((length + 1) * sizeof(char));

    char* temp = str_builder;

    for (char* sPtr = s; *sPtr != '\0'; ++sPtr) {
        if (!seen[*sPtr]){
            *str_builder = *sPtr;
            ++str_builder;
            seen[*sPtr] = 1;
        }
    }

    *str_builder = '\0';

    return temp;
}

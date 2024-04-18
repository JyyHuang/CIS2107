#include "string.h"
#include <stddef.h>

int is_empty(char *s){
    if (s == NULL) return 1;

    for (char* sPtr = s; *sPtr != '\0'; ++sPtr) {
        if (*sPtr != ' '){
            return 0;
        }
    }
    return 1;
}

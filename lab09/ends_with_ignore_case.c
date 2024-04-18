#include "string.h"
#include <ctype.h>

int ends_with_ignore_case(char *s, char *suff){
    int s_len = 0;
    int suff_len = 0;

    for (int i = 0; s[i]; ++i) ++s_len;
    for (int i = 0; suff[i]; ++i) ++suff_len;
    
    if (suff_len > s_len){
        return 0;
    }

    for (int i = 0; i < suff_len; ++i) {
        if(tolower(s[s_len - suff_len + i]) != tolower(suff[i])){
            return 0;
        }
    }

    return 1;
}

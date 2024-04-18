#include "string.h"
#include <stdlib.h>

char **str_chop_all(char *s, char c){
    int len = 0;
    while (s[len] != '\0') ++len;

    int occurences = 0;
    for (int i = 0; i <= len; ++i){
        if (s[i] == c || s[i] == '\0'){
            ++occurences;
        }
    }

    char** result = (char**) malloc((occurences + 1) * sizeof(char*));
    int index = 0;
    int start = 0;

    for (int i = 0; i <= len; ++i) {
        if (s[i] == c || s[i] == '\0'){
            int token_len = i - start;
            result[index] = (char *) malloc((token_len + 1) * sizeof(char));


            for (int j = 0; j < token_len; ++j) {
                result[index][j] = s[start + j];
            }
            result[index][token_len] = '\0';

            ++index;
            start = i + 1;
        }
    }
    result[index] = NULL;

    return result;
}

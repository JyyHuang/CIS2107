#include "string.h"
#include <stdlib.h>

char *str_connect(char **strs, int n, char c){
    int str_lengths = 0;
    int words = 0;
    for (int i = 0; i < n ; ++i) {
        if (strs[i] == NULL){
            return NULL;
        }
        for (int j = 0; strs[i][j] != '\0'; ++j) {
            ++str_lengths;
        }
        
    }

    char* str_builder = (char*) malloc(str_lengths + (n-1) + 1);
    int index = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; strs[i][j] != '\0'; ++j) {
            str_builder[index] = strs[i][j];
            ++index;
        }
        if (i < n - 1){
            str_builder[index] = c;
            ++index;
        }
    }

    str_builder[index] = '\0';

    return str_builder;
}

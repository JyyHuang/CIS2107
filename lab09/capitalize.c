#include "string.h"
#include <ctype.h>

void capitalize(char *s) {
    int i = 0;
    int flag = 1;

    while (s[i]) {
        if (flag && isalpha(s[i])) {
            s[i] = toupper(s[i]);
            flag = 0;
        } else {
            s[i] = tolower(s[i]);
        }

        if (s[i] == ' ') {
            flag = 1;
        }
        ++i;
    }
}

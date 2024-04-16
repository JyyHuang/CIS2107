#include "string.h"

int all_letters(char *s) {
    // iterate through the string and check if the characters fall between the
    // ascii values
    for (char *sPtr = s; *sPtr != '\0'; ++sPtr) {
        if (*sPtr == 32)
            continue;
        if (!((*sPtr >= 65 && *sPtr <= 90) ||
              ((*sPtr >= 97 && *sPtr <= 122)))) {
            return 0;
        }
    }
    return 1;
}

#include "string.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Test all_letters
    puts("Test for all_letters:");
    puts("Input: Hello World");
    printf("%d\n", all_letters("Hello World")); // prints 1
    puts("Input: He11o World");
    printf("%d\n\n", all_letters("He11o World")); // prints 0

    // Test num_in_range
    puts("Test for num_in_range");
    puts("Input: Yellow , f, m");
    printf("%d\n\n", num_in_range("Yellow", 'f', 'm')); // prints 2

    // Test diff
    puts("Test for diff");
    puts("Input: Book, Back");
    printf("%d\n\n", diff("Book", "Back")); // prints 2

    // Test shorten
    puts("Test for shorten");
    char *shorten_word = "Hello World";
    puts("Original Word: ");
    printf("%s\n", shorten_word); // prints Hello World
    shorten(shorten_word, 5);
    puts("Word after shorten with input of 5");
    printf("%s\n\n", shorten_word); // prints Hello

    // Test len_diff
    puts("Test for len_diff");
    puts("Input: Philadelphia, Hello");
    printf("%d\n\n", len_diff("Philadelphia", "Hello")); // prints 7

    // Test rm_left_space
    puts("Test for rm_left_space");
    puts("Input:      Hello");
    char *left_space_word = "     Hello";
    rm_left_space(left_space_word);
    printf("%s\n\n", left_space_word); // prints Hello

    // Test rm_right_space
    puts("Test for rm_right_space");
    puts("Input: Hello     ");
    char *right_space_word = "Hello     ";
    rm_right_space(right_space_word);
    printf("%s\n\n", right_space_word); // prints Hello

    // Test rm_space
    puts("Test for rm_space");
    puts("Input:      Hello     ");
    char *space_word = "     Hello     ";
    rm_space(space_word);
    printf("%s\n\n", space_word); // prints Hello
}

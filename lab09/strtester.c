#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Test all_letters
    puts("Test for all_letters:");
    puts("Input: Hello World");
    printf("Output: %d\n", all_letters("Hello World")); // prints 1
    puts("Input: He11o World");
    printf("Output: %d\n\n", all_letters("He11o World")); // prints 0

    // Test num_in_range
    puts("Test for num_in_range");
    puts("Input: Yellow , f, m");
    printf("Output: %d\n\n", num_in_range("Yellow", 'f', 'm')); // prints 2

    // Test diff
    puts("Test for diff");
    puts("Input: Book, Back");
    printf("Output: %d\n\n", diff("Book", "Back")); // prints 2

    // Test shorten
    puts("Test for shorten");
    puts("Input: Hello World, 5");
    char shorten_word[] = "Hello World";
    shorten(shorten_word, 5);
    printf("Output: %s\n", shorten_word); // prints Hello

    char shorten_word2[] = "Hello World";
    puts("Input: Hello World, 20");
    shorten(shorten_word2, 20);
    printf("Output: %s\n\n", shorten_word2); // prints Hello World

    // Test len_diff
    puts("Test for len_diff");
    puts("Input: Philadelphia, Hello");
    printf("Output: %d\n\n", len_diff("Philadelphia", "Hello")); // prints 7

    // Test rm_left_space
    puts("Test for rm_left_space");
    puts("Input:      Hello");
    char left_space_word[] = "     Hello";
    rm_left_space(left_space_word);
    printf("Output: %s\n\n", left_space_word); // prints Hello

    // Test rm_right_space
    puts("Test for rm_right_space");
    puts("Input: Hello     ");
    char right_space_word[] = "Hello     ";
    rm_right_space(right_space_word);
    printf("Output: %s\n\n", right_space_word); // prints Hello

    // Test rm_space
    puts("Test for rm_space");
    puts("Input:      Hello     ");
    char space_word[] = "     Hello     ";
    rm_space(space_word);
    printf("Output: %s\n\n", space_word); // prints Hello

    // Test find
    puts("Test for find");
    puts("Input: Hello , l");
    printf("Output: %d\n", find("Hello ", "l")); // prints 2
    puts("Input: Hello , q");
    printf("Output: %d\n\n", find("Hello ", "q")); // prints -1

    // Test ptr_to
    puts("Test for ptr_to");
    puts("Input: Hello , l");
    printf("Output: %p\n", ptr_to("Hello ", "l")); // prints pointer to l
    puts("Input: Hello , q");
    printf("Output: %p\n\n", ptr_to("Hello ", "q")); // prints NULL

    // Test is_empty
    puts("Test for is_empty");
    puts("Input: \" \"");
    printf("Output: %d\n", is_empty(" ")); // prints 1
    puts("Input: Hello");
    printf("Output: %d\n\n", is_empty("Hello")); // prints 0

    // Test for str_zip
    puts("Test for str_zip");
    puts("Input: Temple, Hello");
    char *zip_test = str_zip("Temple", "Hello");
    printf("Output: %s\n", zip_test); // prints THeemlplloe
    puts("Input: Spongebob, Patrick");

    char *zip_test2 = str_zip("Spongebob", "Patrick");
    printf("Output: %s\n\n", zip_test2); // prints SPpaotnrgiecbkob
    free(zip_test);
    free(zip_test2);

    // Test for capitalize
    puts("Test for capitalize");
    puts("Input: hello world");
    char cap_word[] = "hello world";
    capitalize(cap_word);
    printf("Output: %s\n\n", cap_word); // prints Hello World

    // Test for strcmp_ign_case
    puts("Test for strcmp_ign_case");
    puts("Input: hello, goodbye");
    printf("Output: %d\n", strcmp_ign_case("hello", "goodbye")); // prints 1
    puts("Input: Hello, hello");
    printf("Output: %d\n\n", strcmp_ign_case("Hello", "hello")); // prints 0

    // Test for take_last
    puts("Test for take_last");
    puts("Input: hello, 3");
    char last_word[] = "hello";
    take_last(last_word, 3);
    printf("Output: %s\n", last_word); // prints llo

    puts("Input: hello, 6");
    char last_word2[] = "hello";
    take_last(last_word2, 6);
    printf("Output: %s\n\n", last_word2); // prints hello

    // Test dedup
    puts("Test for dedup");
    puts("Input: hello");
    char *dedup_word = dedup("hello");
    printf("Output; %s\n\n", dedup_word); // prints helo
    free(dedup_word);

    // Test for pad
    puts("Test for pad");
    puts("Input: hello, 6");
    char *pad_word = pad("hello", 6);
    printf("Output: %s.\n", pad_word); // prints hello' '
    puts("Input: hello, 5");
    char *pad_word2 = pad("hello", 5);
    printf("Output: %s.\n\n", pad_word2); // prints hello
    free(pad_word);
    free(pad_word2);

    // Test for ends_with_ignore_case
    puts("Test for ends_with_ignore_case");
    puts("Input: Coding, ing");
    printf("Output: %d\n", ends_with_ignore_case("Coding", "ing")); // prints 1
    puts("Input: Coding, ed");
    printf("Output: %d\n\n", ends_with_ignore_case("Coding", "ed")); // prints 0

    // Test for repeat
    puts("Test for repeat");
    puts("Input: hello, 3, -");
    char *repeat_word = repeat("hello", 3, '-');
    printf("Output: %s\n\n", repeat_word); // prints 1
    free(repeat_word);

    // Test for replace
    puts("Test for replace");
    puts("Input: Steph is the X, X, best");
    char *replace_word = replace("Steph is the X", "X", "best");
    printf("Output: %s\n\n", replace_word); // prints Steph is the best
    free(replace_word);

    // Test for str_connect
    puts("Test for str_connect");
    puts("Input: [Hello, world, Hello, world], 4, -");
    char *strs[] = {"Hello", "world", "Hello", "world"};
    char *connect_word = str_connect(strs, 4, '-');
    printf("Output: %s\n\n", connect_word); // prints Hello-world-Hello-world
    free(connect_word);

    // Test for rm_empties
    puts("Test for rm_empties");
    puts("Input: [Hello, World, , , Steph]");
    char *empties_word[] = {"Hello", "World", "", "", "Steph", NULL};
    rm_empties(empties_word);
    printf("%s", "Output: ");
    for (int i = 0; empties_word[i] != NULL; ++i) {
        printf("%s ", empties_word[i]);
    }
    // prints Hello World Steph
    puts("\n");

    // Test for str_chop_all
    puts("Test for str_chop_all");
    puts("Input: Hello/world/hello/world, /");
    char *chop_word = "Hello/world/hello/world";
    char** chop_arr = str_chop_all(chop_word, '/');
    printf("%s", "Output: ");
    for (int i = 0; chop_arr[i] != NULL; ++i) {
        printf("%s ", chop_arr[i]);
    }
    // prints Hello world hello world
    puts("\n");

}

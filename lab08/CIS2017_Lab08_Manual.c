/*
 * Name:	Joey Huang 
 * Date:    3/27/2024
 * Section:	002 
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    for (int i = 0; s[i] != '\0'; ++i){
        printf("%c", toupper(s[i]));
    }
    puts("");
    for (int i = 0; s[i] != '\0'; ++i){
        printf("%c", tolower(s[i]));
    }
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4); 
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atof(s1) + atof(s2) + atof(s3) + atof(s4);  
}

// 4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    if (strcmp(s1, s2) == 0){
        printf("\n%s == %s\n", s1, s2);
    }
    else if (strcmp(s1, s2) < 0){
        printf("\n%s < %s\n", s1, s2);
    }
    else{
        printf("\n%s > %s\n", s1, s2);
    }
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    printf("\n\nComparison of first %d chars: ", n);
    if (strncmp(s1, s2, n) == 0){
        printf("\n%s == %s\n", s1, s2);
    }
    else if (strncmp(s1, s2, n) < 0){
        printf("\n%s < %s\n", s1, s2);
    }
    else{
        printf("\n%s > %s\n", s1, s2);
    }
}

//6.(Random Sentences) 
void randomize(void) {
    srand(time(NULL));
    char* article[] = {"the", "a", "one", "some", "any"};
    char* noun[] = {"boy", "girl", "dog", "town", "car"};
    char* verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char* preposition[] = {"to", "from", "over", "under", "on"};
    char sentence[35];

    for (int i = 0; i < 20; ++i) {
        snprintf(sentence, sizeof(sentence), "%s %s %s %s %s %s.", article[rand() % 5], noun[rand() % 5], verb[rand() % 5], preposition[rand() % 5], article[rand() % 5], noun[rand() % 5]);
        sentence[0] = toupper(sentence[0]);
        printf("\n%s", sentence);
    }
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    int tokens[3] = {0};
    int i = 0;
    char* token = strtok(num, " -()");
    
    while (token != NULL){
        tokens[i++] = atoi(token);
        token = strtok(NULL, " -()");
    }
    int areaCode = tokens[0];
    long threeDigit = (long) tokens[1];
    long fourDigit = (long) tokens[2];
    printf("\n\n%d %ld%ld\n\n", areaCode, threeDigit, fourDigit);
    return 0;
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char* token = strtok(text, " ");
    // char array of 100 strings
    char* words[100];
    int numWords = 0;
    while (token != NULL && numWords < 100){
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }
    for (int i = numWords - 1; i >= 0; --i) {
        printf("%s ", words[i]);
    }
    puts("");
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
  
  
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
  
  
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
 
 
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
   
   
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {

 

}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {


}

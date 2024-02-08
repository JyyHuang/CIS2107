#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Joey Huang
 * 2/06/2024
 * CIS 2107
 * Lab 04 1D Arrays 
 * 
 * Design and implement functions to process 1D Arrays.
 */

// Macros
#define SIZE 40
#define RAND_MIN 0
#define RAND_MAX 100

// Function prototypes
void fillArray(int array[], int size);
int findWithRange(int array[], int lowSelectedRange, int highSelectedRange, int size);
void printArray(int array[], int size);
void reverseArray(int array[], int size);
void reverseSelectedRangeWithinArray(int array[], int startRange, int endRange, int size);

// main
int main(int argc, char *argv[])
{
    int array[SIZE];

    // Test fillArray
    printf("%s", "*** Testing fillArray function ***\n");
    fillArray(array, SIZE);
    puts("Your Random Array: ");
    printArray(array, SIZE);
    puts("\n");

    // Test findWithRange
    printf("%s", "*** Testing findWithRange function ***\n");
    int lowSelectedRange = 10;
    int highSelectedRange = 19;
    int max = findWithRange(array, lowSelectedRange, highSelectedRange, SIZE);
    printf("Find max in range %d-%d:\n", lowSelectedRange, highSelectedRange);
    printArray(array, SIZE);
    printf("Max = %d\n\n\n", max);

    // Test reverseArray 
    printf("%s", "*** Testing reverseArray function ***\n");
    puts("Original: ");
    printArray(array, SIZE);
    reverseArray(array, SIZE);
    puts("Reversed: ");
    printArray(array, SIZE);

    // Reverse again to get back to original array
    reverseArray(array, SIZE);
    puts("");
    puts("");

    // Test reverseSelectedRangeWithinArray
    printf("%s", "*** Testing reverseSelectedRangeWithinArray function ***\n");
    int startRange = 10;
    int endRange = 19;
    printf("Reversing array from index %d to index %d:\n",startRange, endRange);
    puts("Original: ");
    printArray(array, SIZE);
    reverseSelectedRangeWithinArray(array, startRange, endRange, SIZE);
    puts("Reversed: ");
    printArray(array, SIZE);



    return 0;
}

// Fill array with random numbers
void fillArray(int array[], int size){
    if (size <= 0){
        puts("Error: Size must be greater than 0.");
        exit(1);
    }

    srand( (unsigned) time(NULL));

    for (size_t i = 0; i < size; i++){
        array[i] = rand() % (RAND_MAX + 1) + RAND_MIN;
    }
}

// Find max element in specified range
int findWithRange(int array[], int lowSelectedRange, int highSelectedRange, int size){
    if (lowSelectedRange < 0 || highSelectedRange < 0 || lowSelectedRange >= size || highSelectedRange >= size || lowSelectedRange > highSelectedRange){
        puts("Error: Range is not valid");
        exit(1);
    }

    // Set max to first element in range
    size_t max = array[lowSelectedRange];

    for (int i = lowSelectedRange + 1; i <= highSelectedRange; i++){
        if (max < array[i]){
            max = array[i];
        }
    }
    return max;
}

// Reverse Array
void reverseArray(int array[], int size){
    if (size <= 0){
        puts("Error: Size must be greater than 0.");
        exit(1);
    }

    // Two pointers reversal
    int l = 0;
    int r = size - 1;
    while (l < r){
        int temp = array[l];
        array[l] = array[r];
        array[r] = temp;
        ++l;
        --r;
    }
}

// Reverse Array within a Range
void reverseSelectedRangeWithinArray(int array[], int startRange, int endRange, int size){
    if (startRange < 0 || endRange < 0 || startRange >= size || endRange >= size || startRange > endRange){
        puts("Error: Range is not valid");
        exit(1);
    }

    // Two pointers reversal
    int l = startRange;
    int r = endRange;
    while (l < r){
        int temp = array[l];
        array[l] = array[r];
        array[r] = temp;
        ++l;
        --r;
    }
}

// Find Sequence Among Array
int findSequence(int array[]){

}

// Helper function to print array
void printArray(int array[], int size){
    if (size <= 0){
        puts("Error: Size must be greater than 0.");
        exit(1);
    }

    printf("%s","[\n");

    for (size_t i = 0; i < size; i++){
        if(i % 10 == 0 && i != 0 && i != size - 1){
            puts("");
        }
        printf("%4d", array[i]);
    }
    printf("%s", "\n]\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Joey Huang
 * 2/15/2024
 * CIS 2107
 * Lab 05 2D Arrays 
 * 
 * To design and implement functions to process 2DArrays.
 */

#define ROWS 2
#define COLS 3
#undef max

// function prototypes
int max(const int array[][COLS]);
int rowSum(const int array[][COLS], size_t col);
int columnSum (const int array[][COLS], size_t row);
int isSquare (const int array[][COLS]);
void displayOutputs(const int array[][COLS]);


int main(int argc, char *argv[])
{
    int array[ROWS][COLS] = {{1,1,3}, {1,1,}};
    printf("%d", max(array));
    return 0;
}

// max function
// init max to INT_MAX and iterate over 2D array and update max
int max(const int array[][COLS]){
    int curr = INT_MIN;
    for (size_t i = 0; i < ROWS; i++){
        for (size_t j = 0; j < COLS; j++){
            if (array[i][j] > curr){
                curr = array[i][j];
            }
        }
    }
    return curr;
}

int rowSum(const int array[][COLS], size_t row){
    int sum = 0;
    for (size_t j = 0; j < COLS; j ++){
        sum += array[row][j];
    }
    return sum;
}

int columnSum(const int array[][COLS], size_t col){
    int sum = 0;
    for (size_t i = 0; i < ROWS; i++){
        sum += array[i][col];
    }
    return sum;
}

int isSquare(const int array[][COLS]){
    size_t numRows = 0;
    size_t numCols = 0;
    for (size_t i = 0; i < ROWS; i++){
        numRows++;
    }
    for (size_t j = 0; j < COLS; j++){
        numCols++;
    }

    return numRows == numCols;
}

void displayOutputs(const int array[][COLS]){
    puts("[ ");
    
    for (size_t i = 0; i < ROWS; i++){
        puts("[ ");
        for (size_t j = 0; j < COLS; j++){
            printf("%d", array[i][j] + " ");
        }
        puts("]");
    }
}

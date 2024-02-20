#include <stdio.h>

/* Joey Huang
 * 2/15/2024
 * CIS 2107
 * Lab 05 2D Arrays 
 * 
 * To design and implement functions to process 2DArrays.
 */

static size_t rows = 0;
static size_t cols = 0;

// function prototypes
int max(const int array[][cols]);
int rowSum(const int array[][cols], size_t col);
int columnSum (const int array[][cols], size_t row);
int isSquare (size_t rows, size_t cols);
void displayOutputs(const int array[][cols]);


int main(int argc, char *argv[])
{   
    puts("Let's create a 2Dim array!");
    printf("%s", "\n\tHow many rows? ");
    scanf("%zu", &rows);
    printf("%s", "\tHow many columns? ");
    scanf("%zu", &cols);
    puts("");

    int array[rows][cols];
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            printf("\tenter [%zu][%zu]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    puts("");

    printf("Max value in array: %d\n\n", max(array));
    
    for (size_t i = 0; i < rows; i++){
        printf("Sum of row %zu = %d\n", i + 1, rowSum(array, i));
    }
    puts("");

    for (size_t j = 0; j < cols; j++){
        printf("Sum of column %zu = %d\n", j + 1, columnSum(array, j));
    }
    puts("");

    printf("This is %sa square array.\n\n", isSquare(rows, cols) ? "" : "not ");

    displayOutputs(array);

    return 0;
}

// max function
// init max to first element and iterate over 2D array and update max
int max(const int array[][cols]){
    int curr = array[0][0];
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            if (array[i][j] > curr){
                curr = array[i][j];
            }
        }
    }
    return curr;
}

int rowSum(const int array[][cols], size_t row){
    int sum = 0;
    for (size_t j = 0; j < cols; j ++){
        sum += array[row][j];
    }
    return sum;
}

int columnSum(const int array[][cols], size_t col){
    int sum = 0;
    for (size_t i = 0; i < rows; i++){
        sum += array[i][col];
    }
    return sum;
}

int isSquare(size_t num_rows, size_t num_cols){
    return num_rows == num_cols;
}

void displayOutputs(const int array[][cols]){
    puts("Here is your 2Dim array:");
    for (size_t i = 0; i < rows; i++){
        printf("%c", '[');
        for (size_t j = 0; j < cols; j++){
            if (j == (cols - 1)){
                printf("%d", array[i][j]);
            } else{
                printf("%d, ", array[i][j]);
            }
        }
        puts("]");
    }
}

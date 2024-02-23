/* 
Name: Joey Huang 
Date: 02/20/2024
Course: CIS2107 
HW#: Lab 05: ““Arrays of Pointers to Functions” 

Objective: To design and implement array of function pointer. 

The purpose of this program is to modify existing code related to examslecting 
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average. 

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/

#include <stdio.h>
#include <stdlib.h>

// function prototypes
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main()
{
    // Get num of students and exams
    int students, exams = 0;
    printf("%s", "Enter the number of students: ");
    scanf("%d", &students);
    printf("%s", "Enter the number of exams for each student: ");
    scanf("%d", &exams);

    // Get grades
    int grades[students][exams];
    for (size_t i = 0; i < students; ++i){
        for (size_t j = 0; j < exams; ++j){
            printf("Enter exam %zu grade for student %zu: ", j + 1, i + 1);
            scanf("%d", &grades[i][j]);
        }
    }
    
    // Initialize array of pointers to functions
    void (*processGrades[4])(int students, int exams, int grades[students][exams]) = {printArray, minimum, maximum, average};

    // menu loop
    size_t choice;
    while (1)
    {
        puts("\nEnter a choice: ");
        puts("\t0 Print the array of grades");
        puts("\t1 Find the minimum grade");
        puts("\t2 Find the maximum grade"); 
        puts("\t3 Print the average on all tests for each student");
        puts("\t4 End Program");
        scanf("%zu", &choice);
        puts("");
        if (choice == 4){
            exit(0);
        }
        (*processGrades[choice])(students, exams, grades); 
    }
     
}

// print array
void printArray(int students, int exams, int grades[students][exams]){
    puts("The array is: ");
    printf("%s", "        ");
    for (size_t k = 0; k < exams; k++){
        printf("\t[%zu]", k);
    }
    for (size_t i = 0; i < students; ++i){
        printf("\ngrades[%zu]", i);
        for (size_t j = 0; j < exams; ++j){
            printf("\t%d",grades[i][j]);
        }
    }
    puts("");
}

// Print minimum grade
void minimum(int students, int exams, int grades[students][exams]){
    // start at highest possible grade
    int lowGrade = 100;

    for (size_t i = 0; i < students; ++i){
        for (size_t j = 0; j < exams; ++j){
            if (grades[i][j] < lowGrade){
                lowGrade = grades[i][j];
            }
        }
    }
    printf("Lowest Grade: %d\n", lowGrade);
}

// Print maximum grade
void maximum(int students, int exams, int grades[students][exams]){
    // start at lowest possible grade
    int highGrade = 0;

    for (int i =0; i < students; ++i){
        for (int j = 0; j < exams; ++j){
            if (grades[i][j] > highGrade){
                highGrade = grades[i][j];
            }
        }
    }
    printf("Highest Grade: %d\n", highGrade);
}

//Find average
void average(int students, int exams, int grades[students][exams]){
    for (int i = 0; i < students; ++i){
        float curr_sum = 0;
        for (int j = 0; j < exams; j++){
            curr_sum += grades[i][j];
        }
        float average = curr_sum / exams;
        printf("The average for student %d is %.2f\n",i + 1, average);
    }
}

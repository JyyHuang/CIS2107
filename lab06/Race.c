l//Joey Huang
//02/28/2024
//CIS2017 Lab7: Race
//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);
int min(int hMin, int tMin);

int main(){
    srand((unsigned)time(NULL));

    int hPos =1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos != 70 && tPos!=70){
        sleep(1);						//slows down the race
        hareMove(&hPos);
        tortMove(&tPos);    
        printRace(hPos,tPos);
        puts("");
    }                              

}

//Finds minimum of hare or tortoise position to decide which position to print first
int min(int hMin, int tMin){
    if (hMin == tMin){
        return 0;
    } else if (hMin < tMin) {
        return hMin;
    } else {
        return tMin;
    }
}

//Prints the position of the H and T
void printRace(int hPos,int tPos){
    
}

//Controls the tortoise movement
void tortMove(int *tPtr){
    size_t move_type = randomNumberGenerator();
    if (move_type >= 1 && move_type <= 5){
       *tPtr += 3; 
    } else if (move_type >= 6 && move_type <= 7){
        *tPtr -= 6;
    } else {
        *tPtr += 1;
    }
    
    // Checks if positon is less than 1
    if (*tPtr > 1) *tPtr = 1;
}

//Controls the hare movement
void hareMove(int *hPtr){
    size_t move_type = randomNumberGenerator();
    if (move_type >= 1 && move_type <= 2){
        // Do Nothing
        ; 
    } else if (move_type >= 3 && move_type <= 4){
        *hPtr += 9;
    } else if (move_type >= 3 && move_type <= 4){
        *hPtr += 9;
    } else if (move_type == 5){
        *hPtr -= 12;
    } else if (move_type >= 6 && move_type <= 8){
        *hPtr += 1;
    } else {
        *ptr -= 2 ;
    }

    // Checks if positon is less than 1
    if (*hPtr > 1) *hPtr = 1;
}

//Generates random number from 1-10
int randomNumberGenerator(){
    return (rand() % INT_MAX + RAND_MIN);
}

#include <stdio.h>
#include <stdlib.h>

/* Joey Huang
 * 1/30/2024
 * CIS 2107
 * Lab 03 ATM
 * 
 * Write a C Program for an ATM machine by implementing functions
 */
#define PIN 3014
#define BALANCE 5000
int transactions = 0;

enum Menu{
    Balance = 1, 
    Withdraw = 2, 
    Deposit = 3, 
    Quit = 4
};

void valid_pin();

// exit program and print message
void quit_program(int status){
    if (status == 0){
        printf("\nThank you for using \"Temple ATM.\"\nYou have made %d transactions\n", transactions);
        exit(0);
    } else{
        printf("\nThank you for using \"Temple ATM.\"\nYou have made %d transactions\n", transactions);
        exit(1);
    }
}

int main(int argc, char *argv[])      
{
    int choice = 0;

    printf("%d", balance);
    printf("%s","Welcome to \"Temple ATM.\"\n\n");

    valid_pin();

    puts("\nWhich transaction you would like to proceed with:\n\n1. Balance");

    quit_program(0);
}

void valid_pin(){
    int attempts = 3;
    int pin;

    while (attempts > 0){
        printf("Please validate your pin (%d Attempts Remaining): ", attempts);
        scanf("%d", &pin);

        if (pin <= 0 ){
            puts("PIN can not be 0 or negative.");
        }

        if ( pin == PIN) {
            return;
        } else{
            attempts--;
        }
    }

    fprintf(stderr, "%s", "Exceeded maximum number of attempts. Your session will now end.\n");
    quit_program(1);
};
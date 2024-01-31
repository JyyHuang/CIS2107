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


void valid_pin();
void quit_program(int);
void get_balance();
void withdraw();
void deposit();

// exit program and print message

int main(int argc, char *argv[])      
{
    int choice = 0;

    const unsigned int Balance = 1;
    const unsigned int Withdraw = 2;
    const unsigned int Deposit = 3;
    const unsigned int Quit = 4;

    printf("%s","Welcome to \"Temple ATM.\"\n\n");

    valid_pin();

    while (choice != Quit)
    {
        puts("\nWhich transaction you would like to proceed with:\n\n1. Balance\n2. Withdraw\n3. Deposit\n4. Quit");
        scanf("%d", &choice);

        if (choice == Balance){
            get_balance();
        } else if (choice == Withdraw){
            withdraw();
        } else if (choice == Deposit){
            deposit();
        } else if(choice == Quit){
            quit_program(0);
        } else{
            puts("Please enter a valid option.");
        }
    }
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

void quit_program(int status){
    if (status == 0){
        printf("\nThank you for using \"Temple ATM.\"\nYou have made %d transactions\n", transactions);
        exit(0);
    } else{
        printf("\nThank you for using \"Temple ATM.\"\nYou have made %d transactions\n", transactions);
        exit(1);
    }
}

void get_balance(){
    printf("Your total balance is: %d\n", BALANCE);
}
void withdraw(){}

void deposit(){}
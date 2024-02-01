#include <stdio.h>
#include <stdlib.h>

/* Joey Huang
 * 1/30/2024
 * CIS 2107
 * Lab 03 ATM
 * 
 * Write a C Program for an ATM machine by implementing functions
 */

// Initialize globals
#define PIN 3014
#define INITIAL_BALANCE 5000
unsigned int transactions = 0;
unsigned int balance = INITIAL_BALANCE;
int withdraw_limit = 1000;
int deposit_limit = 10000;

// Function Prototypes
void valid_pin();
void quit_program(int);
void get_balance();
void withdraw();
void deposit();
void receipt();


int main(int argc, char *argv[])      
{
    // Choices
    unsigned int choice = 0;
    const unsigned int Balance = 1;
    const unsigned int Withdraw = 2;
    const unsigned int Deposit = 3;
    const unsigned int Quit = 4;

    printf("%s","Welcome to \"Temple ATM.\"\n\n");

    valid_pin();

    while (choice != Quit)
    {
        puts("\nWhich transaction you would like to proceed with?\n\n1. Balance\n2. Withdraw\n3. Deposit\n4. Quit");
        printf("%s", "\nEnter the number: ");
        scanf("%u", &choice);

        if (choice == Balance){
            get_balance(balance);
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

// Check if user inputs valid PIN. Three attemps allowed. PIN can not be 0 or negative
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
            --attempts;
        }
    }

    fprintf(stderr, "%s", "\nExceeded maximum number of attempts. Your session will now end.\n");
    quit_program(1);
};


// User picks option 1. Prints Balance
void get_balance(unsigned int balance){
    printf("Your total balance is: $%u\n", balance);
}

// User picks option 2. 3 Attemps total. Only accepts 20s. Checks if amount is within withdraw limit.
void withdraw(){
    int attempts = 3;
    int amount;

    if (balance <= 0){
        printf("Unable to withdraw balance of $%u", balance);
        return;
    }

    while (attempts > 0){
        // Checks if limit is already met
        if (withdraw_limit <= 0){
            puts("You have withdrawn the maximum limit of $1000 for the day.");
            return;
        }

        printf("How much would you like to withdraw? (Only 20s) (%d Attempts Remaining)\n", attempts);
        scanf("%d", &amount);

        if (amount > 0 && amount <= withdraw_limit && amount % 20 == 0){
            balance -= amount;
            withdraw_limit -= amount;
            ++transactions;
            receipt();
            return;
        } else if (amount > withdraw_limit){
            printf("Amount is over the limit. You can only withdraw up to $%d.\n", withdraw_limit);
            --attempts;
        } else{
            puts("Please enter a valid amount.");
            --attempts;
        }
    }

    fprintf(stderr, "%s", "\nExceeded maximum number of attempts. Your session will now end.\n");
    quit_program(1);   
}

// User picks option 3.
void deposit(){

    int attempts = 3;
    int amount;

    while (attempts > 0){
        // Checks if limit is already met
        if (deposit_limit <= 0){
            puts("You have deposited the maximum limit of $10000 for the day.");
            return;
        }

        printf("How much would you like to deposit? (Accepts all bills) (%d Attempts Remaining)\n", attempts);
        scanf("%d", &amount);

        if (amount > 0 && amount <= deposit_limit){
            balance += amount;
            deposit_limit -= amount;
            ++transactions;
            receipt();
            return;
        } else if (amount > deposit_limit){
            printf("Amount is over the limit. You can only deposit up to $%d.\n", deposit_limit);
            --attempts;
        } else{
            puts("Please enter a valid amount.");
            --attempts;
        }
    }

    fprintf(stderr, "%s", "\nExceeded maximum number of attempts. Your session will now end.\n");
    quit_program(1);   
}


// User picks option 4. Exit program and print message. Also used to terminate program whenever necessary.
void quit_program(int status){
    if (status == 0){
        printf("\nThank you for using \"Temple ATM.\"\nYou have made %u transaction(s)\n", transactions);
        exit(0);
    } else{
        printf("\nThank you for using \"Temple ATM.\"\nYou have made %u transaction(s)\n", transactions);
        exit(1);
    }
}

// Helper function to prompt user for a receipt
void receipt(){
    unsigned int choice = 0;

    while (1){
        printf("%s", "Would you like to print a receipt? (1 for Yes, 2 for No)\n");
        scanf("%u", &choice);
        if (choice == 1){
            puts("Receipt printing...");
            return;
        } else if (choice == 2){
            return;
        } else {
            puts("Please enter a valid choice.");
        }
    }
}
#include <stdlib.h>
#include <stdio.h>

/* Joey Huang
 * 1/24/2024
 * CIS 2107
 * Lab 02 Revenue
 * 
 * Write a C program to calculate the revenue from a sale based on the unit price and quantity of a product
 */

int main(int argc, char **argv)
{
    double itemPrice;
    double quantity;
    double discount;
    double discountAmount;

    printf("Welcome to \"Temple\" store\n\n");

    // Item price
    printf("\tEnter item price: ");
    scanf("%lf", &itemPrice);
    if (itemPrice <= 0){
        printf("\n\tThis is not a valid item price.\n\tPlease run the program again\n\n");
        printf("Thank You for using \"Temple\" store\n");
        exit(1);
    }

    // Quantity
    printf("\tEnter quantity: ");
    scanf("%lf", &quantity);
    if (quantity <= 0 || (int) quantity != quantity){
        printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again\n\n");
        printf("Thank You for using \"Temple\" store\n");
        exit(1);
    }

    printf("\n");
    printf("\tThe item price is: $%.1lf\n", itemPrice);
    printf("\tThe order is: %d item(s)\n", (int) quantity);
    printf("\tThe cost is: $%.1lf\n", itemPrice * quantity);

    if (quantity >= 1 && quantity <= 49){
        discount = 0;
    } else if (quantity >= 50 && quantity <= 99)
    {
        discount = .10;
    } else if (quantity >= 100 && quantity <= 149)
    {
        discount = .15;
    } else if (quantity >= 150)
    {
        discount = .25;
    }
    
    printf("\tThe discount is: %.1lf%%\n", discount * 100);

    discountAmount = (itemPrice * quantity) * discount;
    printf("\tThe discount amount is: $%.1lf\n", discountAmount);
    printf("\tThe total is: $%.1lf\n\n", (itemPrice * quantity) - discountAmount);

    printf("Thank You for using \"Temple\" store\n");

    exit(0);
}

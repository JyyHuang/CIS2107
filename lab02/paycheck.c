#include <stdlib.h>
#include <stdio.h>

/* Joey Huang
 * 1/24/2024
 * CIS 2107
 * Lab 02 Paycheck
 * 
 * Write a C program to calculate the paycheck for a Temple employee based on hourly salary, work hours, and overtime hours.
 */

int main(int argc, char **argv)
{
    double employeeNumber;
    double hourlySalary;
    double weeklyTime;
    double regularPay = 0;
    double overtimePay = 0;
    double netPay;

    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");

    // Input Employee Number
    printf("\tEnter Employee Number: ");
    scanf("%lf", &employeeNumber);
    if (employeeNumber <= 0 || (int) employeeNumber != employeeNumber){
        printf("\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    // Input hourly salary
    printf("\tEnter Hourly Salary: ");
    scanf("%lf", &hourlySalary);
    if (hourlySalary <= 0){
        printf("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    // Input weekly time
    printf("\tEnter Weekly Time: ");
    scanf("%lf", &weeklyTime);
    if (weeklyTime <= 0){
        printf("\n\tThis is not a weekly time.\n\tPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    printf("\t==============================\n");
    printf("\tEmployee #: %d\n", (int) employeeNumber);
    printf("\tHourly Salary: $%.1lf\n", hourlySalary);
    printf("\tWeekly Time: %.1lf\n", weeklyTime);

    if (weeklyTime <= 40){
        regularPay = weeklyTime * hourlySalary;
    }
    else {
        regularPay = 40 * hourlySalary;
        overtimePay = (weeklyTime - 40) * (1.5 * hourlySalary);
    }

    netPay =  regularPay + overtimePay;

    printf("\tRegular Pay: $%.1f\n", regularPay);
    printf("\tOvertime Pay: $%.1f\n", overtimePay);
    printf("\tNet Pay: $%.1f\n", netPay);
    printf("\t==============================");

    

    printf("\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");

    exit(0);
}
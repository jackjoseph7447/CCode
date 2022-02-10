/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in the area below designated inside of the main function. When
    completed, the main function should run the code for both problems.

    1. Write code that calculates mileage reimbursement for a salesperson at
    a rate of $.48 per mile. Your program should get the mileage from the user
    in this manner:
        MILEAGE REIMBURSEMENT CALCULATOR
        Enter beginning odometer reading: 13505.2
        Enter ending odometer reading: 13810.6
        You traveled 305.4 miles. At $0.48 per mile, your reimbursement is $146.59.

    2. Write code to convert a temperature in degrees Fahrenheit to degrees
    Celsius. Your program should get the temperature Fahrenheit from the user and
    print the result as:
        FAHRENHEIT TO CELSIUS CALCULATOR
        Enter temperature Fahrenheit: 100.0
        100.0 degrees Fahrenheit is 37.78 degrees Celsius

*/

// Preprocessor directives
#include <stdio.h>
#include <math.h>
// Main function
int main()
{
    // Coding Problem 1
    double begin = 0.0;
    double end = 0.0;

    printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
    printf("Enter beginning odometer reading: ");
    scanf("%lf", &begin);
    printf("Enter ending odometer reading: ");
    scanf("%lf", &end);
    double totalMiles = end - begin;
    double moneyOwed = totalMiles * 0.48;
    printf("You traveled %.1f miles. At $0.48 per mile, your reimbursement is $%.2f\n", totalMiles, moneyOwed);

    // Coding Problem 2

    double fahr = 0.0;
    printf("FAHRENHEIT TO CELSIUS CALCULATOR\n");
    printf("Enter temperature Fahrenheit: ");
    scanf("%lf", &fahr);
    double cel = (fahr - 32.0) * 5.0/9.0;
    printf("%.1f degrees Fahrenheit is %.2f degrees Celsius\n", fahr, cel);


// End main function
return 0;
}

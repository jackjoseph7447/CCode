/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in functions below the main function and call both from the main
    function.  The functions should accept data from main, calculate and return
    the result to main.  Getting data from the user and printing the results
    should be done in main.  When completed, the main function should get input
    data from the user, call the functions, receive the results of the function
    calls, and print their results to screen.

    1. You have saved $500 to use as a down payment on a car. Before beginning
    your car shopping, you decide to write a function to help you figure out what
    your monthly payment will be, given the car's purchase price, the monthly
    interest rate, and the time period over which you will pay back the loan. The
    formula for calculating your payment is:

        payment =    iP
                    ________________
                    1 - (1 + i)^(-n)
        where
        P = principal (the amount you borrow)
        i = monthly interest rate ( 1/12 of the annual rate)
        n = total number of payments

    Your program should get input data from the user in the main function in this manner:
        CALCULATE PAYMENT
        Enter principal: 500.0
        Enter annual interest rate: 6.0
        Enter number of payments: 24
        Your monthly payment is: 22.16


    2. For any integer n > 0, n! is defined as the product n * (n - 1) * (n - 2) … * 2 * 1.
    0! is defined to be 1. It is sometimes useful to have a closed-form definition instead;
    for this purpose, an approximation can be used. R.W. Gosper proposed the following
    such approximation formula:

        n! = n^n x e^(-n) x square_root((2n + 1/3) x pi)

    Create a function that prompts the user to enter an integer n , uses Gosper's
    formula to approximate n!, and then displays the result. The input data should
    be read and output result should be printed in the main function, and the calculation
    should be in the function for Problem 2. The message displaying the result should look
    something like this:

        Enter a number: 5
        5! equals approximately 119.97003

    Your program will be easier to debug if you use some intermediate values
    instead of trying to compute the result in a single expression. If you are not
    getting the correct results, then you can compare the results of your intermediate
    values to what you get when you do the calculations by hand. Use at least two
    intermediate variables - one for 2n + 1/3 and one for (2n + 1/3) x pi.

    Display each of these intermediate values to simplify debugging. Be sure to
    use a named constant for PI, and use the approximation 3.14159265 and use a
    constant for E, approximated as 2.718281827. Test the program on nonnegative
    integers less than 8.

*/

// Preprocessor directives
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define E 2.718281827

// Function prototypes
double payments();
double changeNumber();

// Main function
int main()
{
    payments();
    changeNumber();

    return 0;
}

// Function for Coding Problem 1
double payments()
{
    printf("CALCULATE PAYMENT\n");
    printf("Enter Principal: ");
    double princ = 0.0;
    scanf("%lf", &princ);
    printf("Enter annual interest rate: ");
    double aIR = 0.0;
    scanf("%lf", &aIR);
    double precent = aIR / 100;
    double i = precent / 12.0;
    printf("Enter number of payments: ");
    double tP = 0.0;
    scanf("%lf", &tP);
    double result = (i * princ) / (1 - (pow(1 + i, -tP)));

    return printf("Your monthly payments is: %.2f\n", result);
}

// Function for Coding Problem 2

double changeNumber()
{
    printf("Enter a number: ");
    double num = 0.0;
    scanf("%lf", &num);
    double resultOne = pow(num, num) * pow(E, -num);
    double resultTwo = sqrt((2*num + (1.0/3.0)) * PI);
    double finalResult = resultOne * resultTwo;
    return printf("!%.2f equals approximately %.5f", num, finalResult);
}

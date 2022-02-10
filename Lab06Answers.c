/*

   Please write your code in the designated lines below.

*/


/* Add necessary libraries here. */
#include <stdio.h>
#include <math.h>

/* Add function prototypes here. */
void atm(int dollars, int *fifties, int *twenties, int *tens);
int test7_11_13(int x, int *a, int *b, int *c);
double my_sqrt(double n);

/* Add main function here. The function calls from the problems below should be
   called in main.
*/

int big = 0; // 50
int medium = 0; // 20
int small = 0; // 10


int main()
{
    printf("Enter the amount of money: ");
    int money = 0;
    scanf("%d", &money);

    atm(money, &big, &medium, &small);

    printf("50s = %d, 20s = %d, 10s = %d\n", big, medium, small);

    // ***Changed to ints
    int optionOne = 0; // Question one in Problem 2
    int optionTwo = 0; // Question two in Problem 2
    int optionThree = 0; // Question Three in Problem 2

    printf("Enter a number: ");
    int num = 0;
    scanf("%d", &num);

    // ****Changed * to & to pass by address and removed & from printfs
    test7_11_13(num, &optionOne, &optionTwo, &optionThree);
    printf("Is the value a multiple of 7, 11, or 13? %d\n", optionOne);
    printf("Is the sum of the digits odd or even? %d\n", optionTwo);
    printf("Is the value a prime number? %d\n", optionThree);


    // ****Changed sqrt to sr in case there is a conflict with the math.h function
    printf("Enter a number to be square rooted: ");
    double sr = 0.0;
    scanf("%lf", &sr);
    //printf("the square root of %lf is %lf", sr, my_sqrt(sr));
    printf("the square root of %f is %f", sr, my_sqrt(sr)); // ****Should use %f to print a double


    return 0;
}

/*
   Add function for problem 1 here.

   1. Write a function for an automatic teller machine that dispenses money.
   The user should enter the amount desired (a multiple of 10 dollars) and the
   machine dispenses this amount using the least number of bills. The bills dispensed
   are 50s, 20s, and 10s. The function determines how many of each kind of bill to
   dispense.  The function should be named atm, accept an integer named dollars,
   integer pointer fifties, integer pointer twenties, integer pointer tens and return
   nothing.  When the function completes, the pointers should be set with the number
   of 50s, 20s and tens that are necessary to equal dollars.  Call atm from the main
   function to test it with a few dollar values.  When atm works properly, comment out
   the function call and start problem 2.

   Input a number and find the minimum number of bills to give back
*/
void atm(int dollars, int *fifties, int *twenties, int *tens)
{
    while(dollars != 0)
    {
        if(dollars > 50 || dollars == 50)
        {
            big += 1;
            dollars = dollars - 50;
        }
        else if(dollars > 20 || dollars == 20)
        {
            medium += 1;
            dollars = dollars - 20;
        }
        else if(dollars > 10 || dollars == 10)
        {
            small += 1;
            dollars = dollars - 10;
        }

    }
}


/*
   Add function for problem 2 here.

   2. Determine the following information about each value in a list of positive integers.
      a. Is the value a multiple of 7, 11, or 13?
      b. Is the sum of the digits odd or even?
      c. Is the value a prime number?
   You should write a function named test7_11_13 with an integer input parameter and three type
   int output parameters (aka pointers) that send back the answers to these three questions. If the
   integer is evenly divisible by 7, 11 or 13, its respective output parameter should be set to 1,
   otherwise zero. Some sample input data might be:

   104 3773 13 121 77 30751

   Call test7_11_13 from the main function to test it.  When test7_11_13 works properly, comment out
   the function call and start problem 3.

   write func which takes 3 parameters and func(int a, int *b, int *c, int *d)
   int a_main = 0;
   int b-d main = 0;
*/
int test7_11_13(int x, int *a, int *b, int *c)
{
    int sum = 0;
    int digitTotal = 0;
    int t = x;

    if(x % 7 == 0 || x % 11 == 0 || x % 13 == 0) // Checks to see if x is a mulitible of 7, 11, or 13
        *a = 1;
    else
        *a = 0;

    while(x != 0){
        digitTotal += x % 10; // Gets the sum of each digit
        x /= 10; // ****Added this and curly braces to remove infinite loop
    }
    if(digitTotal % 2 == 0) // Checks to see if those digits are even, if not, return odd
        *b = 1;
    else
        *b = 0;

        // ****Changed i = 1 to i = 2 and i <= to x to i < x
    for(int i = 2; i < x; i++) // Divides every number up to the number, if the sum goes over 2, it is not a prime number. Sum is added to if x is divisable by a number
    {
        if(x % i == 0)
            sum += 1;
    }
    // ****Moved outside loop
    if(sum == 0) // ****Changed from sum > 2 to sum == 0
        *c = 1;
    else
        *c = 0;
    printf("sum = %d\n", sum);
}


/*
   3. Add functions for problem 3 here.

   The square root of a number N can be approximated by repeated calculation
   using the formula:

      NG = 0.5(LG + N/LG)

   where NG stands for next guess and LG stands for last guess. Write a function
   that calculates the square root of a number using this method.  Write a function
   called my_sqrt that accepts an double N, which is the number to find the square root
   and returns the square root found.  There are no pointers in this problem.  You do
   have to compare doubles, which requires an approximate match with an allowable error.

   The initial guess will be the starting value of LG . The program will compute
   a value for NG using the formula given. The difference between NG
   and LG is checked to see whether these two guesses are almost identical. If
   they are, NG is accepted as the square root; otherwise, the next guess ( NG )
   becomes the last guess ( LG ) and the process is repeated (another value is
   computed for NG, the difference is checked, and so on). The loop should be
   repeated until the difference is less than 0.005. Use an initial guess of 1.0.
   Write a driver function and test your square root function for the numbers
   4, 120.5, 88, 36.01, 10,000, and 0.25.

*/

double my_sqrt(double n)
{
    double nextGuess = 0.0;
    double lastGuess = 1.0;  // ****Changed to 1.0
    //double apx = 0.0; // Approximent
    //double answer = 0.0; // Returned to main func


    nextGuess = 0.5 * (lastGuess + n / lastGuess); // ****Need to get initial guess
    //while(lastGuess - nextGuess >= 0.005) // Continues formula as long as the difference is greater than 0.005
    while(fabs(lastGuess - nextGuess) >= 0.005) // ****Added fabs to get absolute value
    {
        lastGuess = nextGuess; // ****Must copy next to last
        //nextGuess = 0.5(lastGuess + n / lastGuess); // Formula given
        nextGuess = 0.5 * (lastGuess + n / lastGuess); // Formula given **** Fixed need * in c for multiplication
        //printf("lg = %f ng = %f l-n = %f\n", lastGuess, nextGuess, fabs(lastGuess - nextGuess));

    }
    //answer = nextGuess;
    return nextGuess;
}

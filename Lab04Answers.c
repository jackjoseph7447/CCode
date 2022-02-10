/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in functions below the main function and call both from the main
    function.  The functions should accept data from main, calculate and return
    the result to main (Problem 2 should print the results for the substance to
    screen.  See below.).  Getting data from the user and printing the results
    should be done in main.  When completed, the main function should get input
    data from the user, call the functions, receive the results of the function
    calls, and print their results to screen.


    1. Write a function that determines the day number (1 to 366) in a year for a
    date that is provided as input data. As an example, January 1, 1994, is day 1.
    December 31, 1993, is day 365. December 31, 1996, is day 366, since 1996 is
    a leap year. A year is a leap year if it is divisible by four, except that any year
    divisible by 100 is a leap year only if it is divisible by 400. Your function should
    accept the month, day, and year as integers from main as arguments. Include an
    additional function leap that returns 1 if called with a leap year, 0 otherwise.
    Sample screen output:

        CALCULATE DAY OF YEAR
        Enter a date: 12 31 2004
        12/31/2004 is the 366th day of 2004

    Note that a leap year is a year that is divisible by 4 but not by 100 or divisible
    by 400.  1900 was not a leap year because it's divisible by 4 but is also divisible
    by 100.  2000 was a leap year because it's divisible by 400.  1904 was a leap year
    because it's divisible by 4 but not divisible by 100.

    2. The table below shows the normal boiling points of several substances. Write
    a function that accepts an argument the observed boiling point of a substance
    in degrees Celsius and identifies the substance if the observed boiling point
    is within 5% of the expected boiling point. If the data input is more than 5%
    higher or lower than any of the boiling points in the table, the function should
    output the message Substance unknown.  Note that the function should print the
    substance and not main.  This will simplify the function call in main.  You need
    to test each substance in an else if chain for the temperature passed from main.

        Substance   Normal boiling point (Celsius)
        Water       100
        Mercury     357
        Copper      1187
        Silver      2193
        Gold        2660

    Your function should define and call a function within_x_percent that takes
    as parameters a reference value ref , a data value data , and a percentage value
    x and returns 1 meaning true if data is within x % of ref -that is, (ref - x%
    * ref) <= data <= (ref + x % * ref) . Otherwise within_x_percent would
    return zero, meaning false. For example, the call within_x_percent(357,
    323, 10) would return true, since 10% of 357 is 35.7, and 323 falls between
    321.3 and 392.7. Sample screen output:

        FIND SUBSTANCE FOR BOILING POINT
        Enter a temperature: 360
        The substance is Mercury

*/

// Preprocessor directives
#include <stdio.h>
#include <math.h>

#define WATER 100
#define MERCURY 357
#define COPPER 1187
#define SILVER 2193
#define GOLD 2660

int month = 0;
int day = 0;
int year = 0;
int result = 0;
int jan = 31;
int feb = 28;
int mar = 31;
int apr = 30;
int may = 31;
int june = 30;
int july = 31;
int aug = 31;
int sep = 30;
int oct = 31;
int nov = 30;
int dec = 31;

int temp = 0;
int boil = 0;


// Function prototypes

void problemOne();
double leapCheck(int year);
void materialName();
double within_x_percent(double ref, double data, double precent);



// Main function
int main()
{
    //Problem 5

    printf("Enter the Richter Scale Number of the earthquake: ");
    double n = 0.0;
    scanf("%lf", &n);

    if(n < 5.0)
        printf("Little or no damage\n");
    else if(5.0 <= n && n < 5.5)
        printf("Some damage\n");
    else if(n >= 5.5 && n < 6.5)
        printf("Serious Damage: walls may crack or fall\n");
    else if(n >= 6.5 && n < 7.5)
        printf("Disaster: houses and buildings may collapse");
    else
        printf("Catastrophe: Most buildings destroyed\n");
    // This program could not be done with an switch statement because doubles cannot be used in a switch statement

    problemOne();
    materialName();

    return 0;
}

// Function for Coding Problem 1
void problemOne()
{
    printf("CALCULATE DAY OF YEAR\n");
    printf("Enter a date: ");

    scanf("%d %d %d", &month, &day, &year);

    leapCheck(year);

    //printf("month = %d\nday = %d\nyear = %d\nfeb = %d\n", month, day, year, feb);

    if(month == 1 || month == 01)
        printf("%d/%d/%d is the %dth day of %d\n", month, day, year, day, year);
    else if(month == 2 || month == 02)
    {
       result = day + jan;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 3 || month == 03)
    {
       result = day + jan + feb;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 3 || month == 03)
    {
       result = day + jan + feb;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 4 || month == 04)
    {
       result = day + jan + feb + mar;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 5 || month == 05)
    {
       result = day + jan + feb + mar + apr;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 6 || month == 06)
    {
       result = day + jan + feb + mar + apr + may;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 7 || month == 07)
    {
       result = day + jan + feb + mar + apr + may + june;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 8)
    {
       result = day + jan + feb + mar + apr + may + june + july;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 9)
    {
       result = day + jan + feb + mar + apr + may + june + july + aug;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 10)
    {
       result = day + jan + feb + mar + apr + may + june + july + aug + sep;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 11)
    {
       result = day + jan + feb + mar + apr + may + june + july + aug + sep + oct;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else if(month == 12)
    {
       result = day + jan + feb + mar + apr + may + june + july + aug + sep + oct + nov;
       printf("%d/%d/%d is the %dth day of %d\n", month, day, year, result, year);
    }

    else
        printf("Error: invalid date\n");

}

// leap function
double leapCheck(year)
{
    if(year % 400 != 0 && year % 4 == 0 && year % 100 == 0)
        NULL;
    else
        feb ++;
}

// Function for Coding Problem 2

void materialName()
{
    printf("FIND SUBSTANCE FOR BOILING POINT\n");
    printf("Enter a temperature: ");
    scanf("%d", &temp);
    printf("Enter the boiling point of the substance: ");
    scanf("%d", &boil);
    within_x_percent(boil, temp, 5);
}

// within_x_percent function

double within_x_percent(double ref, double data, double precent)
{
    precent = precent / 100.0;


    double precentRef = ref * precent;
    double upperRef = precentRef + ref;
    double lowerRef = ref - precentRef;

    if(ref == WATER && data >= lowerRef &&  data <= upperRef)
        printf("The substance is Water\n");
    else if(ref == MERCURY && data >= lowerRef &&  data <= upperRef)
        printf("The substance is Mercury\n");
    else if(ref == COPPER && data >= lowerRef &&  data <= upperRef)
        printf("The substance is Copper\n");
    else if(ref == SILVER && data >= lowerRef &&  data <= upperRef)
        printf("The substance is Silver\n");
    else if(ref == GOLD && data >= lowerRef &&  data <= upperRef)
        printf("The substance is Gold\n");
    else
        printf("Invalid input, please try again\n");
}



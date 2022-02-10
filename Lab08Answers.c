/*
    Please code solutions for the problems below.  You should only have one main function
    and call the required functions for each problem.  Sample output:

    Enter the colors of the resistor's three bands, beginning with
    the band nearest the end. Type the colors in lowercase letters
    only, NO CAPS.
    Band 1 => green
    Band 2 => black
    Band 3 => yellow
    Resistance value: 500 kilo-ohm(s)
    Do you want to decode another resistor: y

    Enter the colors of the resistor's three bands, beginning with
    the band nearest the end. Type the colors in lowercase letters
    only, NO CAPS.
    Band 1 => brown
    Band 2 => vilet
    Band 3 => gray
    Resistance value: -1 kilo-ohm(s)
    Do you want to decode another resistor: n

    Enter a string: chair
    The plural of chair is chairs
    Do you want to convert another string: y

    Enter a string: dairy
    The plural of dairy is dairies
    Do you want to convert another string: y

    Enter a string: boss
    The plural of boss is bosses
    Do you want to convert another string: n

    Enter first string: procrastination
    Enter second string: destination
    The suffix of procrastination and destination is stination
    Do you want to find another suffix: y

    Enter first string: globally
    Enter second string: internally
    The suffix of globally and internally is ally
    Do you want to find another suffix: y

    Enter first string: gloves
    Enter second string: dove
    The suffix of gloves and dove is
    Do you want to find another suffix: n


    Process returned 0 (0x0)   execution time : 124.085 s
    Press any key to continue.


*/

// Import standard input/output library
#include <stdio.h>
#include <math.h>
#include <string.h>

// Function prototypes go here
int resistor(char bands[][25], int n);
int search(char colorCodes[][7], int n, char target[]);
void plural(char word[], int length);
char suffix(char wordOne[], char wordTwo[], char s[]);

// Main function goes here
// Main, libraries and prototypes: 5 points
int main()
{
    char bandOne[25];
    char bandTwo[25];
    char bandThree[25];
    char bands[3][25];
    int n = 3;

    char a;

    do
    {
        printf("Enter the colors of the resistor's three bands, beginning with\n");
        printf("the band nearest the end. Type the colors in lowercase letters\n");
        printf("only, NO CAPS.\n");

        printf("Band 1 => ");
        scanf("%s", bands[0]);
        printf("Band 2 => ");
        scanf("%s", bands[1]);
        printf("Band 3 => ");
        scanf("%s", bands[2]);

        int result = resistor(bands, n);
        printf("result = %d\n", result);

        printf("Do you want to decode another resistor?: ");
        fflush(stdin);
        scanf("%c", &a);
    }while(a != 'n');


    char noun[50];
    char b;

    do
    {
        printf("Enter a noun: ");
        scanf("%s", noun);

        int length = strlen(noun);

        plural(noun, length);

        printf("Do you want to convert another string?: ");
        fflush(stdin);
        scanf("%c", &b);

    }while(b != 'n');



    char wordOne[50];
    char wordTwo[50];
    char s[100];
    char c;

    do
    {
        printf("Enter first string: ");
        scanf("%s", wordOne);
        printf("Enter second string: ");
        scanf("%s", wordTwo);
        suffix(wordOne, wordTwo, s);
        printf("The suffix of %s and %s is: %s\n", wordOne, wordTwo, s);
        printf("Would you like to find another suffix?: ");
        fflush(stdin);
        scanf("%c", &c);

    }while(c != 'n');



    return 0;
}


/*

Problem 1: 10 points

A resistor is a circuit device designed to have a specific resistance value
between its ends. Resistance values are expressed in ohms or kilo-ohms.
Resistors are frequently marked with colored bands that encode their
resistance values, as shown below. The first two bands are digits, and the
third is a power-of-ten multiplier.

The table below shows the meanings of each band color. For example, if the
first band is green, the second is black, and the third is yellow, the resistor has a
value of 50 x 10^4 or 500k.  The 50 is 10 x green(index 5) + black(index 0)).  The
10^4 is 10^yellow(index 4).  The information in the table can be stored in a C program
as an array of strings.

    char COLOR_CODES[10][7] = {"black", "brown", "red",
    "orange", "yellow", "green", "blue", "violet", "gray",
    "white"};

Notice that "red" is COLOR_CODES[2] and has a digit value of 2 and a multiplier
value of 10 2 . In general, COLOR_CODES[ n ] has digit value n and multiplier value 10 n .
Write a function that accepts the colors of Band 1, Band 2, and Band 3,
and then returns the resistance in kilo-ohms. Include a helper function search
that takes three parameters--the list of strings, the size of the list, and a target
string, and returns the subscript of the list element that matches the target or
returns -1 if the target is not in the list.

Color Codes for Resistors*
    Color Value     Digit Value     Multiplier
    Black           0               10^0
    Brown           1               10^1
    Red             2               10^2
    Orange          3               10^3
    Yellow          4               10^4
    Green           5               10^5
    Blue            6               10^6
    Violet          7               10^7
    Gray            8               10^8
    White           9               10^9

*Adapted from Sears and Zemansky’s University Physics , 10th edited by Hugh D. Young and Roger A.
Freedman (Boston: Addison-Wesley, 2000), p. 807.

*/

// resistor function goes here
int resistor(char bands[][25], int n)
{
    char COLOR_CODES[10][7] = {"black", "brown", "red",
    "orange", "yellow", "green", "blue", "violet", "gray",
    "white"};

    int calcOne = 0;
    int calcTwo = 0;
    int calcThree = 0;

    int calc[3];

    for(int i = 0; i < n; i ++)
    {
        calc[i] = search(COLOR_CODES, 10, bands[i]);
        //printf("%d\n", calc[i]); For testing
    }

    double result = ((10 * calc[0] + calc[1]) * pow(10, calc[2])) / 1000.0;
    return result;
}


// search function goes here
int search(char colorCodes[][7], int n, char target[])
{
    for(int i = 0; i < n - 1; i++)
    {
        if(strcmp(colorCodes[i], target) == 0)
            return i;
    }
    return -1;
}


/*

Problem 2: 5 points

Write a function that takes nouns and forms their plurals on the basis of
these rules:

    a. If noun ends in "y", remove the "y" and add "ies".
    b. If noun ends in "s", "ch", or "sh", add "es".
    c. In all other cases, just add "s".

Print each noun and its plural. Try the following data:
    chair   dairy   boss    circus  fly dog church  clue    dish

*/

// plural function goes here
void plural(char word[], int length)
{
    //char last = word[length - 1];
    //char secondLast = word[length - 2];

    if(word[length - 1] == 'y')
    {
        word[length - 1] = '\0';
        strcat(word, "ies");
    }

    else if(word[length - 1] == 's')
    {
        word[length - 1] = '\0';
        strcat(word, "es");
    }

    else if((word[length - 2] == 'c' && word[length - 1] == 'h') || (word[length - 2] == 's' && word[length - 1] == 'h'))
    {
        word[length - 2] = '\0';
        word[length - 1] = '\0';
        strcat(word, "es");
    }

    else
        strcat(word, "s");

    printf("noun = %s\n", word);
}


/*

Problem 3: 5 points

Write and test a function that finds and returns through an output parameter
the longest common suffix of two words (e.g., the longest common suffix of
"procrastination" and "destination" is "stination", of "globally" and "internally"
is "ally", and of "gloves" and "dove" is the empty string).

*/

// suffix function goes here

/*

    An effective approach is to start at the end of each string and count the
    number of matching chars in the suffix in a loop.

    In the next loop, copy the chars from the beginning to the end of the suffix
    to a string.

    For "nice" and "mice":

    nice
    mice

    From last char towards the first, count the chars in the suffix.
        The last chars e match count++
        The next chars c match count++
        The next chars i match count++
        the next chard do not match end loop with count = 3

    Copy the suffix to another string from one of the two strings
        Copy i
        Copy c
        Copy e
        Copy null char

    Suffix is "ice"

    You don't need nested loops.  Just one to count and one to copy.




*/

char suffix(char wordOne[], char wordTwo[], char s[])
{
    int sizeOne = strlen(wordOne); // Size of word.
    int sizeTwo = strlen(wordTwo);
    int count = 0;


    while(wordOne[sizeOne] == wordTwo[sizeTwo] && wordOne >= 0 && wordTwo >= 0)
    {
        count ++;
        wordOne --;
        wordTwo --;
    }

    sizeOne ++;
    sizeTwo ++;

    for(int i = 0; i < count; i++)
        s[i] = wordOne[sizeOne++];


    return s;

}



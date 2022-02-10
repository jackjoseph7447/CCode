/*
    Your task is to write a program to read sales records from a file,
    print the records to screen, and write a report of sales by item id.

    The data file contains:

    1,1,Sheet Goods,100,4.5
    2,2,Joint Compound,7,12.99
    3,3,Tape,5,7.99
    4,2,Joint Compound,12,12.99
    5,1,Sheet Goods,65,4.5
    6,1,Sheet Goods,32,4.5
    7,2,Joint Compound,5,12.99
    8,3,Tape,4,7.99

    The data are:

    integer id
    integer itemID
    string item
    integer qty
    double price

    This task will be easier if you code you program in this order:

    1. Include libraries
    2. Write constants
    3. Write structs
    4. Write empty main (except return 0;)
    5. Write create_list function
    6. Write print_sale function
    7. Write print_list function
    8. Write read_sales function
    9. Test all functions in main
        a. create_list function
        b. read_sales function
        c. print_list function
    10. Write write_report function
    11. Test write_report function in main
    12. Submit this file to Canvas.

    Good luck!
*/


// 1. Include libraries here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 2. Constants and global data here
/*
    A constant called ITEM_SIZE with value 25
    A constant called SALE_LIST_LENGTH with value 100
    A constant called NUM_ITEMIDS with value 3
*/

#define ITEM_SIZE 25
#define SALE_LIST_LENGTH 100
#define NUM_ITEMIDS 3

// Free code!! - The 3 itemIDs from the data
int itemIDs[] = {1, 2, 3};
char items[][ITEM_SIZE] = {"Sheet Goods", "Joint Compound", "Tape"};


// 3. Structs here
/*
    Write code for a struct named sale_t that contains:
    An integer named id
    An integer named itemID
    A string named item with length ITEM_SIZE
    An integer named qty
    A double named price
*/
typedef struct
{
    int id;
    int itemID;
    char item[ITEM_SIZE];
    int qty;
    double price;
}sale_t;

/*
    Write code for a list struct named sale_list_t
    An array of sale_t named array with length SALE_LIST_LENGTH
    An integer named length
    An integer named count
*/

typedef struct
{
    sale_t array[SALE_LIST_LENGTH];
    int length;
    int count;
}sale_list_t;

// Prototypes here
sale_list_t create_list();
void print_sale(sale_t s);
void print_list(sale_list_t sl);
int read_sales(sale_list_t *sl, char fileName[]);
void write_report(sale_list_t sl, char fileName[]);



// 4. Main function here
/*
    The main function should:
    1. Create a sale_list_t
    2. Read the sales from the file to the list
    3. Print the list to screen
    4. Write the report to file
*/
int main()
{
    sale_list_t sl = create_list();
    int sales = read_sales(&sl, "DrywallSupply.csv");
    print_list(sl);

    write_report(sl, "SalesReport.txt");

    return 0;
}


// 5. create_list function
/*
    Write a function named create_list that accepts nothing and returns
    a sale_list_t with length set to SALE_LIST_LENGTH and count to zero.
*/

sale_list_t create_list()
{
    sale_list_t sl;
    sl.length = SALE_LIST_LENGTH;
    sl.count = 0;
    return sl;
}

// 6. print_sale function
/*
    Write a function named print_sale that accepts a sale_t and prints
    all the data on one line, separated by spaces.  Example:

    1 1 Sheet Goods 100 $4.50
*/

void print_sale(sale_t s)
{
    printf("%d %d %s %d $%.2f\n", s.id, s.itemID, s.item, s.qty, s.price);
}

// 7. print_list function
/*
    Write a function named print_list that accepts a sale_list_t and prints
    a header and all the elements by calling print_sale.  Example:

    Drywall Supply Sales

    1 1 Sheet Goods 100 $4.50
    2 2 Joint Compound 7 $12.99
    3 3 Tape 5 $7.99
    4 2 Joint Compound 12 $12.99
    5 1 Sheet Goods 65 $4.50
    6 1 Sheet Goods 32 $4.50
    7 2 Joint Compound 5 $12.99
    8 3 Tape 4 $7.99
*/

void print_list(sale_list_t sl)
{
    for(int i = 0; i < sl.count; i++)
        print_sale(sl.array[i]);
}

// 8. read_sales function
/*
    Write a function named read_sales that accepts a sale_list_t pointer
    and a string containing the file name, and returns the number of records
    read.  Make sure to check that the file opened correctly (not NULL) and
    close the file when done reading.  The function should open the file,
    read all its records into the sale_list_t (make sure to update count),
    close the file and return the count of records read.
*/

int read_sales(sale_list_t *sl, char fileName[])
{
    int records = 0;
    char line[200];

    FILE *file = fopen(fileName, "r");

    if(file == NULL)
    {
        perror("File unable to open");
        exit(2);
    }

    while(fgets(line, 200, file) != NULL)
    {
        line[strlen(line) - 1] = '\0';
        //printf("%s\n", line);
        sl->array[records].id = atoi(strtok(line, ","));
        sl->array[records].itemID = atoi(strtok(NULL, ","));
        strcpy(sl->array[records].item, strtok(NULL, ","));
        sl->array[records].qty = atoi(strtok(NULL, ","));
        sl->array[records].price = atof(strtok(NULL, ","));
        records ++;
        sl->count += 1;
    }

    fclose(file);
    return records;
}

// 10. write_report function
/*
    Write a function named write_report that accepts a sale_list_t and
    a string file name, and returns nothing.  Make sure to check that
    the file opened correctly (not NULL) and close the file when done
    reading. The function should open the file, write the header, write
    the totals for each dept, write the grand total, and close the file.

    Hint: The outer loop should iterate through all itemIDs and the inner
    loop should iterate through all sale_t in the sale_list_t.  Use an
    if statement to accumulate a total for each itemID.

    The report should look like:

    Drywall Supply Sales Report

    1 Sheet Goods: $886.50
    2 Joint Compound: $311.76
    3 Tape: $71.91

    Total sales: $1270.17

*/
void write_report(sale_list_t sl, char fileName[])
{
    FILE *file = fopen(fileName, "w");
    double sum = 0.0;
    double totalSum = 0.0;

    if(file == NULL)
    {
        perror("File unable to open");
        exit(4);
    }

    fprintf(file, "Drywall Supply Sales Report\n\n");

    /*
    int itemIDs[] = {1, 2, 3};
    char items[][ITEM_SIZE] = {"Sheet Goods", "Joint Compound", "Tape"};
    */

    for(int i = 0; i < ITEM_SIZE; i++)
    {
        sum = 0.0;
        fprintf(file, "%d\n", itemIDs[i]);
        for(int j = 0; j < sl.count; j++)
        {
            if(sl.array[i].itemID == sl.array[j].itemID)
            {
                //fprintf(file, "%s ", items[j]);
            }
            //sum += sl.array[i].qty * sl.array[i].price;
        }
        //fprintf(file, "%d %s: $%.2f\n", sl.array[i].itemID, sl.array[i].item, sum);
        //totalSum += sum;

    }

    fprintf(file, "\nTotal sales: $%.2f\n", totalSum);

    fclose(file);

}


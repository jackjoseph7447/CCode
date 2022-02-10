/// Intro
/*
    Your task for this lab is to write an app that creates an expense report
    for The International Secret Intelligence Service (I.S.I.S.) and print it
    to screen.  Suggested sequence of work:

        1. Include necessary libraries
        2. Write empty main() function
        3. Write the Employee struct
        4. Write the EmployeeList struct
        5. Write create_employee_list() function
        6. Test create_employee_list() in main
        7. Write the read_employees(...)
        8. Test read_employees(...) in main
        9. Write print_employee(...)
        10. Write print_employee_list(...)
        11. Test print_employee_list(...) in main

        *You should be able to read the employees into the list and print it
        to screen.

        12. Write the Expense struct
        13. Write the ExpenseList struct
        14. Write create_expense_list() function
        15. Test create_expense_list() in main
        16. Write the read_expenses(...)
        17. Test read_expenses(...) in main
        18. Write print_expense(...)
        19. Write print_expense_list(...)
        20. Test print_expense_list(...) in main

        *You should be able to read the expenses into the list and print it
        to screen.

        21. Write the calc_expenses(...) function
        22. Text calc_expenses(...) in main

        *You should see the necessary output shown at the end of this file.
*/

/// Preprocessor statements
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 50
#define POSITION_SIZE 50
#define ARRAY_LENGTH 50
#define EMPLOYEE_LIST_LENGTH 50
#define DESCRIPTION_LENGTH 100
#define EXPENSE_LIST_LENGTH 50


/// Structs
/*
    Note: that terms in '' are suggestions for variable names.
    The Employee struct stores data:
        The employee's 'id' as an integer
        The employee's 'name' as a string
        The employees 'position' (job title) as a string
        The employee's 'salary' as a double

    Also note: that all structs should be declared like:
        Employee e;
        NOT
        struct Employee e;

*/


/*
    The EmployeeList struct stores a list of Employee:
        An 'array' of Employee
        The preallocated 'length' of the Employee array as integer
        The 'count' of the Employee inserted into array as integer
*/


/*
    The Expense struct stores data:
        The expense line's 'employee_id' as an integer
        The expense's 'description' as a string
        The expense's 'cost' as a double
*/


/*
    The ExpenseList struct stores a list of Expense:
        An 'array' of Expense
        The preallocated 'length' of the Expense array as integer
        The 'count' of the Expense inserted into array as integer
*/

typedef struct
{
    int id;
    char name[NAME_SIZE];
    char position[POSITION_SIZE];
    double salary;

}employee_E;

typedef struct
{
    employee_E array[ARRAY_LENGTH];
    int length;
    int count;
}employeeListE;

typedef struct
{
    int personID;
    char description[DESCRIPTION_LENGTH];
    double cost;
}expense;

typedef struct
{
    expense array[ARRAY_LENGTH];
    int length;
    int count;
}ExpenseList;

/// Prototypes
employeeListE create_employee_list();
int read_employees(employeeListE *ls);
void print_employee(employee_E ls);
void print_employee_list(employeeListE lst);
ExpenseList create_expense_list();
int read_expenses(ExpenseList *el);
void print_expense(expense ep);
void print_expense_list(ExpenseList el);
void calc_expenses(employeeListE el, ExpenseList ep);


/// Main
/*
    The main function should:
        Create an EmployeeList by calling create_employee_list()
        Read employees into EmployeeList by calling read_employees(...)
        Print the EmployeeList by calling print_employee_list(...)

        Create an ExpenseList by calling create_expense_list()
        Read expenses into ExpenseList by calling read_expenses(...)
        Print the ExpenseList by calling print_expense_list(...)

        Call calc_expenses(...) to compile and print expense report to screen
*/

int main()
{
    // Testing
    //employee_E ls = {1, "Archer, Malory", "CEO", 500000.0};

    //Testing done

    employeeListE ls = create_employee_list();

    int countResult = read_employees(&ls);

    //print_employee(ls);
    print_employee_list(ls);

    ExpenseList el = create_expense_list();

    int expenseResult = read_expenses(&el);

    print_expense_list(el);

    calc_expenses(ls, el);

    return 0;
}

/// Create employee list
/*
    The create_employee_list() function accepts no arguments and
    returns an EmployeeList to the calling function.
    It should set the 'length' and 'count' to correct values.
*/

employeeListE create_employee_list()
{
    employeeListE ls;
    ls.length = EMPLOYEE_LIST_LENGTH;
    ls.count = 0;

    return ls;
}


/// Read employees into list
/*
    The read_employees(...) function should accept an EmployeeList reference
    as an argument and return an integer with the correct count of employees
    in the list. The data below needs to be copied to an array if strings
    and then copied to the EmployeeList reference.

    "1|Archer, Malory|CEO|500000.0"
    "2|Archer, Sterling|Agent|250000.0"
    "3|Kane, Lana|Agent|300000.0"
    "4|Figus, Ceril|Accountant|100000.0"
    "5|Tunt, Cheryl|Secretary|65000.0"
    "6|Poovey, Pam|HR|85000.0"
*/

int read_employees(employeeListE *ls)
{
    employee_E ph;
    char employeeStr[100][100];
    int employeeStrCount = 0;

    strcpy(employeeStr[0], "1|Archer, Malory|CEO|500000.0");
    employeeStrCount ++;
    strcpy(employeeStr[1], "2|Archer, Sterling|Agent|250000.0");
    employeeStrCount ++;
    strcpy(employeeStr[2], "3|Kane, Lana|Agent|300000.0");
    employeeStrCount ++;
    strcpy(employeeStr[3], "4|Figus, Ceril|Accountant|100000.0");
    employeeStrCount ++;
    strcpy(employeeStr[4], "5|Tunt, Cheryl|Secretary|65000.0");
    employeeStrCount ++;
    strcpy(employeeStr[5], "6|Poovey, Pam|HR|85000.0");
    employeeStrCount ++;

    char *token;

    for(int i = 0; i < employeeStrCount; i ++)
    {
       token = strtok(employeeStr[i], "|");
       ph.id = atoi(token);
       token = strtok(NULL, "|");
       strcpy(ph.name, token);
       token = strtok(NULL, "|");
       strcpy(ph.position, token);
       token = strtok(NULL, "|");
       ph.salary = atof(token);
       ls->array[i] = ph;
    }
    ls->count = employeeStrCount;

    return employeeStrCount;
}

/// Print employee to screen
/*
    The print_employee(...) function accepts an Employee as an argument and
    returns nothing.  It should prints the data as (for record 1):

        ID:        1
        Name:      Archer, Malory
        Position:  CEO
        Salary:    $500000.00
*/

void print_employee(employee_E ls)
{
    printf("ID: %d\n", ls.id);
    printf("Name: %s\n", ls.name);
    printf("Position: %s\n", ls.position);
    printf("Salary: $%.2f\n", ls.salary);
}


/// Print all employees to screen
/*
    The print_employee_list(...) function accepts an EmployeeList as an argument
    and returns nothing. It should print the list as:

        I.S.I.S. Employees

        ID:        1
        Name:      Archer, Malory
        Position:  CEO
        Salary:    $500000.00

        ID:        2
        Name:      Archer, Sterling
        Position:  Agent
        Salary:    $250000.00

        ID:        3
        Name:      Kane, Lana
        ...
*/

void print_employee_list(employeeListE lst)
{
    printf("I.S.I.S. Employees\n\n");

    for(int i = 0; i < lst.count; i++)
    {
        print_employee(lst.array[i]);
        printf("\n");
    }
}

/// Create expense list
/*
    The create_expense_list() function accepts no arguments and
    returns an ExpenseList to the calling function.
    It should set the 'length' and 'count' to correct values.
*/

ExpenseList create_expense_list()
{
    ExpenseList el;
    el.count = 0;
    el.length = EXPENSE_LIST_LENGTH;
    return el;
}

/// Read expenses into list
/*
    The read_expenses(...) function should accept an ExpenseList reference
    as an argument and return an integer with the correct count of expenses
    in the list. The data below needs to be copied to an array if strings
    and then copied to the ExpenseList reference.

    "1,Dinner,456.23"
    "1,Air Travel,692.12"
    "1,Spa Day,725.00"
    "2,Bar Bill,392.34"
    "2,Glenghoulie Blue,320.00"
    "2,Bar Bill,523.54"
    "3,Explosives,550.00"
    "3,Firearms,2343.56"
    "3,Amunition,245.98"
    "4,Lunch,52.45"
    "4,Ledger,23.45"
    "5,Copy Paper,56.23"
    "5,Staples,12.09"
    "6,Milk,4.50"
    "6,Cheese,7.89"
*/

int read_expenses(ExpenseList *el)
{
    expense ep;
    char expenseStr[100][100];
    int expenseCount = 0;

    strcpy(expenseStr[0], "1,Dinner,456.23");
    expenseCount++;
    strcpy(expenseStr[1], "1,Air Travel,692.12");
    expenseCount++;
    strcpy(expenseStr[2], "1,Spa Day,725.00");
    expenseCount++;
    strcpy(expenseStr[3], "2,Bar Bill,392.34");
    expenseCount++;
    strcpy(expenseStr[4], "2,Glenghoulie Blue,320.00");
    expenseCount++;
    strcpy(expenseStr[5], "2,Bar Bill,523.54");
    expenseCount++;
    strcpy(expenseStr[6], "3,Explosives,550.00");
    expenseCount++;
    strcpy(expenseStr[7], "3,Firearms,2343.56");
    expenseCount++;
    strcpy(expenseStr[8], "3,Ammunition,245.98");
    expenseCount++;
    strcpy(expenseStr[9], "4,Lunch,52.45");
    expenseCount++;
    strcpy(expenseStr[10], "4,Ledger,23.45");
    expenseCount++;
    strcpy(expenseStr[11], "5,Copy Paper,56.23");
    expenseCount++;
    strcpy(expenseStr[12], "5,Staples,12.09");
    expenseCount++;
    strcpy(expenseStr[13], "6,Milk,4.50");
    expenseCount++;
    strcpy(expenseStr[14], "6,Cheese,7.89");
    expenseCount++;

    char *token;

    for(int i = 0; i < expenseCount; i ++)
    {
       token = strtok(expenseStr[i], ",");
       ep.personID = atoi(token);
       token = strtok(NULL, ",");
       strcpy(ep.description, token);
       token = strtok(NULL, ",");
       ep.cost = atof(token);
       el->array[i] = ep;
    }
    el->count = expenseCount;

    return expenseCount;
}

/// Print expense to screen
/*
    The print_expense(...) function accepts an Expense as an argument and
    returns nothing.  It should prints the data as (for record 1):

        Employee ID:  1
        Description:  Air Travel
        Cost:         $692.12
*/

void print_expense(expense ep)
{
    printf("Employee ID: %d\n", ep.personID);
    printf("Description: %s\n", ep.description);
    printf("Cost: %.2f\n", ep.cost);
}


/// Print all expenses to screen
/*
    The print_expense_list(...) function accepts an ExpenseList as an argument
    and returns nothing. It should print the list as:

        I.S.I.S. Expenses

        Employee ID:  1
        Description:  Dinner
        Cost:         $456.23

        Employee ID:  1
        Description:  Air Travel
        Cost:         $692.12

        Employee ID:  1
        Description:  Spa Day
        ...
*/

void print_expense_list(ExpenseList el)
{
    printf("I.S.I.S. Expenses\n");

    for(int i = 0; i < el.count; i++)
    {
        print_expense(el.array[i]);
        printf("\n");
    }
}

/// Calculate the expenses for each employee
/*
    The calc_expenses(...) function accepts the EmployeeList and ExpenseList as
    arguments and returns nothing. It should print an expense report for each
    employee.  It should loop through each employee, printing the employee's
    stated expenses and the total as shown below:

        1 Archer, Malory CEO $500000.00
                Dinner $456.23
                Air Travel $692.12
                Spa Day $725.00
        Total: $1873.35

        2 Archer, Sterling Agent $250000.00
                Bar Bill $392.34
                Glenghoulie Blue $320.00
                Bar Bill $523.54
        Total: $1235.88

        3 Kane, Lana Agent $300000.00
                Explosives $550.00
        ...
*/

void calc_expenses(employeeListE el, ExpenseList ep)
{
    double sum = 0.0;

    for(int i = 0; i < el.count; i++)
    {
        sum = 0.0;
        printf("%d %s %s $%.2f\n", el.array[i].id, el.array[i].name, el.array[i].position, el.array[i].salary);
        for(int j = 0; j < ep.count; j++)
        {
            if(el.array[i].id == ep.array[j].personID)
            {
                printf("\t%s $%.2f\n", ep.array[j].description, ep.array[j].cost);
                sum += ep.array[j].cost;
            }
        }
        printf("Total: $%.2f\n\n", sum);
    }
}

/// Sample complete output from app
/*
I.S.I.S. Employees

ID:        1
Name:      Archer, Malory
Position:  CEO
Salary:    $500000.00

ID:        2
Name:      Archer, Sterling
Position:  Agent
Salary:    $250000.00

ID:        3
Name:      Kane, Lana
Position:  Agent
Salary:    $300000.00

ID:        4
Name:      Figus, Ceril
Position:  Accountant
Salary:    $100000.00

ID:        5
Name:      Tunt, Cheryl
Position:  Secretary
Salary:    $65000.00

ID:        6
Name:      Poovey, Pam
Position:  HR
Salary:    $85000.00

I.S.I.S. Expenses

Employee ID:  1
Description:  Dinner
Cost:         $456.23

Employee ID:  1
Description:  Air Travel
Cost:         $692.12

Employee ID:  1
Description:  Spa Day
Cost:         $725.00

Employee ID:  2
Description:  Bar Bill
Cost:         $392.34

Employee ID:  2
Description:  Glenghoulie Blue
Cost:         $320.00

Employee ID:  2
Description:  Bar Bill
Cost:         $523.54

Employee ID:  3
Description:  Explosives
Cost:         $550.00

Employee ID:  3
Description:  Firearms
Cost:         $2343.56

Employee ID:  3
Description:  Amunition
Cost:         $245.98

Employee ID:  4
Description:  Lunch
Cost:         $52.45

Employee ID:  4
Description:  Ledger
Cost:         $23.45

Employee ID:  5
Description:  Copy Paper
Cost:         $56.23

Employee ID:  5
Description:  Staples
Cost:         $12.09

Employee ID:  6
Description:  Milk
Cost:         $4.50

Employee ID:  6
Description:  Cheese
Cost:         $7.89

1 Archer, Malory CEO $500000.00
        Dinner $456.23
        Air Travel $692.12
        Spa Day $725.00
Total: $1873.35

2 Archer, Sterling Agent $250000.00
        Bar Bill $392.34
        Glenghoulie Blue $320.00
        Bar Bill $523.54
Total: $1235.88

3 Kane, Lana Agent $300000.00
        Explosives $550.00
        Firearms $2343.56
        Amunition $245.98
Total: $3139.54

4 Figus, Ceril Accountant $100000.00
        Lunch $52.45
        Ledger $23.45
Total: $75.90

5 Tunt, Cheryl Secretary $65000.00
        Copy Paper $56.23
        Staples $12.09
Total: $68.32

6 Poovey, Pam HR $85000.00
        Milk $4.50
        Cheese $7.89
Total: $12.39


Process returned 0 (0x0)   execution time : 1.642 s
Press any key to continue.

*/

#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);
int exit_program (int a, int b);

void run_operation (int choice, int a, int b);
void ignore_choice (int choice, int a, int b);

#define NUM_OPS 5

/* Table of arithmetic operations, indexed by the user's choice (0-4). */
int (*operations[NUM_OPS]) (int, int) = { add, subtract, multiply, divide, exit_program };

/*
 * Table of handlers, indexed by whether the choice is valid:
 *   [0] -> invalid choice, do nothing and prompt again
 *   [1] -> valid choice, call the matching operation
 * This lets us dispatch without any conditional statements.
 */
void (*handlers[2]) (int, int, int) = { ignore_choice, run_operation };

int main (void)
{
    /* IMPLEMENT ME: Insert your algorithm here */
    int a = 6;
    int b = 3;
    char input;

    printf ("Operand 'a' : %d | Operand 'b' : %d", a, b);
    printf ("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit):");
    fflush (stdout);

    while (scanf (" %c", &input) == 1) {
        int choice = input - '0';
        handlers[(unsigned) choice < NUM_OPS] (choice, a, b);

        printf ("Operand 'a' : %d | Operand 'b' : %d", a, b);
        printf ("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit):");
        fflush (stdout);
    }

    return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b; }

int subtract (int a, int b) { printf ("Subtracting 'a' and 'b'\n"); return a - b; }

int multiply (int a, int b) { printf ("Multiplying 'a' and 'b'\n"); return a * b; }

int divide (int a, int b) { printf ("Dividing 'a' and 'b'\n"); return a / b; }

int exit_program (int a, int b)
{
    (void) a;
    (void) b;
    fflush (stdout);
    exit (1);
}

void run_operation (int choice, int a, int b)
{
    int x = operations[choice] (a, b);
    printf ("X = %d\n", x);
}

void ignore_choice (int choice, int a, int b)
{
    (void) choice;
    (void) a;
    (void) b;
}

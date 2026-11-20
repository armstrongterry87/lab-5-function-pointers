#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);
int quit (int a, int b);

int main (void)
{
    /* IMPLEMENT ME: Insert your algorithm here */
    int a = 6;
    int b = 3;
    char input;

    /* Array of function pointers: the user's choice is the index */
    int (*operations[]) (int, int) = { add, subtract, multiply, divide, quit };
    const unsigned int num_ops = sizeof (operations) / sizeof (operations[0]);

    printf ("Operand 'a' : %d | Operand 'b' : %d\n", a, b);

    /*
     * Input validation without conditional statements:
     * - input - '0' turns the character into an index into operations[].
     * - Casting to unsigned makes characters below '0' wrap to a large value,
     *   so a single bounds check (>= num_ops) rejects everything outside
     *   '0' - '4' and the loop simply prompts again.
     * - input is reset to '4' (exit) before each read so that, if scanf hits
     *   end of input and leaves input untouched, the index is still in bounds
     *   and the program exits cleanly instead of reading past the array.
     */
    do {
        input = '4';
        printf ("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
        fflush (stdout);
    } while (scanf (" %c", &input) == 1 && (unsigned int) (input - '0') >= num_ops);

    /* Call the selected operation through the function pointer */
    printf ("x = %d\n", operations[input - '0'] (a, b));

    return 0;
}

/* IMPLEMENT ME: Define your functions here */

/* Each operation prints what it is doing and returns the result for a, b. */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b; }

int subtract (int a, int b) { printf ("Subtracting 'b' from 'a'\n"); return a - b; }

int multiply (int a, int b) { printf ("Multiplying 'a' and 'b'\n"); return a * b; }

int divide (int a, int b) { printf ("Dividing 'a' by 'b'\n"); return a / b; }

/*
 * Option 4: terminate the program.
 * It has the same signature as the arithmetic functions so it can live in
 * the same function pointer array; it never returns. The exit status (1)
 * matches the reference implementation func_ptr_ref.
 */
int quit (int a, int b)
{
    (void) a;
    (void) b;
    exit (1);
}

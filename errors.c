#include "monty.h"
#include <stdarg.h>

/**
* err - Print an error message and exit with a status of 99.
* @error_code: Error code.
*/
void err(int error_code, ...)
{
va_list ag;

va_start(ag, error_code);
fprintf(stderr, "L%d: ", va_arg(ag, int));
if (error_code == 1)
fprintf(stderr, "usage: push integer\n");
if (error_code == 2)
fprintf(stderr, "Error: malloc failed\n");
if (error_code == 3)
fprintf(stderr, "Error: can't open file %s\n", va_arg(ag, char *));
if (error_code == 4)
fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
if (error_code == 5)
fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
if (error_code == 6)
fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
if (error_code == 7)
fprintf(stderr, "L%d: can't swap, stack too short\n", va_arg(ag, int));
if (error_code == 8)
fprintf(stderr, "L%d: can't add, stack too short\n", va_arg(ag, int));
if (error_code == 9)
fprintf(stderr, "L%d: can't sub, stack too short\n", va_arg(ag, int));
if (error_code == 10)
fprintf(stderr, "L%d: division by zero\n", va_arg(ag, int));
if (error_code == 11)
fprintf(stderr, "L%d: can't mod, stack too short\n", va_arg(ag, int));
if (error_code == 12)
fprintf(stderr, "L%d: can't Pchar, stack empty\n", va_arg(ag, int));
if (error_code == 13)
fprintf(stderr, "L%d: can't pchar, value out of range\n", va_arg(ag, int));
if (error_code == 14)
fprintf(stderr, "L%d: can't rotr, stack too short\n", va_arg(ag, int));
if (error_code == 15)
fprintf(stderr, "L%d: can't rotl, stack too short\n", va_arg(ag, int));
va_end(ag);
free_nodes();
exit(EXIT_FAILURE);
}

/**
* more_err - Print an error message and exit with a status of 99.
* @error_code: Error code.
*/
void more_err(int error_code, ...)
{
va_list ag;

va_start(ag, error_code);
fprintf(stderr, "L%d: unknown instruction %s\n", va_arg(ag, int), va_arg(ag, char *));
va_end(ag);
free_nodes();
exit(EXIT_FAILURE);
}

/**
* string_err - Print an error message and exit with a status of 99.
* @error_code: Error code.
*/
void string_err(int error_code, ...)
{
va_list ag;
unsigned int ln;

va_start(ag, error_code);
ln = va_arg(ag, unsigned int);
if (error_code == 11)
fprintf(stderr, "L%d: can't Pchar, stack empty\n", ln);
if (error_code == 12)
fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
va_end(ag);
free_nodes();
exit(EXIT_FAILURE);
}

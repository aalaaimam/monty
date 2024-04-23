#include "monty.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
* err - print an error message and exit the program
* @error_code: the error code
* @line_number: the line number
* @format: the error message format string
*/
void err(int error_code, unsigned int line_number, char *format, ...)
{
va_list ag;

va_start(ag, format);
fprintf(stderr, "L%u: ", line_number);
vfprintf(stderr, format, ag);
va_end(ag);

free_nodes(head);
exit(error_code);
}

/**
* more_err - print an error message and exit the program
* @error_code: the error code
* @line_number: the line number
* @format: the error message format string
*/
void more_err(int error_code, unsigned int line_number, char *format, ...)
{
va_list ag;

va_start(ag, format);
fprintf(stderr, "L%u: ", line_number);
vfprintf(stderr, format, ag);
va_end(ag);

free_nodes(head);
exit(error_code);
}

/**
* string_err - print an error message and exit the program
* @error_code: the error code
* @line_number: the line number
*/
void string_err(int error_code, unsigned int line_number)
{
fprintf(stderr, "L%u: unknown instruction string\n", line_number);

free_nodes(head);
exit(error_code);
}

#include "monty.h"

/**
* print_char - Prints the character at the top of the stack.
* @stack: Pointer to the pointer to the stack.
* @line_number: Line number of the instruction.
*/
void print_char(stack_t **stack, unsigned int line_number)
{
int ascii;

if (*stack == NULL)
{
string_err(12, line_number);
}
ascii = (*stack)->n;
if (ascii < 0 || ascii > 127)
{
string_err(12, line_number);
}
printf("%c\n", ascii);
}

/**
* print_str - Prints the string starting at the top of the stack.
* @stack: Pointer to the pointer to the stack.
* @line_number: Line number of the instruction.
*/
void print_str(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;

(void)line_number;

while (tmp != NULL && tmp->n != 0 && isascii(tmp->n))
{
printf("%c", tmp->n);
tmp = tmp->next;
}
printf("\n");
}

#include "monty.h"

/**
* mul_nodes - Multiplies the top two elements of the stack.
* @stack: Pointer to the pointer to the stack.
* @line_number: Line number of the instruction.
*/
void mul_nodes(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
more_err(8, line_number, "mul");
}
(*stack)->next->n *= (*stack)->n;
pop_top(stack, line_number);
}

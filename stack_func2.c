#include "monty.h"

/**
* swap_nodes - Swaps the top two elements of the stack.
* @stack: Pointer to the pointer to the stack.
* @line_number: Line number of the instruction.
*/
void swap_nodes(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

if (*stack == NULL || (*stack)->next == NULL)
{
more_err(7, line_number);
}
tmp = (*stack)->next;
(*stack)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *stack;
tmp->next = *stack;
tmp->prev = NULL;
(*stack)->prev = tmp;
*stack = tmp;
}

/**
* add_nodes - Adds the top two elements of the stack.
* @stack: Pointer to the pointer to the stack.
* @line_number: Line number of the instruction.
*/
void add_nodes(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
more_err(8, line_number, "add");
}
(*stack)->next->n += (*stack)->n;
pop_top(stack, line_number);
}

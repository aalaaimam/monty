#include "monty.h"

/**
* add_to_stack - Adds a node to the stack.
* @stack: Pointer to the pointer to the stack.
* @n: Number to add to the stack.
*/
void add_to_stack(stack_t **stack, int n)
{
stack_t *tmp;

tmp = malloc(sizeof(stack_t));
if (tmp == NULL)
{
dprintf(STDERR_FILENO, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
tmp->n = n;
tmp->prev = NULL;
tmp->next = *stack;
if (*stack != NULL)
(*stack)->prev = tmp;
*stack = tmp;
}

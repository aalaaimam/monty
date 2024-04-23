#include "monty.h"

/**
* main - entry point
* @argc: arguments count
* @argv: list of arguments
* Return: always 0
*/
int main(int argc, char *argv[])
{
stack_t *head = NULL; /* Declare head locally in main() */

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

open_file(argv[1], &head); /* Pass head as a parameter */
free_nodes(&head); /* Pass head as a parameter */
return (0);
}

/**
* create_node - Creates a node.
* @n: Number to go inside the node.
* Return: Upon success, a pointer to the node. Otherwise NULL.
*/
stack_t *create_node(int n)
{
stack_t *node = malloc(sizeof(stack_t));
if (node == NULL)
err(4);
node->next = NULL;
node->prev = NULL;
node->n = n;
return (node);
}

/**
* free_nodes - Frees nodes in the stack.
* @head: Pointer to the head of the stack.
*/
void free_nodes(stack_t **head)
{
stack_t *tmp;

if (*head == NULL)
return;

while (*head != NULL)
{
tmp = *head;
*head = (*head)->next;
free(tmp);
}
}

/**
* add_to_queue - Adds a node to the queue.
* @new_node: Pointer to the new node.
* @head: Pointer to the head of the stack.
* @ln: line number of the opcode.
*/
void add_to_queue(stack_t **new_node, stack_t **head, __attribute__((unused)) unsigned int ln)
{
stack_t *tmp;

if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (*head == NULL)
{
*head = *new_node;
return;
}
tmp = *head;
while (tmp->next != NULL)
tmp = tmp->next;

tmp->next = *new_node;
(*new_node)->prev = tmp;
}

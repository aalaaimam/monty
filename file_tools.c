#include "monty.h"

void open_file(char *file_name, stack_t **head)
{
/* Implementation of open_file */
}

void free_nodes(stac_t **head)
{
/* Implementation of free_nodes */
}

stack_t *create_node(int data)
{
stack_t *node = malloc(sizeof(stack_t));
if (node == NULL)
{
/* Handle error */
}
node->data = data;
node->next = NULL;
return node;
}

void add_to_queue(stack_t **new_node, stack_t **head, unsigned int ln)
{
/* Implementation of add_to_queue */
}

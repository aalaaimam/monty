#include <fcntl.h>
#include <unistd.h>
#include "monty.h"

/**
* open_file - Opens a file.
* @file_name: Name of the file to open.
* Return: File descriptor on success, -1 on failure.
*/
int open_file(char *file_name)
{
int fd;

fd = open(file_name, O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_name);
exit(EXIT_FAILURE);
}
return (fd);
}

/**
* free_nodes - Frees nodes in the stack.
* @head: Pointer to the head of the stack.
*/
void free_nodes(stack_t *head)
{
stack_t *tmp;

while (head != NULL)
{
tmp = head;
head = head->next;
free(tmp);
}
}

/**
* create_node - Creates a node.
* @n: Number to go inside the node.
* Return: Upon success, a pointer to the node. Otherwise, NULL.
*/
stack_t *create_node(int n)
{
stack_t *node;

node = malloc(sizeof(stack_t));
if (node == NULL)
{
dprintf(STDERR_FILENO, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
node->n = n;
node->next = NULL;
return (node);
}

/**
* add_to_queue - Adds a node to the queue.
* @new_node: Pointer to the new node.
* @head: Pointer to the head of the stack.
*/
void add_to_queue(stack_t **new_node, stack_t **head)
{
stack_t *tmp;

if (*head == NULL)
{
*head = *new_node;
return;
}
tmp = *head;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *new_node;
}

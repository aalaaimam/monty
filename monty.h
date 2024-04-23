#ifndef MONTY_H_INCLUDED
#define MONTY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function prototypes
void open_file(char *file_name, stack_t **head);
void free_nodes(stack_t **head);
stack_t *create_node(int data);
void add_to_queue(stack_t **new_node, stack_t **head);
void more_err(int error_code, unsigned int line_number, char *format, ...);
void string_err(int error_code, unsigned int line_number);

#endif /* MONTY_H_INCLUDED */

// In file_tools.c
#include "monty.h"

int open_file(char *file_name)
{
int fd;

fd = open(file_name, O_RDONLY);
if (fd == -1)
{
perror("Error: Can't open file");
exit(EXIT_FAILURE);
}
return (fd);
}

void free_nodes(stack_t **head)
{
stack_t *tmp;

while (*head != NULL)
{
tmp = *head;
*head = (*head)->next;
free(tmp);
}
}

stack_t *create_node(int n)
{
stack_t *node = malloc(sizeof(stack_t));
if (node == NULL)
{
dprintf(STDERR_FILENO, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
node->n = n;
node->next = NULL;
return node;
}

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

// In main.c
#include "monty.h"

int main(int argc, char *argv[])
{
stack_t *head = NULL;
int fd, line_number;
char *buffer = NULL;
size_t bufsize = 0;
ssize_t n_read;
struct instruction instruction;

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: monty file\n");
exit(EXIT_FAILURE);
}

fd = open_file(argv[1]);
line_number = 1;
while ((n_read = getline(&buffer, &bufsize, fd)) != -1)
{
instruction = get_instruction(buffer, line_number);
execute_instruction(&head, instruction, line_number);
line_number++;
}

free(buffer);
close(fd);
free_nodes(&head);
return 0;
}

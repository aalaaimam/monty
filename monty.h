#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
/**
* struct stack_t - A structure representing a stack node
*
* @n: The integer data stored in the node
* @prev: A pointer to the previous node in the stack
*/
typedef struct stack_t
{
int n;
struct stack_t *prev;
} stack_t;
void open_file(char *file_name, stack_t **head);
void free_nodes(stack_t **head);
stack_t *create_node(int data);
void add_to_queue(stack_t **new_node, stack_t **head, unsigned int ln);

#endif

#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t
{
int data;
struct stack_t *next;
} stack_t;

void open_file(char *file_name, stack_t **head);
void free_nodes(stack_t **head);
stack_t *create_node(int data);
void add_to_queue(stack_t **new_node, stack_t **head, unsigned int ln);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
* main - Entry point for the Monty Bytecode Interpreter.
* @argc: Number of arguments.
* @argv: Array of arguments.
* Return: Always 0.
*/
int main(int argc, char *argv[])
{
stack_t *head = NULL;
int fd, line_number;
char *buffer = NULL;
size_t bufsize = 0;
ssize_t n_read;
instruction_t instruction;

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: monty file\n");
exit(EXIT_FAILURE);
}

fd = open_file(argv[1]);
line_number = 1;
while ((n_read = getline(while ((n_read = getline(while ((n_read = getline(&buffer, &bufsize, fd)) != -1)buffer, while ((n_read = getline(&buffer, &bufsize, fd)) != -1)bufsize, fd)) > 0)buffer, while ((n_read = getline(while ((n_read = getline(&buffer, &bufsize, fd)) != -1)buffer, while ((n_read = getline(&buffer, &bufsize, fd)) != -1)bufsize, fd)) > 0)bufsize, fd)) > 0)
{
instruction = get_instruction(buffer, line_number);
execute_instruction(&head, instruction, line_number);
line_number++;
}
free(buffer);
fclose(fd);
free_nodes(head);
return (0);
}

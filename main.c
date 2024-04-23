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

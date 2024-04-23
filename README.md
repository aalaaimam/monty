# 0x19. C - Stacks, Queues - LIFO, FIFO

## Learning Objectives
- Understand LIFO and FIFO concepts
- Know when to use a stack and a queue
- Understand common implementations of stacks and queues
- Know common use cases of stacks and queues
- Understand proper use of global variables


## Requirements
- Allowed editors: vi, vim, emacs
- Compilation: gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
- All files should end with a new line
- Code should use the Betty style
- Maximum one global variable allowed
- Maximum five functions per file
- C standard library allowed
- Prototypes of all functions should be included in monty.h
- Header files should be include guarded

## Data Structures
- Use the following data structures:
  ```c
  /**
   * struct stack_s - doubly linked list representation of a stack (or queue)
   * @n: integer
   * @prev: points to the previous element of the stack (or queue)
   * @next: points to the next element of the stack (or queue)
   *
   * Description: doubly linked list node structure
   * for stack, queues, LIFO, FIFO
   */
  typedef struct stack_s
  {
          int n;
          struct stack_s *prev;
          struct stack_s *next;
  } stack_t;

  /**
   * struct instruction_s - opcode and its function
   * @opcode: the opcode
   * @f: function to handle the opcode
   *
   * Description: opcode and its function
   * for stack, queues, LIFO, FIFO
   */
  typedef struct instruction_s
  {
          char *opcode;
          void (*f)(stack_t **stack, unsigned int line_number);
  } instruction_t;

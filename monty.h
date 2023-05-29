#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>


#define BUF_LENGTH 1024


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct retn_queue_s - Return value of opcodes and if list is stack/queue
 * @opcode_return: Return value of the void opcode functions
 * @queue_val: 1 if list is a queue, 0 if it's a stack
 **/
typedef struct retn_queue_s
{
	int opcode_return;
	int queue_val;
} opret_q;

extern opret_q ret_and_q;


void pall(stack_t **stack, unsigned int line_);
void pint(stack_t **stack, unsigned int line_);
void pop(stack_t **stack, unsigned int line_);
void swap(stack_t **stack, unsigned int line_);
void add(stack_t **stack, unsigned int line_);
void sub(stack_t **stack, unsigned int line_);
void _div(stack_t **stack, unsigned int line_);
void mod(stack_t **stack, unsigned int line_);
void pchar(stack_t **stack, unsigned int line_);
void pstr(stack_t **stack, unsigned int line_);
void mul(stack_t **stack, unsigned int line_);
void rotr(stack_t **stack, unsigned int line_);
void rotl(stack_t **stack, unsigned int line_);

void add_node(stack_t **stack, int push_value);
void add_node_end(stack_t **stack, int push_value);

char *find_command(char *line, stack_t **stack, unsigned int line_);
int check_codes(char *command, stack_t **stack, size_t line_);
int int_check(char *push_arg);
void free_and_exit(char *line, FILE *file, stack_t *stack);
void free_stack(stack_t *stack);
/*ssize_t _getline(char **buf, size_t *size, FILE file_strm);*/

#endif

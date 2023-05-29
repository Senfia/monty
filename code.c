#include "monty.h"

/**
 * pall - Print every value in the stack
 * @stack: Double pointer to the top of the stack
 * @line_: The line number the command was found in the file
 **/
void pall(stack_t **stack, unsigned int line_)
{
	stack_t *wlk = *stack;

	(void)line_;
	for (; wlk != NULL; wlk = wlk->next)
	{
		printf("%d\n", wlk->n);
	}
}

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_: The line number the command was found in the file
 **/
void pop(stack_t **stack, unsigned int line_)
{
	stack_t *kill_node, *wlk = *stack;

	if (wlk == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		kill_node = wlk;
		*stack = wlk->next;
		if (wlk != NULL)
			wlk->prev = NULL;
		free(kill_node);
	}
}

/**
 * swap - Put the second element on top of the stack, and put the top element
 * in the second position
 * @stack: Double pointer to the top of the stack
 * @line_: The line number the command was found in the file
 **/
void swap(stack_t **stack, unsigned int line_)
{
	stack_t *wlk = *stack;
	int tmp;

	if (wlk == NULL || wlk->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		tmp = wlk->n;
		wlk->n = wlk->next->n;
		wlk->next->n = tmp;
	}
}

/**
 * pint - Print the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_: The line number the command was found in the file
 **/
void pint(stack_t **stack, unsigned int line_)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		printf("%d\n", (*stack)->n);
	}
}

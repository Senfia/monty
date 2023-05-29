#include "monty.h"

/**
 * pchar - Prints the character value of the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_: The line number where the command was found
 **/
void pchar(stack_t **stack, unsigned int line_)
{
	if (*stack != NULL)
	{
		if ((*stack)->n < 0 || (*stack)->n > 127)
		{
			printf("L%u: can't pchar, value out of range\n", line_);
			ret_and_q.opcode_return = 1;
		}
		if (ret_and_q.opcode_return == 0)
		{
			putchar((*stack)->n);
			putchar('\n');
		}
	}
	else
	{
		printf("L%u: can't pchar, stack empty\n", line_);
		ret_and_q.opcode_return = 1;
	}
}

/**
 * pstr - Prints the string representation of the stack
 * @stack: Double pointer to the top of the stack
 * @line_: The line number where the command was found
 **/
void pstr(stack_t **stack, unsigned int line_)
{
	stack_t *wlk;

	(void) line_;

	if (*stack != NULL)
	{
		wlk = *stack;
		for (; wlk != NULL && wlk->n > 0 && wlk->n <= 127;
			wlk = wlk->next)
		{
			putchar(wlk->n);
		}
	}
	putchar('\n');
}

#include "monty.h"

/**
 * add - Add the top two values of the stack, store the sum
 * in the second position,
 * set *stack to the second node, and remove the top node
 * @stack: Double pointer to the top of the stack
 * @line_: The line number the command was found in the monty file
 **/
void add(stack_t **stack, unsigned int line_)
{
	stack_t *wlk;

	wlk = *stack;

	if (wlk == NULL || wlk->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		wlk->next->n += wlk->n;
		pop(stack, line_);
	}
}

/**
 * sub - Subtract the top element of the stack from the second element,
 * store the result in the second position, set *stack to the second node,
 * and remove the top node
 * @stack: Double pointer to the top of the stack
 * @line_: The line number the command was found in the monty file
 **/
void sub(stack_t **stack, unsigned int line_)
{
	stack_t *wlk;

	wlk = *stack;

	if (wlk == NULL ||  wlk->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		wlk->next->n -= wlk->n;
		pop(stack, line_);
	}
}

/**
 * _div - Divide the second element of the stack by the first
 * element of the stack,
 * store the result in the second position, set *stack to the second node,
 * and remove the top node
 * @stack: Double pointer to the top of the stack
 * @line_: The line number the command was found in the monty file
 **/
void _div(stack_t **stack, unsigned int line_)
{
	stack_t *wlk;

	wlk = *stack;

	if (wlk == NULL || wlk->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (wlk != NULL && ret_and_q.opcode_return != 1 && wlk->n == 0)
	{
		printf("L%u: division by zero\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		wlk->next->n /= wlk->n;
		pop(stack, line_);
	}
}

/**
 * mul - Multiply the top two values of the stack, store
 * the result in the second
 * position, set *stack to the second node, and remove the top node
 * @stack: Double pointer to the top of the stack
 * @line_: The line number the command was found in the monty file
 **/
void mul(stack_t **stack, unsigned int line_)
{
	stack_t *wlk;

	wlk = *stack;

	if (wlk == NULL || wlk->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		wlk->next->n *= wlk->n;
		pop(stack, line_);
	}
}

/**
 * mod - Modulo the second element of the stack by the
 * first element of the stack,
 * store the result in the second position, set *stack to the second node,
 * and remove the top node
 * @stack: Double pointer to the top of the stack
 * @line_: The line number the command was found in the monty file
 **/
void mod(stack_t **stack, unsigned int line_)
{
	stack_t *wlk;

	wlk = *stack;
	if (wlk == NULL || wlk->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (wlk != NULL && wlk->n == 0 && ret_and_q.opcode_return != 1)
	{
		printf("L%u: division by zero\n", line_);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		wlk->next->n %= wlk->n;
		pop(stack, line_);
	}
}

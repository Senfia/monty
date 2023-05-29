#include "monty.h"

/**
 * rotl - Rotates the stack to the left, moving the top element to the bottom
 *        and making the second element the new top
 * @stack: Double pointer to the top of the stack
 * @line_: The line number where the command was found
 **/
void rotl(stack_t **stack, unsigned int line_)
{
	stack_t *wlk, *first_node, *second_node;

	(void) line_;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		wlk = first_node = *stack;
		second_node = wlk->next;

		for (; wlk->next != NULL; wlk = wlk->next)
		{
		}

		wlk->next = first_node;
		first_node->prev = wlk;
		first_node->next = NULL;
		second_node->prev = NULL;
		*stack = second_node;
	}
}

/**
 * rotr - Rotates the stack to the right, moving the last element to the top
 * @stack: Double pointer to the top of the stack
 * @line_: The line number where the command was found
 **/
void rotr(stack_t **stack, unsigned int line_)
{
	stack_t *last_node, *second_last_node;

	(void) line_;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last_node = *stack;

		for (; last_node->next != NULL; last_node = last_node->next)
		{
		}

		second_last_node = last_node->prev;
		second_last_node->next = NULL;
		last_node->next = *stack;
		last_node->prev = NULL;
		(*stack)->prev = last_node;
		*stack = last_node;
	}
}

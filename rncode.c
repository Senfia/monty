#include "monty.h"

opret_q ret_and_q = {0, 0};

/**
 * check_codes - Check the found command against all possible opcodes
 * @command: The command found on the line
 * @stack: Double pointer to the top of the stack
 * @line_: The line number where the command was found
 *
 * Return: 1 if no command is found, return opcode_return if command was
 * found. (opcode_return is changed by the opcodes, if they fail)
 **/
int check_codes(char *command, stack_t **stack, size_t line_)
{
	instruction_t opcodes[] = {
		{"rotr", rotr},
		{"rotl", rotl},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"pstr", pstr},
		{"pchar", pchar},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{NULL, NULL}
	};
	size_t i;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(command, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_);
			return (ret_and_q.opcode_return);
		}
	}

	printf("L%lu: unknown instruction %s\n", line_, command);
	ret_and_q.opcode_return = 1;
	return (1);
}

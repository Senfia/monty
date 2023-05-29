#include "monty.h"
#include <stdio.h>

/**
 * main - Iterate through a given file and execute opcode commands
 * @argc: The number of arguments passed to the program
 * @argv: The strings passed to the program
 * Return: 0 on success, 1 if reaches end of the file, exit with EXIT_FAILURE
 *         if any opcode fails
 **/
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *command;
	size_t size = 0, line_num = 1;
	stack_t *stack = NULL;
	int cha;

	if (argc != 2)
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((cha = fgetc(file)) != EOF)
	{
		if (cha == '\n')
		{
			line_num++;
			if (line != NULL)
			{
				command = find_command(line, &stack, line_num);
				if (strcmp(command, "nop") != 0)
					check_codes(command, &stack, line_num);
				free(line);
				line = NULL;
			}
		}
		else
		{
			char *temp = realloc(line, size + 2);

			if (temp == NULL)
			{
				printf("Error: Memory allocation failed\n");
				free_and_exit(line, file, stack);
			}
			line = temp;
			line[size++] = cha;
			line[size] = '\0';
		}

		if (ret_and_q.opcode_return != 0)
			break;
	}

	free_stack(stack);
	free(line);
	fclose(file);
	return (ret_and_q.opcode_return);
}

/**
 * free_and_exit - Free all necessary memory and exit with EXIT_FAILURE
 * @line: The line found using getline()
 * @file: The file opened and being read from
 * @stack: The top of the stack list
 **/
void free_and_exit(char *line, FILE *file, stack_t *stack)
{
	free_stack(stack);
	free(line);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - Free all nodes of the stack
 * @stack: Top of the stack list
 **/
void free_stack(stack_t *stack)
{
	stack_t *current, *next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

#include "monty.h"
/**
 * execute - Execute Monty bytecode instructions.
 * @top: Double pointer to the top of the stack.
 * @line: Input line containing the instruction.
 * @Line_number: Current line number in the input file.
 * @file: Pointer to the input file.
 *
 * Return: Always 0.
 */
int execute(stack_t **top, char *line, unsigned int Line_number, FILE *file)
{
	instruction_t instruction[] = {
	    {"push", push}, {"pall", pall}, {NULL, NULL}};
	char *token, *arg;
	int i = 0;

	token = strtok(line, " ");
	arg = strtok(NULL, " \n\t");

	monty.data = arg;

	while (instruction[i].opcode)
	{
		if (strcmp(instruction[i].opcode, token) == 0)
		{
			instruction[i].f(top, Line_number);
			return (0);
		}
		i++;
	}
	if (instruction[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", Line_number, token);
		exit(EXIT_FAILURE);
	}
	return (0);
	(void)file;
}

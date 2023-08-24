#include "monty.h"
monty_t monty = {NULL, NULL, NULL};
/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	stack_t *top = NULL;
	FILE *file;
	char *line = NULL;
	size_t n = 0;
	int line_number = 0;
	int g = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	monty.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (g > 0)
	{
		line = NULL;
		g = getline(&line, &n, file);
		if (line[0] == '#')
			continue;
		delete_spaces(line);
		monty.line = line;
		line_number++;

		if (g > 0)
			execute(&top, line, line_number, file);
		free(line);
	}
	fclose(file);

	free_stack(top);
	return (0);
}

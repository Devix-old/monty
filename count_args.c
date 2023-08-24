#include "monty.h"
/**
 * is_whitespace - Check if a character is whitespace.
 * @c: The character to be checked.
 *
 * Return: true if the character is whitespace, false otherwise.
 */
bool is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * count_args - Count the number of arguments in a line.
 * @line: The input line to be counted.
 *
 * Return: The number of arguments in the line.
 */
int count_args(char *line)
{
	int args = 0;
	bool in_word = false;
	int i;

	if (line == NULL)
		return (-1);
	for (i = 0; line[i] != '\0'; i++)
	{
		if (is_whitespace(line[i]))
		{
			in_word = false;
		}
		else
		{
			if (!in_word)
			{
				args++;
				in_word = true;
			}
		}
	}
	return (args - 1);
}

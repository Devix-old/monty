#include "monty.h"

/**
 * is_integer - Check if a string represents an integer.
 * @str: The input string to be checked.
 *
 * Return: true if the string represents an integer, false otherwise.
 */
bool is_integer(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}

	return (true);
}

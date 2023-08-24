#include "monty.h"
/**
 * push - Pushes an element onto the stack.
 * @top: Pointer to the top of the stack.
 * @Line_number: Line number in the input file.
 */
void push(stack_t **top, unsigned int Line_number)
{
	stack_t *new_node;

	if (is_integer(monty.data) == false)
	{
		fprintf(stderr, "L%d: usage: push integer\n", Line_number);
		free(monty.line);
		free_stack(*top);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->n = atoi(monty.data);
	new_node->prev = NULL;
	new_node->next = *top;

	if (*top != NULL)
		(*top)->prev = new_node;

	*top = new_node;
}

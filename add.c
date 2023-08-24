#include "monty.h"
/**
 * add - Add the two top elements.
 * @top: Pointer to the top of the stack.
 * @Line_number: Line number in the input file.
 */
void add(stack_t **top, unsigned int Line_number)
{
	stack_t *temp = (*top)->next;

	if (count_nodes(*top) < 2 || *top == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}

	temp->n += (*top)->n;

	pop(top, Line_number);
}

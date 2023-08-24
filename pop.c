#include "monty.h"
/**
 * pop - delete the top.
 * @top: Pointer to the top of the stack.
 * @Line_number: Line number in the input file.
 */
void pop(stack_t **top, unsigned int Line_number)
{

	stack_t *temp;

	if (*top == NULL)
	{

		fprintf(stderr, "L%d: can't pop an empty stack", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *top;
		*top = temp->next;
		free(temp);
	}
}

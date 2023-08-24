#include "monty.h"
/**
 * sub - sub the two top elements.
 * @top: Pointer to the top of the stack.
 * @Line_number: Line number in the input file.
 */
void sub(stack_t **top, unsigned int Line_number)
{
	stack_t *temp;
	int SUB;

	if (count_nodes(*top) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}

	temp = *top;

	SUB = temp->next->n - temp->n;
	temp->next->n = SUB;
	*top = temp->next;
	free(temp);
}

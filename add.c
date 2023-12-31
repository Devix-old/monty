#include "monty.h"
/**
 * add - Add the two top elements.
 * @top: Pointer to the top of the stack.
 * @Line_number: Line number in the input file.
 */
void add(stack_t **top, unsigned int Line_number)
{
	stack_t *temp;
	int sum;

	if (count_nodes(*top) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	temp = *top;

	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*top = temp->next;
	free(temp);
}

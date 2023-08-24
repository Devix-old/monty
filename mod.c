#include "monty.h"
/**
 * mod - mod the two top elements.
 * @top: Pointer to the top of the stack.
 * @Line_number: Line number in the input file.
 */
void mod(stack_t **top, unsigned int Line_number)
{
	stack_t *temp;
	int MOD;

	if (count_nodes(*top) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	temp = *top;

	MOD = temp->next->n % temp->n;
	temp->next->n = MOD;
	*top = temp->next;
	free(temp);
}

#include "monty.h"
/**
 * _div - div the two top elements.
 * @top: Pointer to the top of the stack.
 * @Line_number: Line number in the input file.
 */
void _div(stack_t **top, unsigned int Line_number)
{
	stack_t *temp;
	int DIV;

	if (count_nodes(*top) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	temp = *top;

	DIV = temp->next->n / temp->n;
	temp->next->n = DIV;
	*top = temp->next;
	free(temp);
}

#include "monty.h"
/**
 * pint - Print the element n of the top.
 * @top: Pointer to the top of the stack.
 * @Line_number: Line number in the input file.
 */
void pint(stack_t **top, unsigned int Line_number)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}

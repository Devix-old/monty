#include "monty.h"

/**
 * count_nodes - Counts the number of nodes in a stack.
 * @top: Pointer to the top of the stack.
 *
 * Return: Number of nodes in the stack.
 */
int count_nodes(stack_t *top)
{
	int count = 0;
	stack_t *current = top;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
/**
 * swap - Swap the two top elements.
 * @top: Pointer to the top of the stack.
 * @Line_number: Line number in the input file.
 */
void swap(stack_t **top, unsigned int Line_number)
{
	int SWAP;
	stack_t *temp;

	if (count_nodes(*top) < 2 || *top == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", Line_number);
		free_stack(*top);
		free(monty.line);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->next;

	SWAP = temp->n;
	temp->n = (*top)->n;
	(*top)->n = SWAP;
}

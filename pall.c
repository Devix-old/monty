#include "monty.h"
/**
 * pall - Prints all the elements of a stack.
 * @top: Pointer to the top of the stack.
 * @Line_number: Number of lines
 */
void pall(stack_t **top, unsigned int Line_number)
{
	stack_t *head;

	(void)Line_number;
	head = *top;
	if (head == NULL)
		return;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

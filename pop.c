#include "monty.h"
/**
 *f_pop - removes element from top
 *@head: head of stack
 *@counter: line number
 *Return: nothing
 */
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty\n", counter);
		free_buf();
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = (*head)->next;
	free(h);
}

#include "monty.h"
/**
 *f_add - adds two elements on top of stack
 *@head: head of stack
 *@counter: line number
 *Return: nothing
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h = NULL;
	int len = 0;

	h = *head;
	while (h != NULL)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		free_buf();
		exit(EXIT_FAILURE);
	}
	h = (*head)->next;
	h->n += (*head)->n;
	f_pop(head, counter);
}

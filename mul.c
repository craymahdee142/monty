#include "monty.h"
/**
 *f_mul - multiply two elements on top of stack
 *@head: head of stack
 *@counter: line number
 *Return: nothing
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h = NULL;
	int len = 0;

	h = *head;
	while (h != NULL)
	{
		h = h->next;
		len++;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		free_buf();
		exit(EXIT_FAILURE);
	}
	h = (*head)->next;
	h->n *= (*head)->n;
	f_pop(head, counter);
	}
}

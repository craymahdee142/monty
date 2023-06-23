#include "monty.h"
/**
 *f_swap - swap elements on top of stack
 *@head: head of stack
 *@counter: line number
 *Return: nothing
 */
void f_swap(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		free_buf();
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = (*head)->next;
	h->next = (*head)->next;
	h->prev = *head;
	(*head)->next = h;
	(*head)->prev = NULL;
}

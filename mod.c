#include "monty.h"
/**
 *f_mod - divide two elements on top of stack
 *@head: head of stack
 *@counter: line number
 *Return: nothing
 */
void f_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		free_buf();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		free_buf();
		exit(EXIT_FAILURE);
	}
	h = (*head)->next;
	h->n %= (*head)->n;
	f_pop(head, counter);/*_pop() removes the first node*/
}

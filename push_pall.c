#include "monty.h"

/**
 *f_push - function that add node to the stack
 *@head: stack head
 *@counter: int counter
 *Return: nothing
 */

void f_push(stack_t **head, unsigned int counter)
{
	int i, n;

	if (buf.args == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		free_buf();
		exit(EXIT_FAILURE);
	}
	for (i = 0; buf.args[i] != '\0'; i++)
	{
		if (!isdigit(buf.args[i]) && buf.args[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			free_buf();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(buf.args);

	if (buf.lifi == 1)
		add_dnodeint(head, n);
	else
		add_dnodeint_end(head, n);
}

/**
 *f_pall - prints stack element
 *@head: pointer head
 *@counter: line number
 *Return: nothing
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void) counter;

	h = *head;
	if (h == NULL)
		return;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

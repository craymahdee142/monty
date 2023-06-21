#include "monty.h"
/**
 *f_add - adds two elements on top of stack
 *@head: head of stack
 *@counter: line number
 *Return: nothing
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0;
	int temp;

	h = *head;
	while (h != NULL)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(buf.file);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

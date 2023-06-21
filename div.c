#include "monty.h"
/**
 *f_div - divide tow numbers from stack
 *@head: pointer head of stack
 *@counter: line number
 *Return: nothing
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h->next != NULL)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(buf.file);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(buf.file);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n / h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

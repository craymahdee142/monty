#include "monty.h"
/**
 *f_mod - computes rest of division
 *@head: pointer to head stack
 *@counter: line munber
 *Return: nothing
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h != NULL)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(buf.file);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(buf.file);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n % h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

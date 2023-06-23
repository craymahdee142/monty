#include "monty.h"

/**
 *f_pint - prints the top value
 *@head: head of stack
 *@counter: line number
 *Return: nothing
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		free_buf();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

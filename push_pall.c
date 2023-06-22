#include "monty.h"

/**
 *f_push - function that add node to the stack
 *@head: stack head
 *@counter: int counter
 *Return: nothing
 */
void f_push(stack_t **head, unsigned int counter)
{
	int i = 0, n;
	int res = 0;

	if (buf.args != NULL)
	{
		if (buf.args[0] == '-')
			i++;
		for (; buf.args[i] != '\0'; i++)
		{
			/* checks if char is not a digit */
			if (buf.args[i] > 57 || buf.args[i] < 48)
				res = 1; 
		}
		if (res == 1)
		{	
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(buf.file);
			free(buf.content);
			free_stack(*head);
			exit(EXIT_FAILURE); 
		}
		else
		{	
			n = atoi(buf.args);
                	if (buf.lifi == 0)
                        addnode(head, n);
                	else
                        addqueue(head, n);
		}
		
	}
	else 
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(buf.file);
		free(buf.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

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

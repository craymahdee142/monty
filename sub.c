#include "monty.h"
/**
 *f_sub - funtion that substract numbers
 *@head: head pointer of stack
 *@counter: line counetr
 *Return: nothing
 */
void f_sub(stack_t **head, unsigned int counter)
{
 	stack_t *temp;
	int result, i = 0;

	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can'sub, stack too short\n", counter);
		fclose(buf.file);
		free(buf.content);
		free_stack(*head); 
		exit(EXIT_FAILURE);
	}
	temp = *head;
	result = temp->next->n - temp->n;
	temp->next->n =  result;
	*head = temp->next;
	free(temp);
}

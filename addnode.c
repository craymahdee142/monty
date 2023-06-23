#include "monty.h"
/**
 *add_dnodeint - add node at the beginning
 *@head: first position of the linked list
 *@n: data to store
 *Return: doubly linked list
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_buf();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 *add_dnodeint_end - add node at the end
 *@head: first position of the linked list
 *@n: data to store
 *Return: doubly linked list
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *res;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_buf();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	res = *head;
	while (res->next)
		res = res->next;
	temp->next = res->next;
	temp->prev = res;
	res->next = temp;
	return (res->next);
}

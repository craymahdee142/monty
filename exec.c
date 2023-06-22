#include "monty.h"
/**
 *execute - execute opcode
 *@content: line content
 *@stack: head linked list
 *@counter: line numner
 *@file: ponits to empty monty file
 *Return: 0 (success)
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"div", f_div},
				{"add", f_add},
				{"mul", f_mul},
				{"sub", f_sub},
				{"mod", f_mod},
				{"nop", f_nop},
				{"swap", f_swap},
				{"pop", f_pop},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, "\n\t");
	if (op && op[0] == '#')
		return (0);
	buf.args = strtok(NULL, "\n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

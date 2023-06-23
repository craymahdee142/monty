#include "monty.h"
/**
 *get_opcodes - select correct opcode
 *@op: code passed
 *
 *Return: pointer to the func
 */
void (*get_opcodes(char *op))(stack_t **stack, unsigned int counter)
{
	instruction_t opt[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"queue", f_queue},
		{"stack", f_stack},
		{"add", f_add},
		{"sub", f_sub},
		{"nop", f_nop},
		{"mul", f_mul},
		{"div", f_div},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opt[i].opcode; i++)
	{
		if (_strcmp(opt[i].opcode, op) == 0)
			break;
	}
	return (opt[i].f);
}

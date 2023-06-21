#include "monty.h"
buf_t buf = {NULL, NULL, NULL, 0};
/**
 *main - Entry
 *@argc: num of arguments
 *@args: monty file
 *Return: 0 (success)
 */
int main(int argc, char *args[])
{
	FILE *file;
	char *content = NULL;
	stack_t *stack = NULL;
	size_t size = 0;
	ssize_t read_line = 1;
	unsigned int counter = 0;

	/* check number of argument passed*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*open a file specified in the command */
	file = fopen(args[1], "r");
	buf.file = file;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", args[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		buf.content = content; /* set content for potential error msg*/
		counter++;
		if (read_line > 0) /*check is line was successfully read*/
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

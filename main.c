#include "monty.h"
/**
 *main - Entry
 *@argc: num of arguments
 *@args: monty file
 *Return: 0 (success)
 */
int main(int argc, char *args[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, args);
	start_buf(fd);

	nlines = getline(&buf.content, &size, fd);

	while (nlines != -1)
	{
		lines[0] = _strtok(buf.content, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free_buf();
				exit(EXIT_FAILURE);
			}
			buf.args = _strtok(NULL, " \t\n");
			f(&buf.head, buf.counter);
		}
		nlines = getline(&buf.content, &size, fd);
		buf.counter++;
	}
	free_buf();
	return (0);
}

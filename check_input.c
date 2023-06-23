#include "monty.h"

buf_t buf;

/**
 *start_buf - initialised global var
 *@fd: file descriptor
 *Return: nothing
 */
void start_buf(FILE *fd)
{
	buf.lifi = 1;
	buf.counter = 1;
	buf.args = NULL;
	buf.head = NULL;
	buf.fd = fd;
	buf.content = NULL;
}

/**
 *free_buf - free global var
 *Return: nothing
 */
void free_buf(void)
{
	free_stack(buf.head);
	free(buf.content);
	fclose(buf.fd);
}

/**
 *check_input - checks if file exist and can be opened
 *@argc: argument count
 *@args: argument vector
 *Return: file struct
 */
FILE *check_input(int argc, char *args[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(args[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error:Can't open file %s\n", args[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

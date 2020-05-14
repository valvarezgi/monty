#include "monty.h"
holds hold = {NULL, NULL, NULL};
/**
 * main - main
 * @ac: argument counter
 * @av: arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int ac, char *av[])
{
	size_t length = 32;
	ssize_t filereader;
	unsigned int line_number = 0;
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	hold.file = fopen(av[1], "r");
	if (!hold.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((filereader = getline(&hold.buffer, &length, hold.file)) != EOF)
	{
		line_number++;
		tokenizer(hold.buffer, &stack, line_number);
	}
	free_list(stack);
	exit(EXIT_SUCCESS);
}

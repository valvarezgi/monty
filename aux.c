#include "monty.h"
/**
 * getops - get the opcode to use
 * @stack: stack to handle
 * @line_number: counter to lines
 * @function: op to find
 */

void getops(stack_t **stack, unsigned int line_number, char *function)
{
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		/* {"swap", _swap},*/
		/* {"add", _add},*/
		/* {"nop", _nop},*/
		{NULL, NULL}
	};
	int idx = 0;

	while (op[idx].opcode)
	{
		if (strcmp(op[idx].opcode, function) == 0)
		{
			op[idx].f(stack, line_number);
			break;
		}
		idx++;
	}

	if (!op[idx].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, function);
		free_list((*stack));
		exit(EXIT_FAILURE);
	}
}

/**
 * free_list - Function that frees lists
 * @stack : doubly linked list to free
 */

void free_list(stack_t *stack)
{
	stack_t *aux;

	while (stack != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
	fclose(hold.file);
	free(hold.buffer);
}

/**
 * tokenizer - split in tokens
 * @buffer: buffer
 * @stack: stack
 * @line_number: counter
 */

void tokenizer(char *buffer, stack_t **stack, unsigned int line_number)
{
	char *fun, *aux;

	fun = strtok(buffer, " \n\t");
	aux = strtok(NULL, " \n\t");
	hold.tokens = aux;

	if (fun && fun[0] != '#')
		getops(stack, line_number, fun);
}

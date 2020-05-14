#include "monty.h"
/**
 * push - push an element to the stack
 * @stack: stack
 * @line_number: counter
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode, *aux;
	int i, j = 1, number;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_list(newNode);
		exit(EXIT_FAILURE);
	}
	if (hold.tokens)
	{
		for (i = 0; hold.tokens[i] != '\0'; i++)
		{
			if (hold.tokens[i] >= 48 && hold.tokens[i] <= 57)
				j = 0;
			else
				j = 1; }
		if (j == 0)
			number = atoi(hold.tokens);
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			free_list((*stack));
			free(newNode);
			exit(EXIT_FAILURE); }
	}
	else
	{fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list((*stack));
		free(newNode);
		exit(EXIT_FAILURE); }
	newNode->n = number;
	newNode->next = *stack;
	newNode->prev = NULL;
	aux = *stack;
	if (*stack != NULL)
		aux->prev = newNode;
	*stack = newNode;
}

/**
 * pall -prints all the values
 * @stack: stack
 * @line_number: counter
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;
	(void)line_number;

	copy = *stack;
	for (; copy; copy = copy->next)
		printf("%d\n", copy->n);
}

/**
 * pint - print the value at the top
 * @stack: stack
 * @line_number: counter
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * pop - removes an element from the top of the stack
 * @stack: stack
 * @line_number: counter
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_list((*stack));
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(aux);
	if (*stack)
		(*stack)->prev = NULL;
}

#include "monty.h"
/**
 * add - adds
 * @stack: stack
 * @line_number: counter
 */

void add(stack_t **stack, unsigned int line_number)
{
    if(*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_list(*stack);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n = (*stack)->next->n + (*stack)->n;
    pop(stack, line_number);
}


/**
 * nop - nop
 * @stack: stack
 * @line_number: counter
 */

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

}
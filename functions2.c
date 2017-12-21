#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	if (list_len(*stack) < 2)	
	{
		printf("L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;	
	
	free_node(stack);
}


int numbers_only(const char *s)
{
	while (*s)
	{
		if (isdigit(*s++) == 0)
		return 0;
	}
	return 1;
}

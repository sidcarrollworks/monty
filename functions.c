#include "monty.h"

int data;

void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (isdigit(data))
	{
		printf("L<%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = data;
	new_node->prev = NULL;

	if (!(*stack))
		new_node->next = NULL;
	else
		new_node->next = *stack;

	*stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	tmp = *stack;
	if (!tmp)
	{
		printf("Stack is NULL\n");
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		printf("L<%d>: can't pint, stack empty\n", line_number);
	else
		printf("%d\n", (*stack)->n); 
}

/*
void pop(stack_t **stack, int line_number)
{

}
void swap(stack_t **stack, int line_number)
{

}

void nop(stack_t **stack, int line_number)
{
	data = 0;
}
*/

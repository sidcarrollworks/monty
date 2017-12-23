#include "monty.h"

int data;

void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (isdigit(data))
	{
		printf("L<%d: usage: push integer\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed");
		free_dlistint(*stack);
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
		free_dlistint(*stack);
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
	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n); 
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	if ((*stack)->next == NULL)
		*stack = NULL;

	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
	}
	
	free(tmp);
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;

	if (list_len(*stack) < 2)
	{
		printf("L%d: can't swap, stack too\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_SUCCESS);
	}

	tmp1 = (*stack)->next;

	(*stack)->next = tmp1->next;
	(*stack)->prev = tmp1;

	tmp1->next = (*stack);
	tmp1->prev = NULL;

	*stack = tmp1;
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

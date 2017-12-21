#include "monty.h"

size_t list_len(stack_t *stack)
{
	stack_t *tmp;
	size_t i = 0;

	tmp = stack;
	if (tmp == NULL)
		return (i);

	while (tmp != NULL)
		tmp = tmp->next, i++;
	return (i);
}

void free_node(stack_t **stack)
{
	stack_t *tmp;

	tmp = (*stack)->next;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	
	free(tmp);
}

int int_check(char *data_n)
{
	int i = 0;

	if (!data_n)
		return (0);
	while (data_n[i])
	{
		if (isdigit(data_n[i]) == 0 && data_n[i] != '-')
			return (0);
		else
			i++;
	}
	return (1);
}


/**
 * free_dlistint - free list
 * @head: head of list
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	if (!head)
		return;

	while (head->next)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	free(head);
}

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

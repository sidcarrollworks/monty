#include "monty.h"
/*
void add(stack_t **stack, int line_number)
{
}
*/

int numbers_only(const char *s)
{
	while (*s)
	{
		if (isdigit(*s++) == 0)
		return 0;
	}
	return 1;
}

#include "monty.h"

int data;
/**
 *
 */
int main(int argc, char *argv[])
{
	FILE *file;
	unsigned int lc = 0;
	char *op_token = NULL;
	char *str = argv[1];
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	int i = 0;
	char *num = NULL;

	instruction_t codez[] = {
		{"push", push_stack},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"#", nop},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* printf("check 1\n"; */

	file = fopen(str, "r");
	if (!file)
	{
		printf("ERROR: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}

	/* printf("check 2\n"); */

	while (getline(&line, &len, file) != -1)
	{
		/* printf("check 3\n"); */
		lc++;
		op_token = strtok(line, " \t\n");
		if (op_token)
		{
			i = 0;
			while (codez[i].opcode)
			{
				/* printf("check 4\n"); */
				if (strcmp(codez[i].opcode, op_token) == 0)
				{
					if (strcmp("push", op_token) == 0)
					{
						num = strtok(NULL, " \t\n");
						data = atoi(num);
					}
					break;
				}			
				i++;
			}
			if (codez[i].opcode == NULL)
			{
				printf("L<%d>: unknown instruction <%s>\n", lc, op_token);
				exit(EXIT_FAILURE);
			}
		/* printf("check 5\n"); */
			codez[i].f(&stack, lc);
		/* printf("check 5 and a half::::::: %d\n", stack->n); */
		}
	}
	/* printf("check 6\n"); */
	fclose(file);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}

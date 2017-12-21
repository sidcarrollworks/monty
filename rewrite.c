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

	file = fopen(str, "r");
	if (!file)
	{
		printf("ERROR: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		lc++;
		op_token = strtok(line, " \t\n");
		if (op_token)
		{
			i = 0;
			while (codez[i].opcode)
			{
				if (strcmp(codez[i].opcode, op_token) == 0)
				{
					if (strcmp("push", op_token) == 0)
					{
						num = strtok(NULL, " \r\t");
						if (int_check(num))
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
			codez[i].f(&stack, lc);
		}
	}
	fclose(file);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}

#include "shell.h"

/**
 * read_command - func that read the input cmd
 *
 * Return: string
 */

char *read_command(void)
{
	char *string = NULL;
	size_t size = 0;
	int input = getline(&string, &size, stdin);

	if (input == -1)
	{
		free(string);
		exit(0);
	}

	if (string[input - 1] == '\n')
	{
		string[input - 1] = '\0';
	}
	return (string);
}

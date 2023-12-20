#include "shell.h"
/**
 * read_command - function that read the givven command
 * Return: the command
 */
char *read_command(void)
{
	char *str = NULL;
	size_t siz = 0;
	ssize_t input = getline(&str, &siz, stdin);

	if (input == -1)
	{
		perror("Error reading input\n");
		free(str);
		exit(EXIT_FAILURE);
	}
	if (str[input - 1] == '\n')
	{
		str[input - 1] = '\0';
	}
	else
	{
		char *temp = realloc(str, input + 1);

		if (temp == NULL)
		{
			perror("Error reallocating memory\n");
			free(str);
			exit(EXIT_FAILURE);
		}
		str = temp;
		str[input - 1] = '\0';
		input++;
	}
	return (str);
}

#include "shell.h"
/**
 * split_command - function that split input into
 * many tokens
 * @input: the command entred to be splited
 * Return: array of comands
 */
char **split_command(char *input)
{
	char *tok;
	char **tokens = NULL;
	int i = 0;
	int max_tokens = INITIAL_TOKENS;

	tokens = malloc(max_tokens * sizeof(char *));
	if (tokens == NULL)
	{
		perror("malloc_fails");
		exit(EXIT_FAILURE);
	}
	tok = strtok(input, " \t\n");
	while (tok != NULL)
	{
		tokens[i] = strdup(tok);
		if (tokens[i] == NULL)
		{
			perror("strdup_fails");
			while (i > 0)
			{
				free(tokens[--i]);
			}
			free(tokens);
			free(input);
			exit(EXIT_FAILURE);
		}
		i++;
		tok = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}


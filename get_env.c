#include "shell.h"
/**
 * get_env - function the get the env
 * @input_cmd: the command
 * Return: the env
 */
char *get_env(char *input_cmd)
{
	int i, size;

	size = strlen(input_cmd);
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], input_cmd, size) == 0)
			return (environ[i] + size + 1);
	}
	return (NULL);
}

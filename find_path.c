#include "shell.h"
/**
 * find_path - function that find the path
 * @input_cmd: the inputede command
 * Return: the path to be excuted
 */
char *find_path(char *input_cmd)
{
	struct stat st;
	char *path = get_env("PATH");
	char *full_path = strdup(path);
	char *token = strtok(full_path, ":");
	char full_cmd[1024];

	while (token)
	{

		strcpy(full_cmd, token);
		strcat(full_cmd, "/");
		strcat(full_cmd, input_cmd);

		if (stat(full_cmd, &st) == 0)
		{
		free(full_path);
		return (strdup(full_cmd));
		}
		token = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}

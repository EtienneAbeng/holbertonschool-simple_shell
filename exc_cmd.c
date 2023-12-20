#include "shell.h"
/**
 * execute_command - function that excute command
 * @arr_cmd: the array of cmmands
 * Return: 1
 */
int execute_command(char **arr_cmd)
{
	char *cmd = arr_cmd[0];
	char *full_path = NULL;
	pid_t _pid;
	int status;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		full_path = cmd;
	}
	else
	{
		full_path = find_path(cmd);
	}
	if (full_path == NULL)
	{
		perror("Command not found");
		return (1);
	}
	_pid = fork();
	if (_pid == -1)
	{
		perror("Error: fork");
		exit(EXIT_FAILURE);
	}
	if (_pid == 0)
	{
		execve(full_path, arr_cmd, environ);
		if (full_path != cmd)
			perror("Error: execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	if (full_path != cmd)
	{
		free(full_path);
	}
	return (1);
}

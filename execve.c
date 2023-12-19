#include "shell.h"
/**
 * execute_command - Execute a command using execve
 * @command: The command to be executed
 * This function forks a new process, allocates memory for the array
 * of arguments, and then executes the command using execve.
 */
void execute_command(char *command)
{
	pid_t pid;
	char **args;

	pid = fork_process();

	if (pid == 0)
	{
		/* Child process and memory allocation for the array of arguments */
		args = (char **)malloc(sizeof(char *) * 2);
		if (args == NULL)
		{
			perror("Memory allocation failed");
			free(command);
			exit(EXIT_FAILURE);
		}

		/* Copy the command into the array of arguments */
		args[0] = command;
		args[1] = NULL;
		execve(command, args, NULL);

		/* In case of execution failure */
		perror("hsh");
		free(command);
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		wait(NULL);

		/*display_prompt*/
		display_prompt();
	}
	free(command);
}

#include "shell.h"
/**
 * fork_process - Create a new process using fork
 *
 * This function creates a new process using fork and returns
 * the process ID. It also handles errors if the fork fails.
 *
 * Return: The process ID (PID) of the new process.
 */

pid_t fork_process(void)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

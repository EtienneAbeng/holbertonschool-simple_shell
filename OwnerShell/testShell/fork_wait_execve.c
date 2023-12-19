#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Create 5 child processes,each child executes the "ls -l /tmp" command
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t son_pid;
	int status;

	/*Create 5 son processes*/
	int i;

	for (i = 0; i < 5; i++)
	{
		son_pid = fork();

		/*Check for fork errors*/
		if (son_pid == -1)
		{
			printf("Error fork");
			return (1);
		}

		/*Code for the son process*/
		if (son_pid == 0)
		{
		/*Son process code and command to execute the process*/
			char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

			/*Execute the command using execve*/
			if (execve(argv[0], argv, NULL) == -1)
			{
				printf("Error");
				exit(1);
			}
			else
			{
				/*Wait for the son process to finish*/
				wait(&status);

				/*Print information about the exited son process*/
				printf("process of son %d exited with status %d\n", son_pid, WEXITSTATUS(status));
			}
		}
	}
	return (0);
}

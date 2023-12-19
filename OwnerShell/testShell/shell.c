#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - super simple shell
 *
 * @pid & ppid: A process is an instance of an executing program,
 *  that has a unique process ID
 * @execve: The system call execve allows a process to execute another programm 
 * @fork: The system call fork creates a new child process,
 * almost identical to the parent
 * @wait: The wait system call suspends execution of the calling process 
 * until one of its children terminates.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer = NULL;
	size_t command_size = 0;
	while (1)
	{
		/*Display the prompt*/
		printf("#$");

		/*Allocation to read the command of user with getline*/
		ssize_t read_getline = getline(&buffer, &command_size, stdin);

		if (read_getline == -1)
		{
			printf("Error command");
			exit(1);
		}

		/*To creat a son process*/

		pid_t son_pid = fork();

		if (son_pid == -1)
		{
			printf ("Error son process for the creation");
			exit(1);
		}

		if (son_pid == 0)
		{
		/*Split the command to get the programm name and argument*/
			char *token = strtok(buffer, " ");
			char **args = malloc(sizeof(char *) * 2);

			if(args == NULL)
			{
				printf("Memory allocation failled");
				exit (1);
			}

			args[0] = token;
			args[1] = NULL;

			/*Execute command enter for the user*/
			if (execve(token, args, NULL) == EOF)
			{
			printf("Error executing command, please retry");
			exit(1);
			}
		} 
		else
		{
		/*Code executed by process and wait the son process to finish*/
			int status;
			waitpid(son_pid, &status, 0);

			if (WIFEXITED(status))
			{
				printf("Son process exited with status %d\n", WEXITSTATUS(status));
			}
			else
			{
				printf("Son  process exited abnormally\n");
			}
		}
	}
	free(buffer);
	return (0);
}

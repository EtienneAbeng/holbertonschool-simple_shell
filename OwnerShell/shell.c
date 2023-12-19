#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	char *buffer = NULL;
	size_t buf_size = 2023;
	ssize_t read_size;
	pid_t pid;
	while(1)
	{
	/* Allocation a buffer to store the command entered by the user*/
		buffer = (char *)malloc(buf_size);
		if (buffer == NULL)
		{
			perror("Memory allocation failed");
			return (EXIT_FAILURE);
		}

		/*Display a command prompt*/
		printf("Myshell > ");

		/*Read the command from stdin (keyboard)*/
	       	read_size = getline(&buffer, &buf_size, stdin);

		/*Handle end of file with Ctrl + D*/
		if (read_size == -1)
		{
		free(buffer);
		exit(EXIT_SUCCESS);
		}

		/*Execute the commande using execve*/

		pid = fork();

		if (pid == -1)
		{
			perror("fork error");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
		/*child process and memory allocation for the array of argument*/
			char **args = (char**) malloc(sizeof(char*) * 2);
			if (args == NULL)
			{
				perror ("Memory allocation failled");
				free(buffer);
				exit(EXIT_FAILURE);
			}

			/*Copy the command into the array of arguments*/
			args[0] = buffer;
			args[1] = NULL;

			execve(buffer, args, NULL);

			/*In case of execution failure*/

			perror("Execution error");
			free(buffer);
			free(args);
			exit(EXIT_FAILURE);
		}
		else
		{
		/*Parent process*/
			wait(NULL);
		}
		/*Free the memory allocated for the command*/
		free(buffer);
	}
	return (0);
}

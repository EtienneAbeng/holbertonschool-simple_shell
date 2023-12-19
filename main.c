#include "shell.h"
/**
 * main - Entry point for the simple shell program
 *
 * This function contains the main logic of the simple shell.
 * It displays the prompt, reads the user's command, and executes it.
 * The process is repeated in an infinite loop until the user exits.
 */

int main(void)
{
	char *command = NULL;
	size_t buf_size = BUF_SIZE;
	ssize_t read_size;

	while(1)
	{
	 /* Allocation a buffer to store the command entered by the user */
		display_prompt();
		command = (char*)malloc(buf_size);
		if (command == NULL)
		{
			perror("memory allocation failed");
			exit(EXIT_FAILURE);
		}

	/*Read the command from stdin (keyboard)*/
	read_size = getline(&command, &buf_size, stdin);

	/*handle end of the file with Ctrl + D*/
	if (read_size == -1)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	/*Execute the command using exercve*/
		execute_command(command);
	}
}

#include "shell.h"
/**
 * main - main program
 * Return: 0 if secusees
 */
int main(void) 
{
	char **array_command;
	char *command;
	int builtin = 0;
	int i;
	int inter_mode = isatty(STDIN_FILENO);
	while (1) {
		if (inteir_mode)
		{
			buffer();
		}
		command = read_command();
        if (command == NULL)
	{
		if (!inter_mode) 
		{
			break;
		}
		continue;
	}	
	array_command = split_command(command);
	if (array_command != NULL && array_command[0] != NULL)
	{
		if (strcmp(array_command[0], "exit") == 0)
		{
			exit_shell();
			builtin = 1;
		} else if (strcmp(array_command[0], "env") == 0)
		{
			print_env();
			builtin = 1;
		}
	}	
	if (!builtin && array_command != NULL)
	{
		execute_command(array_command);
		for (i = 0; array_command[i] != NULL; ++i) 
		{
			free(array_command[i]);
		}
		free(array_command);
	}
	free(command);
	builtin = 0;
	}
	return 0;
}
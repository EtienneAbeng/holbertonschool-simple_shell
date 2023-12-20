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
	int inter_mode = isatty(STDIN_FILENO);

	while (1)
	{
		if (inter_mode)
			buffer();

		command = read_command();
		if (!command)
		{
			if (!inter_mode)
				break;
			continue;
		}

		array_command = split_command(command);
		if (array_command && array_command[0])
		{
			if (strcmp(array_command[0], "exit") == 0)
			{
				builtin = 1;
				exit_shell();
			}
			else if (strcmp(array_command[0], "env") == 0)
			{
				builtin = 1;
				print_env();
			}
		}

		if (!builtin && array_command)
			execute_command(array_command);

		free(command);
		free(array_command);
		builtin = 0;
	}

	return (0);
}

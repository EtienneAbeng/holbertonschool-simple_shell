#include "shell.h"
/**
 * main - main program
 * Return: 0 if secusees
 */
int main(void)
{
	char **arrayofcomand;
	char *command;
	int isbuiltin = 0;
	int i = 0;
	int interactive = isatty(STDIN_FILENO);

	builtin_t builtins[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};

	while (1)
	{
		if (interactive)
		{
			buffer();
		}

		command = read_command();
		if (command == NULL)
		{
			if (!interactive)
			{
				break;
			}
			continue;
		}

		arrayofcomand = split_command(command);

		i = 0;
		while (builtins[i].cmd != NULL)
		{
			if (strcmp(builtins[i].cmd, arrayofcomand[0]) == 0)
			{
				isbuiltin = 1;
				builtins[i].func();
				free(command);
				free(arrayofcomand);
				break;
			}
			i++;
		}
		if (!isbuiltin)
		{
			if (arrayofcomand != NULL)
			{
				execute_command(arrayofcomand);
			}
			free(command);
			free(arrayofcomand);
		}
		isbuiltin = 0;
	}
	return (0);
}

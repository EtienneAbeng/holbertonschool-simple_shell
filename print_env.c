#include "shell.h"
/**
 * print_env - function that prints the env
 * Return: the envirments printed
 */
int print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0)
}

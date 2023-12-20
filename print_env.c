#include "shell.h"
/**
 * print_env - function that prints the env
 * Return: the envirments printed
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

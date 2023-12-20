#include "shell.h"
/**
 * print_env - function that prints the env
 * Return: the envirments printed
 */
void print_env(void)
{
	int i = 0;

	printf("Printing environment variables...\n");
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

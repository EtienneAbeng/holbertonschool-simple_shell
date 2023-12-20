#include "shell.h"
/**
 * buffer - function that print the buffer
 * at the begining of the line
 * Return - nothing
 */
void buffer(void)
{
	const char *prompt = "#cisfun$ ";
	size_t prompt_length = strlen(prompt);

	write(STDOUT_FILENO, prompt, prompt_length);
}

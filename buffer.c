#include "shell.h"
void buffer() 
{const char *prompt = "shell >>";
	size_t prompt_length = strlen(prompt);
	write(STDOUT_FILENO, prompt, prompt_length);
}

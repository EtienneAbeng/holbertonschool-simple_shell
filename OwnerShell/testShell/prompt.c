#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *buffer = NULL;
	size_t buf_size = 2024;

	/*Allocation dynamic of buffer to stock the command of user */

	buffer = calloc(sizeof(char), buf_size);
	if (buffer == NULL)
	{
		printf("Allocation memory is failled");
		return(1); /* To leave the program */
	}

	/* Writing a prompt in the stand out (stdout) */
	write(1, "$>", 3);

	/*Loop playback from stand in (keyboard) until user */
	while (getline(&buffer, &buf_size, stdin) != EOF)
	{
	/* Print the command enter for the user */
	/*printf(" %s",  buffer); Voir si cela pose problème*/

	/* Rewrite the prompt for the next entry */
	write(1, "$>", 3);
	}

	free(buffer);
	return (0);

	
}

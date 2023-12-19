#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	char *buffer = NULL;
	size_t buffer_size = 2023;
	
	/*Allocation memory to stock the user's command*/
	buffer = calloc(sizeof(char), buffer_size);
	if (buffer == NULL)
	{
		perror("Allocation memory failled");
		return (EXIT_FAILURE);
	}

	/*Writing of prompt*/
	write(1, "$MyShell> ", 10);

	/*Reading STDIN in loop*/

	while (getline(&buffer, &buffer_size, stdin) > 0)
	{
		printf(" %s", buffer);
		/*Traitement of the command*/
	char **tokens = isolateCommand(buffer);

	/* Utilize tokens as needed */
		executeCommand(tokens);
	/* Free each token individually */
        for (size_t i = 0; tokens[i] != NULL; ++i) 
	{
            printf("%s\n", tokens[i]);
            free(tokens[i]);
        }

	/*Free the array of token*/
	free(tokens);

		write(1, "$MyShell> ", 10);
	}

	free(buffer);
	return (0);
}

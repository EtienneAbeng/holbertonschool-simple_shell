#include "main.h"

char** isolateCommand(char *buffer) 
{
	/*Use strtok to split the command into words (tokens)*/
	char *token = strtok(buffer, " ");
	size_t token_count = 0;
	
	/*Allocation memories array to stock the tokens*/
	char **tab_Token = NULL;
	
	while (token != NULL) 
	{
	/*Reallocation memories to stock a new token*/
		tab_Token = realloc(tab_Token, (token_count + 1) * sizeof(char *));
		if (tab_Token == NULL) 
		{
			perror("Allocation Memories failed");
			exit(EXIT_FAILURE);
		}
		
		/*To allocate memory for the current token and copy it*/
		tab_Token[token_count] = strdup(token);
		if (tab_Token[token_count] == NULL) 
		{
			perror("Allocation Memory for Token failed");
			exit(EXIT_FAILURE);
		}
		
		/*To increment the next token*/
		++token_count;
		/*To get the next token*/
		token = strtok(NULL, " ");
	}
	
	/* Reallocate to add a NULL pointer to mark the end of the array */
	tab_Token = realloc(tab_Token, (token_count + 1) * sizeof(char *));
	if (tab_Token == NULL) 
	{
		perror("Allocation Memories failed");
		exit(EXIT_FAILURE);
	}
	
	/* Set the last element to NULL to mark the end of the array */
	tab_Token[token_count] = NULL;
	
	/* Return the array of tokens */
	return (tab_Token);
}

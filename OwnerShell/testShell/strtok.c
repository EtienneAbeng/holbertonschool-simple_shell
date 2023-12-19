#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[] = "My Simple Shell";
	char *token;

	printf (" %s split\n", str);

	/*To separate the string according the space*/
	token = strtok (str," ");

	/*To print the cutting result*/
	while (token != NULL)
	{
		printf ("%s \n", token);
		token = strtok (NULL, " ,");
	}	
	return (0);
}

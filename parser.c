#include "shell.h"
/**
 * parser - devides arguments form commands
 * @input: user's input
 * @tokens: the marker
 * Return: 0 if success
 */
int parser(char *input, char **tokens)
{
	int counter = 0;
	char *token = strtok(input, " ");

	while (token != NULL)
	{
		if (counter >= 20)
		{
			fprintf(stderr, "Too many tokens.\n");
			exit(EXIT_FAILURE);
		}
		tokens[counter] = strdup(token);
		counter++;

		token = strtok(NULL, " ");
	}
	return (0);
}

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
		if (token_count >= 20) 
		{
			fprintf(stderr, "Too many tokens.\n");
			exit(EXIT_FAILURE);
		}
		tokens[token_count] = strdup(token);
		token_count++;

		token = strtok(NULL, " ");
	}
	return (0);
}

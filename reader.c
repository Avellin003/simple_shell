#include "shell.h"
/**
 * reader - function that gets input
 * @input: address to store the input
 * @counter: user defined input limiter
 */
void reader(char *input, size_t counter)
{
	size_t end_searcher;

	fgets(input, counter, stdin);/*gets the input from keyboar check main.c*/
	end_searcher = strlen(input);
	if (end_searcher > 0 && input[end_searcher - 1] == '\n')
	{
		input[end_searcher - 1] = '\0';
	} /*defines "Enter" as end of input*/
}

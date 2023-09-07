#include "shell.h"
/**
 * main - runner function
 * Return: 0 if sucess and exits upon "exit"input
 */
int main(void)
{
	char input[100]; /*input maximum number*/

	while (1)
	{
		prompt();
		reader(input, sizeof(input));/*tracks the size into counter*/
		if (strcmp(input, "exit") == 0)/*checks if the input is exit*/
		{
			break;/*terminates if it's "exit"*/
		}
	}
	return (0);
}

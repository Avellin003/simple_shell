#include "shell.h"
/**
 * main - the running function
 * Return: void
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive();
	}
	else
		non_interactive();
	return (0);
}

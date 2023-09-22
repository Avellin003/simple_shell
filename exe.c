#include <stdio.h>
#include "shell.h"
/**
 * exe - execute executable commands
 * @command: the name of the command to execute
 * @args: the holder of the commad splits
 * Return: 0 if success else -1
 */
int exe(const char *command, char *args[])
{
	if (execvp(command, args) == -1)
	{
		return (-1);
	}

	return (0);
}

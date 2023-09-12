#include "shell.h"
/**
 * my_cd - changes the current directory
 * @path: arguments that provides dive in path
 * Return: 0 if sucess else 1
 */
int my_cd(const char *path)
{
	if (chdir(path) != 0)
	{
		perror("chdir");
		return 1;
	}
	return 0;
}
/**
 * my_exit - exits the shell
 * Returns : 0 if success
 */
void my_exit(void)
{
	exit(0);
}

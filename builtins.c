#include "shell.h"
/**
 * my_cd - changes the current directory
 * @path: arguments that provides dive in path
 * Return: 0 if sucess else 1
 * wd: gets my curerrent directory
 */
int my_cd(const char *path, const char *wd)
{
	char new[120];

if (snprintf(new, sizeof(new), "%s/%s", wd, path) >= sizeof(new))
{
	fprintf(stderr, "too long\n");
	return (1);
}

	if (chdir(path) != 0)
	{
		perror("chdir");
		return (1);
	}
	return (0);
}
/**
 * my_exit - exits the shell
 * Returns : 0 if success
 */
void my_exit(void)
{
	exit(0);
}

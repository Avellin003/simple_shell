#include "shell.h"
/**
 * exe - execute executable commands
 * @command: the name of the command to execute
 * Return: 0 if success else -1
 */
int exe(const char *command)
{
	char *path = "/usr/bin/"; /*defines the path the commands are*/
	char full_path[256]; /*max path*/

	snprintf(full_path, sizeof(full_path), "%s%s", path, command);
	/*checks if the command exists if not returns -1*/
	if (access(full_path, X_OK) != 0)
	{
		fprintf(stderr, "Command not found: %s\n", command);
		return (-1);
	}
	/*execute the command*/
	if (system(full_path) != 0)
	{
		fprintf(stderr, "Failed to execute command: %s\n", command);
		return (-1);
	}
	return (0);
}

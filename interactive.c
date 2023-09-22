#include "shell.h"
/**
 * interactive - interactive part of the shell
 * Return: 0 if sucess and exits upon "exit"input
 */
int interactive(void) /*it was interactive before*/
{
	char input[1024]; /*input maximum number*/

	while (1)
	{
		prompt();
		reader(input, sizeof(input));/*tracks the size into counter*/
		if (strcmp(input, "exit") == 0)
			my_exit();
		else if (strcmp(input, "cd") == 0)
		{
			if (my_cd(getcwd(NULL, 0), input) != 0)
				fprintf(stderr, "can't change directory\n");
		}
		else if (strcmp(input, "ls") == 0 || strcmp(input, " ") == 0
				|| strcmp(input, "help") == 0)
		{
			pid_t pid = fork();

			if (pid < 0)
				perror("fork");
			else if (pid == 0)
			{
				exe(input, NULL);
				/*exit(0);*/
				my_exit();
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
			}
		}
		else if (strcmp(input, "env") == 0)
		{
			exe(input, NULL);
			/*exit(0);*/
			my_exit();
		}
	}
	return (0);
}

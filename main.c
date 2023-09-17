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
			my_exit();/*terminates if it's "exit"*/
		}
		else if (strcmp(input, "cd") == 0)
		{
			if (my_cd(getcwd(NULL, 0), input) != 0)
			{
				fprintf(stderr, "can't change directory\n");
			}
		}
		else if (strcmp(input, "ls") == 0 || strcmp(input, " ") == 0 || strcmp(input, "help") == 0)
		{
			pid_t pid = fork();

			if (pid < 0)
				perror("fork");
			/*executes help or ls*/
			else if (pid == 0)
			{
				exe(input);
				exit(0);
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
			}
		}
		else if (strcmp(input, "env") == 0)
		{
			exe(input);
			exit(0);
		}
		/*else
		{
			write(stderr, "command not found\n", 20);
		}*/
	}
	return (0);
}

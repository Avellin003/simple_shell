#include "shell.h"
#define MAX_INPUT_SIZE 100
#define MAX_ARRAY_SIZE 100

/**
 * acccess_input - handles fork
 *
 * Return: array of result
 */
void access_input(char *command, char *array[], char *env_vars[])
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error ");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (access(command, F_OK) == 0)
		{
			execve(command, array, env_vars);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			write(STDERR_FILENO, "./shell: No such file or directory\n", 35);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
/**
 * shell_prompt - display and execute prompt
 *
 * Return: Success 0.
 */
int shell_prompt(void)
{
	char *token;
	char input[MAX_INPUT_SIZE];
	char *array[MAX_ARRAY_SIZE];
	int i;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("fget");
				exit(EXIT_FAILURE);
			}
		}
		input[strlen(input) - 1] = '\0';
		token = strtok(input, " ");
		i = 0;
		while (token != NULL && i < MAX_ARRAY_SIZE - 1)
		{
			array[i++] = token;
			token = strtok(NULL, " ");
		}
		array[i] = NULL;
		access_input(array[0], array, NULL);
	}
	return (0);
}


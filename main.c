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
	}
	pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Child process
            // Execute the user input as a shell command
            int result = execlp("/bin/sh", "/bin/sh", "-c", input, NULL);

            if (result == -1) {
                perror("Command execution failed");
                exit(EXIT_FAILURE);
            }

            // This code will not be reached if the exec succeeds
            exit(EXIT_SUCCESS);
        } else { // Parent process
            // Wait for the child process to complete
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("Wait failed");
                exit(EXIT_FAILURE);
            }
        }
	return (0);
	}

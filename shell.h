#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void reader(char *input, size_t counter);
void prompt(void);
int _putchar(char c);
void access_input(char *command, char *array[], char *env_vars[]);
int main(void);
#endif

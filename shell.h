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
int my_cd(const char *,const char *);
int exe(const char *);
void executer(char *);
void my_exit(void);
void reader(char *, size_t);
void prompt(void);
int _putchar(char );
void access_input(char *, char *, char *);
int shell_prompt(void);
#endif

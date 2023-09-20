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
/*interactive.c*/
int interactive(void);
/*builtins.c*/
void my_exit(void);
int my_cd(const char *, const char *);
int exe(const char *);
void executer(char *);
/*reader.c*/
void reader(char *, size_t);
/*prompt.c*/
void prompt(void);
/*_putchar.c*/
int _putchar(char *);
/*void access_input(char *, char *, char *);*/
int non_interactive(void);
int print_env(char **argv, char **env);
#endif

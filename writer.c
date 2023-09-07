#include "shell.h"
/**
 * writer - function that writes to stdout
 * @input: argument holding the input command
 * Return: nothing
 */
void writer(const char *input)
{
    write(1,input,strlen(input));
}
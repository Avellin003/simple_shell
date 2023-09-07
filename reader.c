#include "shell.h"
/**
 * get_input - a function that reads the inputs
 * @argv: argument vector
 * @argc: argument count
 * Return: nothing
*/
void get_input(int argc, char *argv, char input[120])
{
    int counter;
    int i = 0;

    counter = strlen(argc);
    if(argc == 1)
    {
        writer(" ");
    }
    while(argc > 1)
    {
        strcpy(argv[i], input);
        writer(input);
        i++;
    }
}
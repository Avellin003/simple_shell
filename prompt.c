#include "shell.h"
/**
 * prompt - a function that displays prompt
 * fflush: clears the  buffer to allow new inputs
 * returns: nothing
 */
void prompt(void)
{
	putchar('$');
	putchar(' ');
	fflush(stdout); /*fflush allows other inputs to be printed */
}

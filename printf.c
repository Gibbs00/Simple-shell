#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>



/**
* shell_print - writes the character to stdout
* @my_print_fun: The character to print
* Return: On success 1.
*/


void shell_printf(const char *my_print_fun)
{
	write(STDOUT_FILENO, my_print_fun, strlen(my_print_fun));
}

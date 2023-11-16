#include "shell.h"


/**
* shell_print - writes the character to stdout
* @message: The character to print
* Return: On success 1.
* On error, -1 is returned and errno set appropriately
*/


void shell_print(const char *my_print_fun)
{
	write(STDOUT_FILENO, my_print_fun, strlen(my_print_fun));
}

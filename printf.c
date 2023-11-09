#include "shell.h"


void shell`_print(const char *message)
{
	write(STDOUT_FILENO, mesaage, strlen(message));
}

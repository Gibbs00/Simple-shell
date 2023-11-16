#include "shell.h"

void get_command(char *command, size_t size)
{
    if (fgets(command, size, stdin) == NULL)
    {
        if (feof(stdin))
	{
            shell_print("\n");
            exit(EXIT_SUCCESS);
        }
	else
	{
            shell_printf("Error while reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    command[strcspn(command, "\n")] = '\0'; // Remove newline
}

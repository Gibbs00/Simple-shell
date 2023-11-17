#include "shell.h"

/*
 * get_command - Read a command from the standard input
 * @command: Buffer to store the entered command
 * @size: Size of the buffer
 *
 * This function uses fgets to read a command from the standard input into
 * the provided buffer. It handles potential errors during input, such as
 * reaching the end of the file or encountering an error while reading.
 * If the input is successful, it removes the newline character from the
 * command string.
 * Returns: no return
 */

void get_command(char *command, size_t size)
{
    if (fgets(command, size, stdin) == NULL)
    {
        if (feof(stdin))
	{
            shell_printf("\n");
            exit(EXIT_SUCCESS);
        }
	else
	{
            shell_printf("Error while reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    command[strcspn(command, "\n")] = '\0';
}

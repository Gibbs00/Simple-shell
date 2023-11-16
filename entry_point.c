#include "shell.h"

/**
 * main - Entry point for the shell program
 * This function initializes a shell and enters into a loop where it continuously
 * prompts the user, reads a command, and executes it until the program is terminated.
 * Return: Always 0.
 */

int main(void)
{
	char command[128];

	while (true) 
	{
		shell_show_prompt();
		read_command(command, sizeof(command));
		exe_command(command);
	}
	return (0);
}

#include "shell.h"

/**
 * execute_env - Displays current environment variables
 *
 * This function executes the 'env' command to list and print the current
 * environment variables to the standard output. The @arguments parameter is
 * not used in this function.
 *
 * @arguments: An array of arguments (not utilized in this function).
 */

void execute_env(char **arguments)
{
	char **envmt = environ;
	(void)arguments;

	for (; *envmt; envmt++)
	{
		write(STDOUT_FILENO, *envmt, strlen(*envmt));
		write(STDOUT_FILENO, "\n", 1);
	}
}


/**
 * execute_setenv - Set or update an environment
 * variable using 'setenv' command.
 *
 * This function takes arguments
 * where args[0] is the variable name and args[1] is
 * the associated value.
 *
 * @args: Array with the variable name (args[0]) and its value (args[1]).
 */

void execute_setenv(char **args)
{
	if (args == NULL || args[0] == NULL || args[1] == NULL)
	{
		return;
	}
	if (setenv(args[0], args[1], 1) == -1)
	{
		return;
	}
}

/**
 * execute_unsetenv - Unsets or removes an environment
 * variable using 'unsetenv' command.
 *
 * Takes an array of arguments
 * with args[0] as the variable name to be unset.
 * Uses 'unsetenv' system call to remove the specified environment variable.
 *
 * @args: Array of arguments with the variable name to be unset (args[0]).
 */

void execute_unsetenv(char **args)
{
	if (args == NULL || args[0] == NULL)
	{
		return;
	}
	if (unsetenv(args[0]) == -1)
	{
		return;
	}
}


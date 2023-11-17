#include "shell.h"

/**
 * execute_custom_builtins - Execute built-in commands with arguments.
 * @command: The command.
 * @args: The command arguments.
 * BuiltinCommand - Represents a built-in command.
 * Return: 1 if the command is a built-in and is executed, 0 otherwise.
 */
int execute_custom_builtins(const char *command, char **args)
{
	int k = 0;
	 BuiltinCommand
	{
		const char *command_name;
		void (*execute)(char **);
	};
	 BuiltinCommand builtin_commds[] = {
		{"env", execute_env},
		{"setenv", execute_setenv},
		{"unsetenv", execute_unsetenv},
		{NULL, NULL}
	};
	while (builtin_commds[k].command_name != NULL)
	{
		if (strcmp(builtin_commds[k].command_name, command) == 0)
		{
			builtin_commds[k].execute(args);
			return (1);
		}
		k++;
	}
	return (0);
}

/**
 * my_builtins - Checks if a command is a built-in.
 * @command: The command being checked.
 *
 * Description: This function checks if the given command is a built-in
 * by searching for it in the list of available built-in commands.
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int my_builtins(const char *command)
{
	const char *builtins[] = {
		"env",
		"exit",
		"cd",
		"alias",
		"setenv",
		"unsetenv",
		NULL
	};
	int k = 0;

	for (k = 0; builtins[k] != NULL; k++)
	{
		if (strcmp(command, builtins[k]) == 0)
		{
			return (1);
		}
	}
	return (0);
}


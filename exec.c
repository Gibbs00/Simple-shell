#include "shell.h"

/**
 * build_command_arguments - Construct an array of command arguments
 *
 * @command: The main command
 * @arguments: The arguments to the command
 * Return: An array of command and arguments
 */
char **build_command_arguments(char *command, char **arguments)
{
	int token_count = 0;
	char **ptr_array;
	int k = 0;

	if (arguments == NULL || arguments[0] == NULL)
	{
		ptr_array = malloc(sizeof(char *) * 2);
		if (ptr_array == NULL)
		{
			perror("custom_shell");
			exit(EXIT_FAILURE);
		}
		ptr_array[0] = command;
		ptr_array[1] = NULL;
		return (ptr_array);
	}
	while (arguments[token_count] != NULL)
	{
		token_count++;
	}
	ptr_array = malloc(sizeof(char *) * (token_count + 2));
	if (ptr_array == NULL)
	{
		perror("custom_shell");
		exit(EXIT_FAILURE);
	}
	ptr_array[0] = command;
	for (k = 0; k < token_count; k++)
	{
		ptr_array[k + 1] = arguments[k];
	}
	ptr_array[token_count + 1] = NULL;
	return (ptr_array);
}



/**
 * custom_execute - Executes a command with specified arguments.
 *
 * @command_path: The path to the executable of the command.
 * @arguments: An array of strings representing the arguments to the command.
 *
 * This function executes the command located at @command_path with the given
 * @arguments. It does not handle environment variables directly; consider
 * using the execve() family of functions for more advanced use cases.
 *
 * Return: The exit status of the executed command.
 */
int custom_execute(char *command_path, char **arguments)
{
	int exit_status = 0, wait_status = 0;
	char **cmd_with_args = build_command_arguments(command_path, arguments);
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("custom_shell");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(command_path, cmd_with_args, environ) == -1)
		{
			perror("custom_shell");
			_exit(127);
		}
	}
	wait(&wait_status);
	exit_status = WEXITSTATUS(wait_status);
	free(cmd_with_args);
	return (exit_status);
}



/**
 * run_any_command - Execute a command with arguments or search for it in PATH
 *
 * @command: The command to run or search for
 * @args: The arguments to the command
 * Return: The exit status of the command
 */
int run_any_command(char *command, char **args)
{
	char *system_path = getenv("PATH");
	char *duplicate_path;
	char *command_path = NULL;
	char *token;
	int result = 1;

	if (my_builtins(command))
	{
		execute_custom_builtins(command, args);
		return (1);
	}
	if (strchr(command, '/') != NULL)
		return (custom_execute(command, args));
	if (system_path == NULL || system_path[0] == '\0')
		return (127);
	duplicate_path = strdup(system_path);
	token = tokenize_custom(duplicate_path, ":");
	while (token != NULL)
	{
		command_path = malloc(strlen(token) + strlen(command) + 2);
		if (command_path == NULL)
		{
			perror("custom_shell");
			free(duplicate_path);
			return (1);
		}
		sprintf(command_path, "%s/%s", token, command);
		if (access(command_path, X_OK) == 0)
		{
			result = custom_execute(command_path, args);
			free(command_path);
			free(duplicate_path);
			return (result);
		}
		free(command_path);
		token = tokenize_custom(NULL, ":");
	}
	free(duplicate_path);
	perror("custom_shell");
	return (127);
}


#include "shell.h"

/**
 * main - Entry point of the program.
 * @main_argc: Number of command-line arguments.
 * @main_argv: Array of strings representing command-line arguments.
 *
 * Return: 0 on successful execution.
 */
int main(int main_argc, char **main_argv)
{
	char *data_input = NULL;
	size_t input_size = 0;
	ssize_t input_len;
	int interactive = isatty(STDIN_FILENO);
	(void)main_argc;
	(void)main_argv;

	while (1)
	{
		if (interactive)
		{
			my_prompt();
		}
		input_len = getline(&data_input, &input_size, stdin);
		if (input_len == -1)
		{
			if (data_input != NULL)
			{
				free(data_input);
			}
			if (interactive)
			{
				printf("\n");
			}
			return (0);
		}
		if (data_input[input_len - 1] == '\n')
		{
			data_input[input_len - 1] = '\0';
		}
		process_input_line(data_input);
	}
	return (0);
}


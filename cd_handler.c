#include "shell.h"


/**
 * is_blank_space - checks if the input string contains only blank spaces
 * @str: the input string to be checked
 * Return: 1 if true (contains only blank spaces), 0 otherwise
 */
int is_blank_space(const char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n' ||
				*str == '\r' || *str == '\f' || *str == '\v')
		{
			str++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}



/**
 * process_input_line - Handles command arguments.
 * @data_input: The input line.
 */
void process_input_line(char *data_input)
{
	char *cmd, **arguments, **tokens, *tk;
	size_t i, count = 0;

	if (data_input == NULL || data_input[0] == '\0' || is_blank_space(data_input))
	{
		return;
	}
	data_input = delete_comments(data_input);
	tokens = custom_tokenizer(my_strtrim(data_input), ";", &count);
	for (i = 0; i < count; i++)
	{
		tk = tokens[i];
		cmd = split_command(&tk);
		arguments = run_arguments(tk);
		free(cmd);
		my_free(arguments);
	}
	my_free(tokens);
}


/**
 * split_command - split token into command and arguments
 * @token: the input token
 * Return: the command part
 */
char *split_command(char **token)
{
	char *cmd = NULL;
	char *save_ptr;

	cmd = strtok_r(*token, " \t", &save_ptr);
	*token = save_ptr;
	return (cmd);
}


/**
 * delete_comments - delete comments from a string
 * @str: the input string
 * Return: the modified string
 */
char *delete_comments(char *str)
{
	char *comment_start = str;

	while (*comment_start)
	{
		if (*comment_start == '#')
		{
			*comment_start = '\0';
			break;
		}
		comment_start++;
	}
	return (str);
}




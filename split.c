#include "shell.h"
/**
 * custom_tokenizer - Tokenizes a string using custom delimiters.
 * @str: The string to be tokenized.
 * @delim: A string containing delimiters.
 * @token_count: A pointer to an integer to store the number of tokens.
 *
 * Return: An array of token strings or NULL on failure.
 */
char **custom_tokenizer(const char *str, const char *delim,
	size_t *token_count)
{
	char **tokens = NULL;
	char *token = NULL;
	char *str_copy = strdup(str);
	char *saveptr = NULL;
	size_t count = 0;

	if (str_copy == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	token = strtok_r(str_copy, delim, &saveptr);
	while (token != NULL)
	{
		tokens = realloc(tokens, (count + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			perror("Memory allocation failed");
			free(str_copy);
			return (NULL);
		}
		tokens[count] = strdup(token);
		if (tokens[count] == NULL)
		{
			perror("Memory allocation failed");
			free(str_copy);
			return (NULL);
		}
		count++;
		token = strtok_r(NULL, delim, &saveptr);
	}
	free(str_copy);
	*token_count = count;
	return (tokens);
}





/**
 * my_strtrim - Trim leading and trailing whitespace from a string.
 * @str: The string to be trimmed.
 *
 * Return: A pointer to the trimmed string.
 */
char *my_strtrim(char *str)
{
	int length = strlen(str);
	int start = 0;

	while (length > 0 && isspace((unsigned char)str[length - 1]))
	{
		length--;
	}
	str[length] = '\0';
	while (isspace((unsigned char)str[start]))
	{
		start++;
	}
	if (start > 0)
	{
		memmove(str, str + start, length - start + 1);
	}
	return (str);
}



/**
 * tokenize_custom - Tokenizes a string using specified delimiters.
 * @str: The string to be tokenized.
 * @delimiters: A string containing the delimiter characters.
 *
 * This function tokenizes the input string @str by breaking it into tokens
 * based on the characters found in @delimiters.
 *
 * Return: A pointer to the next token or NULL if there are no more tokens.
 */
char *tokenize_custom(char *str, const char *delimiters)
{
	static char *next_token;
	char *current_token = NULL;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	current_token = next_token;
	while (*next_token != '\0' && strchr(delimiters, *next_token) == NULL)
		next_token++;
	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}
	return (current_token);
}


#include "shell.h"

/**
 * run_arguments - Tokenizes the input string to extract arguments.
 * @line: The input line to be parsed.
 * Return: A pointer to an array of argument strings.
 */
char **run_arguments(char *line)
{
    size_t argurment_count, j;
    char **tokens;
    char **arguments;


    tokens = custom_tokenizer(line, " \t\n", &argurment_count);

    if (argurment_count)
    {
        arguments = malloc(sizeof(char *) * (argurment_count + 1));
        if (arguments == NULL)
        {
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
        for (j = 1; j < argurment_count; j++)
        {
            arguments[j - 1] = strdup(tokens[j]);
            if (arguments[j - 1] == NULL)
            {
                perror("./hsh");
                exit(EXIT_FAILURE);
            }
        }
        arguments[argurment_count - 1] = NULL;
        my_free(tokens);
        return arguments;
    }


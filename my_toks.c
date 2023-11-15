#include "shell.h"

/**
 * custom_tokenizer - Tokenizes a string using custom delimiters.
 * @str: The string to be tokenized.
 * @delimiters: A string containing delimiters.
 * @token_count: A pointer to an integer to store the number of tokens.
 * Return: An array of token strings or NULL on failure.
 */
#include "shell.h"

char **custom_tokenizer(const char *str, const char *delimiters, size_t *token_count) {
    char **tokens = NULL;
    char *token = NULL;
    char *str_copy = strdup(str);
    char *saveptr = NULL;
    size_t count = 0;

    if (str_copy == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    token = strtok_r(str_copy, delimiters, &saveptr);
    while (token != NULL) {
        tokens = realloc(tokens, (count + 1) * sizeof(char *));
        if (tokens == NULL) {
            perror("Memory allocation failed");
            free(str_copy);
            return NULL;
        }
        tokens[count] = strdup(token);
        if (tokens[count] == NULL) {
            perror("Memory allocation failed");
            free(str_copy);
            return NULL;
        }
 count++;
        token = strtok_r(NULL, delimiters, &saveptr);
    }

    free(str_copy);

    *token_count = count;

    return tokens;
}


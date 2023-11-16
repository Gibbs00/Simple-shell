#ifndef SHELL_H
#define SHELL_H

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Constants for command chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN

/* Using system getline() and strtok */
#define USE_GETLINE 0
#define USE_STRTOK 0
/* History file and maximum history entries */
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

/* Constants for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Shell Function */

extern char **environ;

void my_prompt(void);
int _atoi(char *s);

char **custom_tokenizer(const char *str, const char *delim,
	size_t *token_count);

void process_input_line(char *data_inpu);
char *split_command(char **token);
char *delete_comments(char *str);
char *my_strtrim(char *str);
void my_free(char **arr);
int is_blank_space(const char *str);
char **run_arguments(char *line);
int run_any_command(char *command, char **args);
char **build_command_arguments(char *command, char **arguments);
char *tokenize_custom(char *str, const char *delimiters);
int execute_custom_builtins(const char *command, char **args);
int my_builtins(const char *command);
void execute_env(char **args);
void execute_setenv(char **args);
void execute_unsetenv(char **args);
void execute_cd(char **args);
int custom_execute(char *command_path, char **arguments);
int process_logical_operator(char *);
extern char **environ;



/* mygetline functions */
void _realloc_buffer(char **buffer, size_t *current_size, size_t new_size);
ssize_t my_getline(char **input_buffer, size_t *buffer_size, FILE *stream);

#endif /* SHELL_H */


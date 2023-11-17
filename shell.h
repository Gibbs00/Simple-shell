#ifndef SHELL_H
#define SHELL_H
<<<<<<< HEAD
=======

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
>>>>>>> 473caade73eec2cbd22f4e501a06ec5de9665bbf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

void shell_show_prompt(void);
void shell_printf(const char *message);
void get_command(char *command, size_t size);
void exe_command(const char *command);


/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int checker(char **cmd, char *buf);
void prompt_user(void);
void handle_signal(int m);
char **tokenizer(char *line);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);

void print_env(void);

/* string handlers */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

void execution(char *cp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void free_buffers(char **buf);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif

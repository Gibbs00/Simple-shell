#include "shell.h"

/**
 * exe_command - Execute a shell command in a child process.
 * This function forks a child process to execute the provided shell command.
 * @command: The shell command to be executed
 * Returns: a prompt on success.
 */

void exe_command(const char *command)
{
	 pid_t child_pid = fork();

	 if (child_pid == -1)
	 {
		perror("fork");
		exit(EXIT_FAILURE);
	 }
	 else if (child_pid == 0)
	 {
		 execlp(command, command, (char *)NULL);
		 perror("execve");
		 exit(EXIT_FAILURE);
	 }
	 else
	 {
		 wait(NULL);
	 }
}

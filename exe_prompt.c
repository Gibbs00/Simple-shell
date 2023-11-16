#include "shell.h"

/**
 * exe_command - Execute a shell command in a child process.
 * This function forks a child process to execute the provided shell command.
 * The child process attempts to execute the command using execve, and the parent
 * process waits for the child to complete.
 * @command: The shell command to be executed.
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
		 execve(command, command, (char *)NULL);
		 perror("execve");
		 exit(EXIT_FAILURE);
	 }
	 else
	 {
		 wait(NULL);
	 }
}

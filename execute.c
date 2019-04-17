#include "holberton.h"
/**
* execute - forks a child process and runs the execve function inside
* @command: array of commands
* @argv: argument vector from main function
*
* Return: nothing
*/

void execute(char *command[], char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(command[0], command, environ);
		perror(argv[0]);
		exit(0);
	}

	waitpid(child_pid, &status, 0);
}

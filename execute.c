#include "holberton.h"
/**
* execute - forks a child process and runs the execve function inside
* @pathcommand: full command from path
* @command: array of commands
* @env: environment variable from main
* @argv: argument vector from main function
*
* Return: nothing
*/

void execute(char *pathcommand, char *command[], char **env, char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (!pathcommand)
			execve(command[0], command, env);
		else
			execve(pathcommand, command, env);
		perror(argv[0]);
		exit(0);
	}

	waitpid(child_pid, &status, 0);
}

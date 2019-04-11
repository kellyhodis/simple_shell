#include "holberton.h"

void execute(char *command, char *arguments[], char **env, char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(command, arguments, env);
		perror(argv[0]);
		exit(0);
	}

	waitpid(child_pid, &status, 0);
}

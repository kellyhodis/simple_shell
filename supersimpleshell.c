#include "holberton.h"

int main(void)
{
	char *buffer = NULL, *token;
	char *command[15];
	size_t size = 1024;
	int i = 0, status;
	pid_t child_pid;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		getline(&buffer, &size, stdin);

		token = strtok(buffer, "\n");
		while (token != NULL)
		{
			command[i] = strdup(token);
			i++;
			token = strtok(NULL, "\n");
		}
		command[i] = NULL;

		child_pid = fork();
		if (child_pid == 0)
		{
			execve(command[0], command, NULL);
			exit(0);
		}
		waitpid(child_pid, &status, 0);
		buffer = NULL;
		i = 0;
	}
	return (0);	
}

#include "holberton.h"

int main(int argc, char **argv)
{
	char *buffer = NULL, *token1, *token2;
	char *command[15];
	size_t size = 1024;
	int i = 0, status;
	pid_t child_pid;

	(void)argc;

	
	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		getline(&buffer, &size, stdin);

		token1 = strtok(buffer, "\n");
		token2 = strtok(token1, " ");
		while (token2 != NULL)
		{
			command[i] = strdup(token2);
        		i++;
        		token2 = strtok(NULL, " ");
        	}
        	command[i] = NULL;
		
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(command[0], command, NULL);
			perror(argv[0]);
			exit(0);
		}
		waitpid(child_pid, &status, 0);
		buffer = NULL;
		i = 0;
	}
	return (0);	
}

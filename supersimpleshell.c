#include "holberton.h"

int main(void)
{
	char *buffer = NULL, *token;
	char *command[15];
	size_t size = 1024;
	int i = 0;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	getline(&buffer, &size, stdin);
	
	token = strtok(buffer, "\n");
	while (token != NULL)
	{
		command[i] = strdup(token);
		printf("%s\n", command[i]);
		i++;
		token = strtok(NULL, "\n");
	}
	command[i] = NULL;
	execve(command[0], command, NULL);
	perror( "failed");
	exit(EXIT_FAILURE);

	return (0);	
}

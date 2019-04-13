#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
/**
* main - waits for the user to enter a command and prints it on the next line
* @argc: number of arguments
* @argv: argument vector
*
* Return: 0
*/

int main(void)
{
	char *buffer = NULL;
	size_t size = 100;
	int i;

	write(STDOUT_FILENO, "$ ", 2);
	getline(&buffer, &size, stdin);
	for (i = 0; buffer[i]; i++)
		;
	write(STDOUT_FILENO, buffer, i);

	return (0);

}

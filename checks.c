#include "holberton.h"
/**
* checks - checks the first command element against edge cases
* @command: array of commands
* @searched_path: flag to indicate whether or not the path was searched
* @buffer: allocated buffer that holds input
* @from_term: flag to indicate whether or not the input was from terminal
*
* Return: nothing
*/

int checks(char *command[], int *searched_path, char *buffer, int *from_term, int *ln, char **argv)
{
	int execute_on = 1;
	struct stat st;
	char *count;
	
	(void)ln;
	check_exit(command, buffer, from_term);
	execute_on = env_check(command[0]);
	if (stat(command[0], &st) != 0)
	{
		command[0] = search_path(command[0], searched_path);
		if (stat(command[0], &st) != 0)
		{
			count = _itoa(*ln);
			execute_on = 0;
			write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, count, _strlen(count));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, command[0], _strlen(command[0]));
			write(STDOUT_FILENO,": not found\n", 12);
			free(count);
		}
	}
	return (execute_on);
}

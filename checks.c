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

int checks(char *command[], int *searched_path, char *buffer, int *from_term)
{
	int execute_on = 1;
	struct stat st;

	check_exit(command, buffer, from_term);
	execute_on = env_check(command[0]);
	if (stat(command[0], &st) != 0)
		command[0] = search_path(command[0], searched_path);
	return (execute_on);
}

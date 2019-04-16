#include "holberton.h"
/**
* checks - checks the first command element against edge cases
* @command: array of commands
* @env: environment variable from main
* @searched_path: flag to indicate whether or not the path was searched
* @buffer: allocated buffer that holds input
*
* Return: nothing
*/

int checks(char *command[], char **env, int *searched_path, char *buffer)
{
	int execute_on = 1;
	struct stat st;

	check_exit(command, buffer);
	execute_on = env_check(command[0], env);
	if (stat(command[0], &st) != 0)
		command[0] = search_path(command[0], env, searched_path);
	return (execute_on);
}

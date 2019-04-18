#include "holberton.h"
/**
* checks - checks the first command element against edge cases
* @command: array of commands
* @s_p: flag to indicate whether or not the path was searched
* @buf: allocated buffer that holds input
* @f_t: flag to indicate whether or not the input was from terminal
* @ln: line number.
* @av: argument volume.
* Return: nothing
*/

int checks(char *command[], int *s_p, char *buf, int *f_t, int *ln, char **av)
{
	int execute_on = 1;
	struct stat st;
	char *count;

	(void)count;
	(void)av;
	(void)ln;
	check_exit(command, buf, f_t);
	execute_on = env_check(command);
	if (stat(command[0], &st) != 0)
	{
		command[0] = search_path(command[0], s_p);
	}
	return (execute_on);
}

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

<<<<<<< HEAD
	(void)av;
	(void)count;
=======
	(void)count;
	(void)av;
>>>>>>> aa1b74d6329227679aee35f7fd4e2b51bcc5208b
	(void)ln;
	check_exit(command, buf, f_t);
	execute_on = env_check(command);
	if (stat(command[0], &st) != 0)
	{
		command[0] = search_path(command[0], s_p);
<<<<<<< HEAD
/*		if (stat(command[0], &st) != 0)
		{
			count = _itoa(*ln);
			execute_on = 0;
			write(STDOUT_FILENO, av[0], _strlen(av[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, count, _strlen(count));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, command[0], _strlen(command[0]));
			write(STDOUT_FILENO, ": not found\n", 12);
			free(count);
		}
*/	}
=======
	}
>>>>>>> aa1b74d6329227679aee35f7fd4e2b51bcc5208b
	return (execute_on);
}

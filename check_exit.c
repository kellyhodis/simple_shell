#include "holberton.h"
/*
* check_exit - checks to see if the terminal input was "exit"
* and quits the shell if so
* @command: array of command and arguments to the command
*
* Return: nothing
*/

/* if function returns -1, it tells program to quit */
void check_exit(char *command[])
{
	int exitcode = 0;

	if (_strcmp(command[0], "exit") == 0)
	{
		if (command[1])
		{
			exitcode = _atoi(command[1]);
			exit(exitcode);
		}
		exit(0);
	}
} 

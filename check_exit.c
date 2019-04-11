#include "holberton.h"


/* if function returns -1, it tells program to quit */
int check_exit(char *command[])
{
	int exitcode = 0;

	if (_strcmp(command[0], "exit") == 0)
	{
		if (command[1])
		{
			exitcode = _atoi(command[1]);
			exit(exitcode);
		}
		return (-1);	
	}
	return (0);
} 

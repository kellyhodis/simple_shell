#include "holberton.h"
/**
* word_token - separates a line into an array of commands
* @command: array of strings for commands
* @str: line to parse
*
* Return: nothing
*/

void word_token(char *command[], char *str)
{
	int i = 0;
	char *word = NULL;

	word = strtok(str, " ");
	while (word)
	{
		command[i] = word;
		i++;
		word = strtok(NULL, " ");
	}
	command[i] = NULL;
}


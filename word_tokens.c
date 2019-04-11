#include "holberton.h"

void word_token(char *command[], char *str)
{
	int i = 0;
	char *word = NULL;

	word = strtok(str, " ");
	while (word)
	{
		command[i] = strdup(word);
		i++;
		word = strtok(NULL, " ");
	}
	command[i] = NULL;
}
		

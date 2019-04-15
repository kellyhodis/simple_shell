#include "holberton.h"
/**
* _strtok - tokenizes strings
* @str: string to tokenize
* @delim: delimiters to search string for
*
* Return: pointer to first token
*/
char *_strtok(char *str, const char *delim)
{
	const char *dm;
	static char *place;
	char *hold;

	if (str)
		place = str;
	if (delim)
		dm = delim;
	hold = place;
	while (*place)
	{
		while (*dm)
		{
			if (*place == *dm)
			{
				*place = '\0';
				break;
			}
			dm++;
		}
		place++;
		if (*(place - 1) == '\0')
			break;
	}

	return (hold);
}

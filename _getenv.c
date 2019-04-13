#include "holberton.h"

char *_getenv(const char *name)
{
	extern char **environ;
	char *tempenv;
	char *compare = NULL;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tempenv = strdup(environ[i]);
		compare = strtok(tempenv, "=");
		if (strcmp(compare, name) == 0)
		{
			return (strtok(NULL, "\n"));


		}
	}
	return (0);
}

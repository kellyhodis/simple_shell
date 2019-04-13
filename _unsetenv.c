#include "holberton.h"

int _unsetenv(const char *name)
{
	extern char **environ;
	char *tempenv;
	char *compare = NULL;
	int i;

	if (_getenv(name) == NULL)
		return (0);
	for (i = 0; environ[i]; i++)
	{
		tempenv = strdup(environ[i]);
		compare = strtok(tempenv, "=");
		if (strcmp(compare, name) == 0)
		{
			environ[i] = NULL;
			if (!environ[i])
				return (0);
			else
				return (-1);
		}
	}

	return (-1);
}

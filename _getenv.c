#include "holberton.h"

char *_getenv(const char *name)
{
		extern char **environ;
		char *tempo;
		char *token = NULL;
		int index = 0; 

		for (; environ[index]!= NULL; index++)
		{
			tempo = strdup(environ[index]);
			token = strtok(tempo, "=");
		
			if (strcmp(token, name) == 0)
			{
				return (strtok(NULL, "\n"));
			}
		
		}
	return (0);
}

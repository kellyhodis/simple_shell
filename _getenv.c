#include "holberton.h"

char *_getenv(const char *name)
{
		extern char **environ;
		char *tempo;
		char *tempo_start;
		char *token = NULL;
		char *match;
		int index = 0; 

		for (; environ[index]!= NULL; index++)
		{
			tempo = strdup(environ[index]);
			tempo_start = tempo;
			token = strtok(tempo, "=");
					
			if (strcmp(token, name) == 0)
			{
				match = strdup(strtok(NULL, "\n"));
				free(tempo_start);
				return (match);
			}
			free(tempo_start);
		}
	return (0);
}

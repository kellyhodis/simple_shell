#include "holberton.h"
/**
* _getenv - looks for a particular variable in the current environment
* @name: variable to seek
* @env: environment variable from main
*
* Return: pointer to the value at this variable in env
*/
char *_getenv(const char *name, char **env)
{
	char *tempo;
	char *tempo_start;
	char *token = NULL;
	char *match;
	int index = 0;

	for (; env[index] != NULL; index++)
	{
		tempo = strdup(env[index]);
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
	return (NULL);
}

#include "holberton.h"

int env_check(char *command, char **env)
{
	if (_strcmp(command, "env") == 0)
	{
		_env(env);
		return (0);
	}
	return (1);
}

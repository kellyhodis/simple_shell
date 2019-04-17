#include "holberton.h"

/**
* _env - prints the current environment
* @environ: environment variable
*
* Returns: nothing
*/

void _env(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i++]);
	}
}


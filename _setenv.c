#include "holberton.h"

int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char *src1, *src2;
	char equal = '=';
	int i, j, k;

	if (_getenv(name) && overwrite == 0)
		return (0);
	for (i = 0; environ[i]; i++)
		;
	/* env[i] is where to set the new env variable */
	/* get length of name */
	for (j = 0; name[j]; j++)
		;
	/* malloc space for length of name + 1 for '=' */
	src1 = malloc(j + 2);
	if (!src1)
		return (-1);

	for (j = 0; name[j]; j++)
		src1[j] = name[j];
	src1[j] = equal;
	src1[j + 1] = '\0';

	for (k = 0; value[k]; k++)
		;
	src2 = malloc(k + 1);
	if (!src2)
		return (-1);

	for (k = 0; value[k]; k++)
		src2[k]	= value[k];
	src2[k] = '\0';

	environ[i] = malloc(k + j + 2);
	if (!environ[i])
		return (-1);

	for (j = 0; src1[j]; j++)
		environ[i][j] = src1[j];

	for (k = 0; src2[k]; k++)
		environ[i][j + k] = src2[k];
	environ[i][j + k] = '\0';
	environ[i + 1] = NULL;
	return (0);
}

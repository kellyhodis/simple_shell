#include "holberton.h"
/**
* piped_in - reads input to buffer if it is piped in from stdin
* @lines: array of strings
* @buffer: string to store input
*
* Return: flag
*/
int piped_in(char *lines[], char *buffer)
{
	int flag, j;
	size_t size = 1024;
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (1);
	read(STDIN_FILENO, buffer, size);
	printf("buffer: %s\n", buffer);
	j = 0;
	flag = 0;
	lines[j] = strtok(buffer, "\n");
	/*delimiter by line */
	while (lines[j])
	{
		j++;
		lines[j] = strtok(NULL, "\n");
	}
	for (j = 0; lines[j]; j++)
		printf("%s\n", lines[j]);
	return (flag);
}

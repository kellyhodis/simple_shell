#include "holberton.h"

/**
* line_token - splits input into lines
* @lines: array in which to store lines
* @term_buffer: buffer for reading from the terminal
*
* Return: nothing
*/

char *line_token(char *lines[], char *term_buffer)
{
	int getEOF = 0, j = 0;
	size_t size = 0;

	getEOF = getline(&term_buffer, &size, stdin);
	if (getEOF == -1)
		return (NULL);
	lines[j] = strtok(term_buffer, "\n");
	if (lines[j])
		lines[j + 1] = NULL;
	return (term_buffer);
}


#include "holberton.h"

/**
* line_token - splits input into lines
* @lines: array in which to store lines
* @term_buffer: buffer for reading from the terminal
*
* Return: nothing
*/

void line_token(char *lines[], char *term_buffer)
{
	int getEOF = 0, j = 0;
	size_t size = 1024;

	getEOF = read(STDIN_FILENO, term_buffer, size);
	if (getEOF == 0)
		exit(0);
	if (getEOF == -1)
	{
		lines[j] = NULL;
		return;
	}
	lines[j] = strtok(term_buffer, "\n");
	if (lines[j])
		lines[j + 1] = NULL;
}

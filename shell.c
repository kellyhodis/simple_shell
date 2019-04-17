#include "holberton.h"
/**
* main - act as interpreter & shell clone
* @argc: argument count
* @argv: argument vector
* @envp: environment variable
*
* Return: 0
*/

int main(int argc, char **argv)
{
	char piped_buffer[1024], *term_buffer = NULL;
	char *lines[15], *command[15];
	/* defaults */
	int terminal = 1, j = 0, i = 0, execute_on = 1;
	int on = 1, searched_path = 0;

	(void)argc;
	signal(SIGINT, handler_c);
	if (!(isatty(fileno(stdin))))
		terminal = piped_in(lines, piped_buffer);
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	while (on)
	{
		if (terminal)
			term_buffer = line_token(lines, term_buffer);
		for (j = 0; lines[j]; j++)
		{
			word_token(command, lines[j]);
			if (terminal)
				execute_on = checks(command, &searched_path, term_buffer, &terminal);
			else
				execute_on = checks(command, &searched_path, piped_buffer, &terminal);
			if (execute_on)
				execute(command, argv);
			else
				execute_on = 1;
			if (searched_path == 1)
				free(command[0]);
			searched_path = 0;
		}
		if (terminal)
			free(term_buffer);
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		reset(&i, &j, &execute_on);
		if (!terminal)
		{
			on = 0;
		}
	}
	return (0);
}

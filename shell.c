#include "holberton.h"

int main(int argc, char **argv, char **envp)
{
	char *piped_buffer = NULL, *term_buffer = NULL;
	char *lines[15], *command[15];
	size_t size = 1024;
	/* defaults */
	int terminal = 1, j = 0, i = 0, execute_on = 1;
	int on = 1, getEOF = 0, frompath = 0;
	char *pathcommand = NULL;
	struct stat st;

	(void)argc;

	if (!(isatty(fileno(stdin))))
		terminal = piped_in(lines, piped_buffer);
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	if (terminal)
		printf("omg\n");
	while (on)
        {
		if (terminal)
		{
			j = 0;
			getEOF = getline(&term_buffer, &size, stdin);
			if (getEOF == -1)
				break;
			lines[j] = strtok(term_buffer, "\n");
			lines[j + 1] = NULL;
			printf("%s\n", lines[j]);
		}
		for (j = 0; lines[j]; j++)
		{
			word_token(command, lines[j]);
			check_exit(command);
			execute_on = env_check(command[0], envp);
			if (stat(command[0], &st)!= 0)
			{
				pathcommand = search_path(command[0]);
				frompath = 1;
			}
			if (execute_on)
				execute(pathcommand, command, NULL, argv);
			if (frompath == 1)
			{
				free(pathcommand);
			}
			else
				execute_on = 1;
		}
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		reset(&i, &j, &execute_on);
		if (!terminal)
			on = 0;
	}
	free(piped_buffer);
	return (0);
}

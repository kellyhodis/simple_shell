#include "holberton.h"

/*
* main - functions as a shell-like interpreter
* @argc: argument count
* @argv: argument vector
* @envp: environment
*
* Return: 0
*/

int main(int argc, char **argv, char **envp)
{
	char *buffer = NULL, *oneline;
	char *command[15], *lines[15];
	size_t size = 1024;
	int i = 0, getEOF = 0, j = 0, dummy = 0;
	int on = 1, terminal = 1, execute_on = 1;
	struct stat st;
	(void)argc;
	/* allocate memory for buffer */
	buffer = _calloc(1, size);
	if (buffer == NULL)
		return ('\0');


	/* check if input is piped or from terminal */
	if (!(isatty(fileno(stdin))))
		terminal = piped_in(lines, buffer);
	
	/* prompt */
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	
	while (on)
	{
		if (terminal)
		{
			getEOF = getline(&buffer, &size, stdin);
			if (getEOF == -1)
				break;
			oneline = strtok(buffer, "\n");
			lines[j] = malloc(sizeof(char *));
			lines[j] = strdup(oneline); 
			lines[j + 1] = NULL;

		}
		while(lines[j])
		{
			word_token(command, lines[j]);
			check_exit(command);
			execute_on = env_check(command[0], envp);		
			if (stat(command[0], &st)!= 0)
				command[0] = search_path(command[0]);
			if (execute_on)
				execute(command, NULL, argv);	
			j++;
			reset(&i, &dummy, &execute_on);
		}
		/* if input was piped, do not repeat the loop */
		if (!terminal)
			on = 0;
		write(STDOUT_FILENO, "#cisfun$ ", 9);
/*		free_array_of_str(command);*/
		reset(&i, &j, &execute_on);
		while (lines[j])
		{
			free(lines[j]);
			j++;
		}
		j = 0;

		buffer = NULL;
	}
	free(buffer);
	return (0);	
}

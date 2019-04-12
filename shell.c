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
	char *buffer = NULL, *token1;
	char *command[15], *lines[15];
	size_t size = 1024;
	int i = 0, getEOF = 0, j = 0;
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
			token1 = strtok(buffer, "\n");
			lines[j] = strdup(token1); 
			lines[j + 1] = NULL;

		}
		while(lines[j])
		{
			word_token(command, lines[j]);
			if (check_exit(command) == -1)
				break; 
			execute_on = env_check(command[0], envp);		
			if (stat(command[0], &st)!= 0)
				command[0] = search_path(command[0]);
			if (execute_on)
				execute(command[0], command, NULL, argv);	
			j++;
			i = 0;
			execute_on = 1;
		}
		/* if input was piped, do not repeat the loop */
		if (!terminal)
			on = 0;
		write(STDOUT_FILENO, "#cisfun$ ", 9);
/*		free_array_of_str(command);*/
		reset(&i, &j, &execute_on);
		buffer = NULL;
	}
	free(buffer);
	return (0);	
}

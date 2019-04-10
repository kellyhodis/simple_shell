#include "holberton.h"

int main(int argc, char **argv, char **envp)
{
	char *buffer = NULL, *token1 = NULL, *token2 = NULL;
	char *command[15], *lines[15];
	size_t size = 1024;
	int i = 0, status, getEOF = 0, j = 0;
	pid_t child_pid;
	int on = 1, piped = 1, flag_1 = 1, exitcode;
	struct stat st;
	(void)argc;
	
	*command = _calloc(15,(sizeof(char *)));  
	*lines = _calloc(15,(sizeof(char *)));
	buffer = malloc(size);
	if (buffer == NULL)
		return ('\0');
	if (!(isatty(fileno(stdin))))
	{
		read(STDIN_FILENO, buffer, size);
		printf("%s\n", buffer);
		piped = 0;
	lines[j] = strtok(buffer, "\n");
	/* delimiter by line */
       		 while (lines[j])
        	{
                	printf("%s\n", lines[j]);
                	j++;
                	lines[j] = strtok(NULL, "\n");
        	}
        	j = 0;

	}	
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	while (on)
	{
		if (piped !=0)
		{
			getEOF = getline(&buffer, &size, stdin);
			printf("%s\n", buffer);
		if (getEOF == -1)
			break;
		lines[j] = "";
		if (lines[j])
			{
				/*lines[j] = malloc(strlen(buffer) + 1);*/
				lines[j] = strdup(buffer); 
				lines[j + 1] = NULL; 
			}
		}
	while(lines[j])
	{	
		if (piped != 0)
		{
			token1 = strtok(lines[j], "\n");
			printf("%s\n", token1);
		}
		else
		token1 = strtok(lines[j], "\0");
		token2 = strtok(token1," ");
		while (token2 != NULL)
		{
			command[i] = malloc(strlen(token2) + 1);
			command[i] = strdup(token2);
        		i++;
        		token2 = strtok(NULL, " ");
        	}
        	command[i] = NULL;
		if (_strcmp(command[0], "exit")== 0)
			{
				if (command[1] != NULL)
					{
						exitcode = _atoi(command[1]);
						exit(exitcode);
					}
					break;
			}
		if (_strcmp(command[0], "env") == 0)
			{
				flag_1 = 0;	
				_env(envp);
			}
	printf("%d\n",_setenv("PATH", ":test:church:/bin/ls", 1));			
			if (stat(command[0], &st)!= 0)
			command[0] = malloc(strlen(search_path(command[0])) + 1);
			command[0] = search_path(command[0]);
			if (flag_1)
			{	
				child_pid = fork();
				if (child_pid == 0)
				{
					execve(command[0], command, NULL);
					perror(argv[0]);
					exit(0);
				}
					waitpid(child_pid, &status, 0);
			}
			j++;
			i = 0;
			flag_1 = 1;
		}
			j = 0;
			buffer = NULL;
			if (piped == 0)
				on = 0;
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
	return (0);	
}

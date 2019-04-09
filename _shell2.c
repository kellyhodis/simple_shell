#include "holberton.h"

int main(int argc, char **argv, char **envp)
{
	char *buffer = NULL, *token2;
	char *command[15], *lines[15];
	size_t size = 1024;
	int i = 0, status, getEOF = 0, j = 0;
	pid_t child_pid;
	int on = 1, flag = 1, flag_1 = 1, exitcode;
	struct stat st;
	(void)argc;

	if (!(isatty(fileno(stdin))))
	{
		flag = 0;
	}
		
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	while (on)
	{
		getEOF = getline(&buffer, &size, stdin);
		if (getEOF == -1)
			break;
	lines[j] = strtok(buffer, "\n");
	while (lines[j])
	{
		j++;
		lines[j] = strtok(NULL, "\n");
	}
	j = 0;
	while(lines[j])
	{
		token2 = strtok(lines[j]," ");
		while (token2 != NULL)
		{
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
	/*_setenv("PATH", ": test: church: /bin/ls", 1);*/			
		if (stat(command[0], &st)!= 0)
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
		if (flag == 0)
			on = 0;
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
	return (0);	
}

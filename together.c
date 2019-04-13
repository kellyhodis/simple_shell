#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t child_pid;
	int i = 0, status;

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
			exit(0);
		}
		waitpid(child_pid, &status, 0);
		i++;
	}
	return (0);
}

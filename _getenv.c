#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


char *_getenv(const char *name);
int main(void)
{
 	getenv("HOME");
	printf("%s\n", getenv("PATH"));	
	printf("%s\n",_getenv("PATH"));
}
char *_getenv(const char *name)
{
		extern char **environ;
		char *tempo;
		char *token = NULL;
		int index = 0; 

		for (; environ[index]!= NULL; index++)
		{
			tempo = strdup(environ[index]);
			token = strtok(tempo, "=");
		
			if (strcmp(token, name) == 0);
			{
				return (strtok(NULL, "\n"));
			}
		
		}
	return (0);
}

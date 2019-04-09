#include "holberton.h" 

void _env(char **environ)
{
	int i = 0;
	while(environ[i]) 
	{
 		 printf("%s\n", environ[i++]); 
	}
}

#include <string.h>
#include <stdio.h>

int main(void)
{
	char st[] = "hello there, it's great to see you today!";
	char *token;

	token = strtok(st, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}

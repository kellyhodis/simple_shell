#include "holberton.h"

int main(int argc, char **argv, char **env)
{
	extern char **environ;
	(void)argc;

	printf("address of env = %p\n", (void *)env);
	printf("address of environ = %p\n", (void *)environ);

	return (0);
}

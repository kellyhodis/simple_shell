#include <stdio.h>

/**
* main - prints all the arguments without using ac
* @ac: unused
* @av: argument vector
*
* Return: 0
*/

int main(int ac, char *av[])
{
	int i = 0;

	(void)ac;
	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}

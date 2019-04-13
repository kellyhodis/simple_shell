#include "holberton.h"

int main(int argc, char **argv)
{
	int i = 1;
	struct stat st;

	if (argc < 2)
	{
		printf("Usage: %s path_to_file...\n", argv[0]);
		return (1);
	}

	while (argv[i])
	{
		printf("%s:", argv[i]);
		if (stat(argv[i], &st) == 0)
			printf(" FOUND\n");
		else
			printf(" NOT FOUND\n");
		i++;
	}
	return (0);
}

#include "holberton.h"

void free_array_of_str(char *arr[])
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

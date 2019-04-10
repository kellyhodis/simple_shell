#include "holberton.h"
/**
 * _calloc - function that allocates memory for an array
 * @nmemb: nmemeber to be used.
 * @size: size parameter.
 * Return: Always 0.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int x = 0;
	char *memo;

	if (nmemb == 0 || size == 0)
	return (NULL);

	memo = malloc(nmemb * size);
	if (memo == NULL)
	return (NULL);
	for (; x < nmemb * size; x++)
		memo[x] = 0;
	return (memo);
}

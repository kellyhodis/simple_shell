#include "holberton.h"
/**
* get_delim - go through pathway directories and concatenate
* @head: head of linked list.
* @str: string.
* @dir_slash: character pointer.
* Return: Null pointer.
*/
char *get_delim(struct dir_s *head, char *dir_slash, char *str, int *searched_path)
{
	struct dir_s *trav;
	struct stat st;
	int leng, n = 50;

	trav = head;

	while (trav != NULL)
	{
		for (leng = 0; trav->dir[leng]; leng++)
			;
		dir_slash = malloc(sizeof(char) * (strlen(str) + leng + 2));
		if (!dir_slash)
			return (NULL);
		for (leng = 0; trav->dir[leng]; leng++)
			dir_slash[leng] = trav->dir[leng];
		dir_slash[leng] = '/';
		dir_slash[leng + 1] = '\0';
		_strncat(dir_slash, str, n);
		if (stat(dir_slash, &st) == 0)
		{
			*searched_path = 1;
			return (dir_slash);
		}
		trav = trav->next;
		free(dir_slash);
	}
	*searched_path = 0;
	return (str);
}

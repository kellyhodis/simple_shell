#include "holberton.h"

/* linked list of directories */

char *search_path(char *str)
{
/* struct to be manipulated through linked list */
        struct dir_s *head, *curr, *prev, *trav;
	struct stat st;
	int n = 50, leng;
	char *dir_slash = NULL, *mybuf = NULL, *cat = NULL;
	char *forest = _getenv("PATH"); 

	/*allocated space for node type directory and tokenized */
        head = malloc(sizeof(struct dir_s));
        if (head == NULL)
                return (NULL);
	mybuf = malloc(sizeof(char) * 1024); /* there is a constant to replace 1024 with */
	if (!mybuf)
		return (NULL);
	mybuf = strtok(forest, ":");
	head->dir = strdup(mybuf); 
	prev = head;

        while (mybuf)
        {
		curr = malloc(sizeof(struct dir_s));
                if (curr == NULL)
			return (NULL);
		curr->dir = strdup(mybuf);
		prev->next = curr;
                prev = curr;
		mybuf = strtok(NULL, ":"); 
        }
	trav = head;
	while (trav!= NULL)
	{
		for(leng = 0;trav->dir[leng]; leng++)
    			; 
		dir_slash = malloc(leng + 2);
		if (!dir_slash)
			return (NULL);
		/* copy each character of trav->dir into dir_slash */ 
		for(leng = 0; trav->dir[leng]; leng++)
			dir_slash[leng] = trav->dir[leng];
		/* add the forward slash / character followed by null byte */
		dir_slash[leng] = '/';
		dir_slash[leng + 1] = '\0';
		printf("dir_slash: \n\n\n%s\n\n\n\n", dir_slash);
		/* add dir_slash and str together on the same line */
		cat =_strncat(dir_slash, str, n);
		if (stat(cat, &st)== 0)
		{
			free(dir_slash);
			return(cat);
		}
		free(dir_slash);
		trav = trav->next;
	}
        return (NULL);
}

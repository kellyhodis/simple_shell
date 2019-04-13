#include "holberton.h"

/* linked list of directories */

char *search_path(char *str)
{
/* struct to be manipulated through linked list */
        struct dir_s *head, *curr, *prev, *trav;
	struct stat st;
	int n = 50, leng;
	char *dir_slash, *mybuf = NULL;
	char *forest = _getenv("PATH"); 

	printf("forest:\n%s\n\n\n\n\n", forest);	

	/*allocated space for node type directory and tokenized */
        head = malloc(sizeof(struct dir_s));
        if (head == NULL)
                return (NULL);
	mybuf = strtok(forest, ":");
	head->dir = mybuf; 
	prev = head;

        while (mybuf)
        {
		curr = malloc(sizeof(struct dir_s));
                if (curr == NULL)
			return (NULL);
		curr->dir = mybuf;
		prev->next = curr;
                prev = curr;
		mybuf = strtok(NULL, ":"); 
        }
	trav = head;
	while (trav!= NULL)
	{
		for(leng = 0;trav->dir[leng]; leng++)
    			; 
		dir_slash = malloc(sizeof(char) * (strlen(str) + leng + 2));
		if (!dir_slash)
			return (NULL);
		/* copy each character of trav->dir into dir_slash */ 
		for(leng = 0; trav->dir[leng]; leng++)
			dir_slash[leng] = trav->dir[leng];
		/* add the forward slash / character followed by null byte */
		dir_slash[leng] = '/';
		dir_slash[leng + 1] = '\0';
		/* add dir_slash and str together on the same line */
		_strncat(dir_slash, str, n);
		if (stat(dir_slash, &st)== 0)
		{
			free(forest);
			return(dir_slash);
		}
		trav = trav->next;
		free(dir_slash);
	}
	free(forest);
	free_list(head);
	free(dir_slash);
        return (NULL);
}

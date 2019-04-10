#include "holberton.h"

/* linked list of directories */

char *search_path(char *str)
{
/* struct to be manipulated through linked list */
        struct dir_s *head;
        struct dir_s *curr;
        struct dir_s *prev;
        struct dir_s *trav;
	struct stat st;
	/*char *command = NULL;*/
/*	char *ptr[15];*/
	int leng;
	char *dir_slash = NULL;
	char *mybuf = NULL;
	char *cat = NULL; 
	char *forest = NULL;
 
	head = _calloc(1, sizeof(struct dir_s));
/*	printf("%d\n", _setenv("PATH", ":/usr/bin:/bin",1)); */
	forest = malloc(strlen(_getenv("PATH") + 1));
  	forest[0] = '\0';
	forest = _getenv("PATH");
	printf("%s\n",forest); 
/*allocated space for node type directory and tokenized */
        if (head == NULL)
                return (NULL);
		
		mybuf = strtok(forest, ":");
		head->dir = _calloc(1, strlen(mybuf) + 1);
 	        head->dir = strdup(mybuf);       
		prev = head;
		
        while (mybuf)
        {
   		curr =_calloc(1, sizeof(struct dir_s));
                printf("%s\n", mybuf);
		if (curr == NULL)
                return (NULL);
		curr->dir = _calloc(1, strlen(mybuf) + 1);
                curr->dir = strdup(mybuf);
		prev->next = curr;
                prev = curr;
	
               mybuf = strtok(NULL, ":"); 
        }
        trav = head;
	while (trav!= NULL)
	{
		for(leng = 0;trav->dir[leng]; leng++);
	
	dir_slash = malloc(strlen(trav->dir) + 2);
        if (dir_slash == NULL)
                return (NULL);
        dir_slash[0] = '\0';

        for(leng = 0;trav->dir[leng]; leng++)
                dir_slash[leng] = trav->dir[leng];
        dir_slash[leng] = '/';
        dir_slash[leng+1] = '\0';
		cat = malloc(strlen(dir_slash) + strlen(str) + 13);
		cat[0]= '\0';
		cat = strcat(dir_slash,str);
		if (stat(cat, &st)== 0)
			return(cat);
	trav = trav->next;
	}
	        return (NULL);
}

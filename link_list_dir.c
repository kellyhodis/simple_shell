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
	/*size_t size = 0;*/
	int n = 50;
	/*char *command = NULL;*/
/*	char *ptr[15];*/
	int leng;
	char *dir_slash;
	char *mybuf;
	char *cat = NULL ; 
	char *forest = getenv("PATH"); 

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

		for(leng = 0;trav->dir[leng]; leng++);
        dir_slash = malloc(leng + 1);
        if (dir_slash == NULL)
                return (NULL);
        
        for(leng = 0;trav->dir[leng]; leng++)
                dir_slash[leng] = trav->dir[leng];
        dir_slash[leng] = '/';
        dir_slash[leng+1] = '\0';
		cat =_strncat(dir_slash,str, n);
		if (stat(cat, &st)== 0)
			return(cat);
	trav = trav->next;
	}
	        return (NULL);
}

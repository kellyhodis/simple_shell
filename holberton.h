#ifndef HOLBERTON_H
#define HOLBERTON_H
<<<<<<< HEAD
=======

>>>>>>> e73b0c9e9f3acf117c23c42c317a6871f877f408
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

struct dir_s
{
	char *dir;
	struct dir_s *next;
}dir_s;

char *_strncat(char *dest, char *src, int n);
char *search_path(char *str);

/* size_t **directory(dir_s **head, char **envp, mem_t *some);*/
/* size_t *add_nodedir_end(dir_t **head, const char *dir);*/

<<<<<<< HEAD
#endif 
=======

#endif /* HOLBERTON_H */

>>>>>>> e73b0c9e9f3acf117c23c42c317a6871f877f408

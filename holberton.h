#ifndef HOLBERTON_H
#define HOLBERTON_H

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
#include <unistd.h>

/**
* struct dir_s - singly linked list
* @dir: malloc'd string that holds directory
* @next: points to the next node
*
* Description: singly linked list node structure for holding
* PATH directories
*/

typedef struct dir_s
{
	char *dir;
	struct dir_s *next;
} dir_s;

void handler_c(int signo);
char *_strtok(char *str, const char *delim);
void free_list(dir_s *head);
void word_token(char *command[], char *str);
int env_check(char *command, char **env);
void check_exit(char *command[]);
void reset(int *i, int *j, int *env_print);
void execute(char *pathcommand, char *command[], char **envp, char **argv);
int piped_in(char *lines[], char *buffer);
char *_strncat(char *dest, char *src, int n);
void *_calloc(unsigned int nmemb, unsigned int size);
char *search_path(char *str, char **env);
char *_getenv(const char *name, char **env);
int _strcmp(char *s1, char *s2);
void _env(char **environ);
int _atoi(char *str);
int _setenv(const char *name, const char *value, int overwrite);

#endif /* HOLBERTON_H */

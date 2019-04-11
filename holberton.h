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

typedef struct dir_s
{
	char *dir;
	struct dir_s *next;
}dir_s;

void free_array_of_str(char *arr[]);
void word_token(char *command[], char *str);
int env_check(char *command, char **env);
int check_exit(char *command[]);
void reset(int *i, int *j, int *env_print);
void execute(char *command, char *arguments[], char **envp, char **argv);
int piped_in(char *lines[], char *buffer);
char *_strncat(char *dest, char *src, int n);
void *_calloc(unsigned int nmemb, unsigned int size);
char *search_path(char *str);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
void _env(char **environ);
int _atoi(char *str);
int _setenv(const char *name, const char *value, int overwrite);
#endif 

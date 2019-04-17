#include "holberton.h"

void sig_handle()
{
  printf("Here’s the condition CTRL-C\n");
  signal(SIGINT,SIG_IGN);
}


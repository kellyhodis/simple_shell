#include "holberton.h"
/**
 * handler_c - Act as handler for signal function
 * @signo: number of signal.
 * Return: Void.
 */
void handler_c(int signo)
{
	(void)signo;
	write(0, "\n", 1);
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

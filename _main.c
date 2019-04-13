#include "holberton.h"

int main(void)
{	
	printf("%d\n", setenv("TEST", "meaningless", 0));
	printf("%d\n", _setenv("TEST2", "meaningFUL", 0));
	printf("%s\n", getenv("TEST"));
	printf("%s\n", _getenv("TEST2"));
	printf("%d\n", unsetenv("TEST"));
	printf("%d\n", _unsetenv("TEST2"));
	if (getenv("TEST2") == NULL)
		printf("deleted\n");
	else
		printf("%s\n", getenv("TEST2"));
	if (_getenv("TEST") == NULL)
		printf("deleted\n");
	else
		printf("%s\n", _getenv("TEST"));

	return (0);
}

#include "main.h"

/**
 * print_env - print environmental variables.
 */

void print_env(void)
{
char **env = environ;
int i;
for (i = 0; env[i]; i++)
{
printf("%s\n", env[i]);
}
}

/**
 * exit_func - exit shell
 * @number: number to exit the shell with
 */

void exit_func(char *number)
{
int n = atoi(number);
if (number == NULL)
exit(0);
else
exit(n);
}

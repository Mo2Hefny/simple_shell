#include "main.h"

/**
 * print_env - print environmental variables.
 * Return: 1 on success.
 */

int print_env(void)
{
char **env = environ;
int i;
for (i = 0; env[i]; i++)
{
printf("%s\n", env[i]);
}
return (1);
}

/**
 * exit_func - exit shell
 * @cmd: tokens
 */

void exit_func(char **cmd)
{
int n;

if (cmd[1] == NULL)
exit(0);

n = atoi(cmd[1]);
exit(n);
}

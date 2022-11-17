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
{
free(cmd);
exit(0);
}

n = atoi(cmd[1]);
free(cmd);
exit(n);
}

/**
 * change_dir - cd build-in
 * @cmd: tokens
 * Return: 1
 */

int change_dir(char **cmd)
{
char *prev = NULL, *current = NULL;

prev = get_env_variable("PWD");

if (!cmd[1])
{
if (chdir("/root") == -1)
{
perror("Error ~");
return (1);
}
current = "/root";
}
else if (cmd[1][0] == '-')
{
current = get_env_variable("OLDPWD");
if (chdir(current) == -1)
{
perror("Error -");
return (1);
}
}
else
{
if (chdir(cmd[1]) == -1)
{
perror("Error cd");
return (1);
}
current = cmd[1];
}
if (current)
{
setenv("PWD", current, 1);
setenv("OLDPWD", prev, 1);
}
return (1);
}

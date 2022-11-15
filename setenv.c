#include "main.h"

/**
 * set_env - set environmental variable.
 * @cmd: tokens
 * Return: 1 on success.
 */

int set_env(char **cmd)
{
if (!cmd[1] || !cmd[2])
{
fprintf(stderr, "Not enough arguments");
return (1);
}
if (setenv(cmd[1], cmd[2], 1) == -1)
fprintf(stderr, "No variable declared");
return (1);
}

/**
 * unset_env - unset environmental variable.
 * @cmd: tokens
 * Return: 1
 */

int unset_env(char **cmd)
{
if (!cmd[1])
fprintf(stderr, "No variable declared");
else if (unsetenv(cmd[1]) == -1)
fprintf(stderr, "Variable not found");
return (1);
}

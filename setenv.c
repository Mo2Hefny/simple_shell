#include "main.h"

/**
 * set_env - set environmental variable.
 * @name: variable name
 * @value: variable value
 * @flag: overwrite or not
 * Return: 1
 */

int set_env(char* name, char* value, int flag)
{
if (setenv(name, value, flag) == -1)
fprintf(stderr, "No variable declared");
return (1);
}

/**
 * unset_env - unset environmental variable.
 * @cmd: tokens
 * Return: 1
 */

int unset_env(char** cmd)
{
if (!cmd[1])
fprintf(stderr, "No variable declared");
else if (unsetenv(cmd[1]) == -1)
fprintf(stderr, "Variable not found");
return (1);
}

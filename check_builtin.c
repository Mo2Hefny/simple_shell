#include "main.h"

/**
 * handle_builtin - handle built in commands.
 * @cmd: commands array
 * Return: 1 if found command, 0 otherwise.
 */

int handle_builtin(char **cmd)
{
if (strncmp(cmd[0], "env", 3) == 0)
{
print_env();
return (1);
}
else if (strncmp(cmd[0], "exit", 4) == 0)
{
if (cmd[1] == NULL)
exit(0);
exit_func(cmd[1]);
return (1);
}
else if (strncmp(cmd[0], "setenv", 6) == 0)
{
if (!cmd[1] || !cmd[2])
{
fprintf(stderr, "Not enough arguments");
return (1);
}
else
return (set_env(cmd[1], cmd[2], 1));
}
else if (strncmp(cmd[0], "unsetenv", 8) == 0)
return (unset_env(cmd));
return (0);
}

/**
 * check_builtin _ checks for built in commands.
 * @cmd: commands array.
 * Return: 1 if found built in command, 0 other wise.
 */

int check_builtin(char **cmd)
{
if (handle_builtin(cmd))
{
free(cmd);
return (1);
}
else if (cmd[0][0] == '/')
{
execute(cmd[0], cmd);
free(cmd);
return (1);
}
return (0);
}

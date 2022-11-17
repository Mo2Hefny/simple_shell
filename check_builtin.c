#include "main.h"

/**
 * handle_builtin - handle built in commands.
 * @cmd: commands array
 * Return: 1 if found command, 0 otherwise.
 */

int handle_builtin(char **cmd)
{
if (strncmp(cmd[0], "env", 3) == 0)
return (print_env());

else if (strncmp(cmd[0], "exit", 4) == 0)
exit_func(cmd);

else if (strncmp(cmd[0], "setenv", 6) == 0)
return (set_env(cmd));

else if (strncmp(cmd[0], "unsetenv", 8) == 0)
return (unset_env(cmd));

else if (strncmp(cmd[0], "cd", 2) == 0)
return (change_dir(cmd));

return (0);
}

/**
 * check_builtin - checks for built in commands.
 * @cmd: commands array.
 * Return: 1 if found built in command, 0 other wise.
 */

int check_builtin(char **cmd)
{
if (handle_builtin(cmd))
{
return (1);
}
else if (cmd[0][0] == '/')
{
execute(cmd[0], cmd);
return (1);
}
return (0);
}

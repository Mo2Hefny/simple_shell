#include "main.h"

/**
 * get_path - gets PATH.
 * Return: PATH
 */

char *get_path()
{
char **env = environ;
char *temp;
int i;
for (i = 0; env[i]; i++)
{
if (strncmp(env[i], "PATH=", 5) == 0)
{
temp = env[i];
for (i = 0; temp[i]; i++)
if (temp[i] == ':')
temp[i] = ' ';
return (temp + 5);
}
}
return (NULL);
}

/**
 * check_path - checks which path does the aquired
 * command belongs to.
 * @paths: PATH array.
 * @cmd: command to check.
 */

void check_path(char **paths, char **cmd)
{
int i;
char *temp;

for (i = 0; paths[i]; i++)
{
temp = append_path(paths[i], cmd[0]);
if (access(temp, F_OK | X_OK) == 0)
{
execute(temp, cmd);
free(temp);
return;
}
free(temp);
}
execute(NULL, cmd);
}

/**
 * append_path - gets path of aquired command
 * @path: PATH
 * @cmd: command to add to PATH
 * Return: appended path
 */

char *append_path(char *path, char *cmd)
{
char *buff;
int i, j, len;

if (!path)
path = "";
if (!cmd)
cmd = "";
len = strlen(path) + strlen(cmd);
buff = malloc(sizeof(char) * (len + 2));
for (i = 0; path[i]; i++)
buff[i] = path[i];

if (path[i - 1] != '/')
buff[i++] = '/';

for (j = 0; cmd[j]; j++)
buff[i + j] = cmd[j];

buff[i + j] = '\0';

return (buff);
}

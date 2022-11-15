#include "main.h"

/**
 * execute - execute tokens passed from stdin
 * @cmd: command
 * @command: tokens passed to execute
 * Return: 0 if successful or -1 if failed
 */

int execute(char *cmd, char **command)
{
pid_t child;
int status;

child = fork();
if (child == 0)
{
if (execve(cmd, command, NULL) == -1)
{
perror("Error");
exit(-1);
}
}
else if (child == -1)
{
perror("Error");
return (1);
}
else
wait(&status);

return (0);
}

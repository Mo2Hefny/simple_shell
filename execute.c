#include "main.h"

/**
 * execute - execute tokens passed from stdin
 * @command: tokens passed to execute
 * Return: 0 if successful or -1 if failed
 */

int execute(char **command)
{
pid_t child;
int status;

if (strncmp(command[0], "exit", 4) == 0)
return (-1);

child = fork();
if (child == 0)
{
if (execve(command[0], command, NULL) == -1)
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

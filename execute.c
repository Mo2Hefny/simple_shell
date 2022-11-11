#include "main.h"

/**
 * execute - execute tokens passed from stdin
 * @command: tokens passed to execute
 * Return: 0 if successful or -1 if failed
 */

int execute(char **command)
{
pid_t child;
int stat;
char *cmd[] = {"/bin/ls", "-l", NULL};
if (strcpy(command[0], "exit") == 0)
return (-1);

child = fork();
if (child == 0)
{
if (execve(cmd[0], cmd, NULL) == -1)
{
perror("Error cmd");
exit(-1);
}
}
else if (child == -1)
{
perror("Error");
return(1);
}
else
wait(&stat);

return (0);
}

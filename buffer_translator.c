#include "main.h"

/**
 * numberofspaces - check number of spaces in buffer to
 * allocate the array of token strings.
 * @buff: buffer
 * @sep: separators.
 * Return: number of spaces;
 */

int numberofspaces(char *buff, char *sep)
{
int flag = 0, spaces = 0;
char *buf = buff;
while (*buf)
{
if (strchr(sep, *buf) && flag == 0)
{
spaces++;
flag = 1;
}
else if (strchr(sep, *buf) == NULL && flag == 1)
flag = 0;
buf++;
}

return (spaces);
}

/**
 * buffer_translator - Divides the buffer
 * into number of tokens to execute.
 * @buff: buffer
 * Return: tokens
 */

char **buffer_translator(char *buff)
{
char **tokens = NULL, *temp_token;
char *separator = " \t\n:";
int i = 0;
int spaces;

if (!buff)
return (NULL);
spaces = numberofspaces(buff, separator);
tokens = malloc(sizeof(char *) * (spaces + 2));
if (!tokens)
{
fprintf(stderr, "sh: allocation error\n");
exit(1);
}

temp_token = strtok(buff, separator);
while (temp_token)
{
if (temp_token[0] == '#' || temp_token[1] == '#')
break;
tokens[i++] = temp_token;
temp_token = strtok(NULL, separator);
}
tokens[i] = NULL;

return (tokens);
}

#include "main.h"

/**
 * iscomment - checks if the token is a comment.
 * @token: token.
 * Return: 1 if comment, 0 otherwise.
 */

int iscomment(char *token)
{
if (token[0] == '#' || token[1] == '#')
return (1);
return (0);
}

/**
 * numberofspaces - check number of spaces in buffer to
 * allocate the array of token strings.
 * @buff: buffer
 * Return: number of spaces;
 */

int numberofspaces(char *buff)
{
int i, spaces = 0;

for (i = 0; buff[i]; i++)
{

if (buff[i] == ' ')
spaces++;
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
char **tokens, *temp_token;
char *separator = " \t\n\r";
int i = 0;
int spaces;

if (!buff)
return (NULL);
spaces = numberofspaces(buff);
tokens = malloc(sizeof(char *) * (spaces + 2));
if (!tokens)
{
fprintf(stderr, "sh: allocation error\n");
exit(1);
}

temp_token = strtok(buff, separator);
while (temp_token)
{
if (iscomment(temp_token))
break;
tokens[i++] = temp_token;
temp_token = strtok(NULL, separator);
}
tokens[i] = NULL;
return (tokens);
}

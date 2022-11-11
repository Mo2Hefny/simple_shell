#include "main.h"

/**
 * main - Simple shell.
 * @argc: number of arguments.
 * @argv: argument strings.
 * Return: 0
 */

int main(int argc, char **argv)
{
char *buffer;
char **tokens;
int response;
size_t buffersize = 1024;

if (argc > 1)
{
if (execve(argv[1], argv, environ) == -1)
{
perror(argv[0]);
exit(-1);
}
}

buffer = malloc(buffersize);
if (!buffer)
{
perror("Unable to allocate buffer");
exit(1);
}
do {
printf("#cisfun$ ");
getline(&buffer, &buffersize, stdin);
tokens = buffer_translator(buffer);
execve(tokens[0], tokens, NULL);
response = execute(tokens);
} while (response != -1);

return (0);
}

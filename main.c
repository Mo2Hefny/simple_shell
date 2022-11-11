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
int response, piped = 0;
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
if (isatty(0))
{
piped = 1;
printf("#cisfun$ ");
}
if (getline(&buffer, &buffersize, stdin) == -1)
break;
buffer[strlen(buffer) - 1] = '\0';
tokens = buffer_translator(buffer);
response = execute(tokens);
free(tokens);
} while (piped && response != -1);
free(buffer);
return (0);
}

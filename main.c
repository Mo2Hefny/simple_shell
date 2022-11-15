#include "main.h"

/**
 * main - Simple shell.
 * @argc: number of arguments.
 * @argv: argument strings.
 * Return: 0
 */

int main(int argc, char **argv)
{
char *buffer, *path;
char **tokens, **paths;
size_t piped = 0, buffersize = 1024;
if (argc > 1)
if (execve(argv[1], argv, environ) == -1)
{
perror(argv[0]);
exit(-1);
}
buffer = malloc(buffersize);
path = get_path();
paths = buffer_translator(path);
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
{
putchar('\n');
break;
}
buffer[strlen(buffer) - 1] = '\0';
tokens = buffer_translator(buffer);
if (check_builtin(tokens))
continue;
check_path(paths, tokens);
free(tokens);
} while (piped);
free(buffer);
free(paths);
return (0);
}

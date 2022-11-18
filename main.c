#include "main.h"

/**
 * shell_interact - loop for user end.
 * @buffer: buffer string.
 * @paths: array of PATH strings.
 * @buffsize: buffer length.
 */

void shell_interact(char *buffer, char **paths, size_t buffsize)
{
char **tokens;
int piped = 1;

do {
if (isatty(0))
{
_puts("#cisfun$ ");
piped = 1;
}

if (getline(&buffer, &buffsize, stdin) == -1)
{
_putchar('\n');
break;
}

buffer[strlen(buffer) - 1] = '\0';
tokens = buffer_translator(buffer);

/* checks build-ins and frees tokens before recursion */
if (check_builtin(tokens))
continue;

check_path(paths, tokens);
free(tokens);
} while (piped);
free(buffer);
free(paths);
}

/**
 * main - Simple shell.
 * @argc: number of arguments.
 * @argv: argument strings.
 * Return: 0
 */

int main(int argc, char **argv)
{
char *buffer, *path, **paths;
size_t buffersize = 1024;
info_t info;
info.program = argv[0];
info.linecount = 0;

if (argc > 1)
if (execve(argv[1], argv, environ) == -1)
{
perror(info.program);
exit(-1);
}
buffer = malloc(buffersize);
path = get_env_variable("PATH");
paths = buffer_translator(path);
if (!buffer)
{
perror("Unable to allocate buffer");
exit(1);
}
shell_interact(buffer, paths, buffersize);

return (0);
}
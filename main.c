#include "main.h"

/**
 * shell_interact - loop for user end.
 * @buffer: buffer string.
 * @paths: array of PATH strings.
 * @buffsize: buffer length.
 */

void shell_interact(char *buffer, char **paths, size_t buffsize)
{
char **tokens = NULL;
int piped = 1, builtin;

do {
if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
{
_puts("$ ");
}
if (getline(&buffer, &buffsize, stdin) == -1)
{
write(STDERR_FILENO, "\n", 1);
break;
}

buffer[strlen(buffer) - 1] = '\0';

tokens = buffer_translator(buffer);
if (tokens == NULL || *tokens == NULL || **tokens == '\0')
continue;
/* checks build-ins and frees tokens before recursion */
builtin = check_builtin(tokens);
if (builtin != 0)
{
if (builtin == -1)
{
free(buffer);
free(paths);
exit_func(tokens, piped);
}
continue;
}
piped++;
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
char *path = NULL, *spaced = NULL, *buffer, **paths;
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
spaced = strdup(path);
spaced = separate_path(spaced);
paths = buffer_translator(spaced);
free(spaced);
if (!buffer)
{
perror("Unable to allocate buffer");
exit(1);
}
shell_interact(buffer, paths, buffersize);

return (0);
}

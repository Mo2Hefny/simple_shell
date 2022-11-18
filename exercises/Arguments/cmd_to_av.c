#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - prints all arguments
 *
 * @ac: number of arguments.
 * @av: NULL terminated string arguments.
 * Return: Always 0.
 */

int main(int ac, char **av)
{
char *token;
int i;
(void)ac;

for (i = 1; av[i]; i++)
{
token = strtok(av[i], "-");

while (token != 0)
{
printf("%s\n", token);
token = strtok(0, "-");
}
}

return(0);
}

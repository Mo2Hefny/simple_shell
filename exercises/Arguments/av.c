#include <stdio.h>

/**
 * main - prints all arguments
 *
 * @ac: number of arguments.
 * @av: NULL terminated arguments
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{

int i = 0;
(void)ac;

while (av[i])
      printf("%s ", av[i++]);

putchar('\n');

return (0);
}

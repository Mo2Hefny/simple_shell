#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints all arguments
 *
 * Return: Always 0.
 */

int main(void)
{

char *buffer;
size_t bufsize = 32;
ssize_t len;

buffer = (char *)malloc(bufsize * sizeof(char));
if( buffer == NULL)
{
perror("Unable to allocate buffer");
exit(1);
}

printf("$ ");
if ((len = getline(&buffer,&bufsize,stdin)) != -1 && buffer)
{
fwrite (buffer, 1, len, stdout);
}
free(buffer);
return(0);
}

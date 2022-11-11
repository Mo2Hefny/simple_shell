#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

char **buffer_translator(char *buff);
int numberofspaces(char *buff);
int execute(char **command);

#endif

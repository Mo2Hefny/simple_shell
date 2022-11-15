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
int execute(char *, char **command);
int check_builtin(char **);
int handle_builtin(char **);
void print_env();
void exit_func(char *);
char *get_path(void);
void check_path(char**, char**);
char *append_path(char*, char*);
void free_items(char**, ...);
int set_env(char*, char*, int);
int unset_env(char**);

#endif

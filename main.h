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
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* Write functions */
void _puts(char *str);
int _putchar(char c);

/* SHELL */
void handle_signal(int m);
void shell_interact(char *buff, char **paths, size_t size);
int execute(char *, char **command);

/* Tokenizer */
char **buffer_translator(char *buff);
int numberofspaces(char *buff);

/* BUILD-IN */
int check_builtin(char **);
int handle_builtin(char **);
int print_env(void);
void exit_func(char **);
int set_env(char **);
int unset_env(char **);
int change_dir(char **);

/* PATH */
char *get_env_variable(char *);
void check_path(char **, char **);
char *append_path(char *, char *);
void free_items(char **, ...);

/**
 * struct info - carries main information of program
 * @program: program name.
 * @linecount: number of lines in buffer.
 */

struct info
{
char *program;
int linecount;
};

typedef struct info info_t;

#endif

#ifndef SHELL_H
#define SHELL_H

/* ----------Libraries---------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* ----------Macros---------- */
extern char **environ;
#define BUFSIZE 1024
#define SPACE ' '
#define TAB '\t'

/* ----------Prototypes---------- */
/* shell.c */
int printPrompt(void);
/* ReadLine.c */
char *readLine(void);
/* parseLine.c */
char **parseLine(char *line);
/* handle_input.c */
int emptyLine(char *line);
/* execute.c */
int execute(char **args);
/* get_env.c */
char *getEnv(char *name);
/* getPath.c */
char *getPath(char *file);
/* free2.c */
void freeDP(char **args);
/* free2.c */
void freeMemory(char **tokens, size_t count);
/* exit shell function*/
void shell_exit(char **command, char *input);
#endif

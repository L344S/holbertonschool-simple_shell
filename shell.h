#ifndef SHELL_H
#define SHELL_H

/* ----------Libraries---------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
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
char *_getenv(char *name);
/* get_path.c */
char *get_path(char *file);
/* free2.c */
void freeDP(char **args);
/* free2.c */
void freeMemory(char **tokens, size_t count);

void listFilesInDirectory(const char *path);
void listFiles(const char *path);

#endif

#ifndef SHELL_H
#define SHELL_H

/* ----------Libraries---------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* ----------Macros---------- */
extern char **environ;
#define BUFSIZE 1024

/* ----------Prototypes---------- */
/* shell.c */
int printPrompt(void);
/* read_line.c -> reading the user input */
char *read_line(void);

void listFilesInDirectory(const char *path);

void listFiles(const char *path);

#endif

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

/* Macros */
#define BUFSIZE 1024

/* custom_prompt  */
void custom_prompt(void);
/* read_line.c -> reading the user input */
char *read_line(void);

void listFilesInDirectory(const char *path);

void listFiles(const char *path);

#endif

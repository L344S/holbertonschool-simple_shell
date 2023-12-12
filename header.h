#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Macros */
#define BUFSIZE 1024

/* NewShell.c -> printing a prompt */
int show_prompt(void);
/* read_line.c -> reading the user input */
char *read_line(void);

#endif

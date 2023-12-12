#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Macros */
#define BUFSIZE 1024

/* custom_prompt  */
int custom_prompt(void);
/* read_line.c -> reading the user input */
char *read_line(void);

#endif

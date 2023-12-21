#include "shell.h"

/**
* printPrompt - entry point
* Description: prints the custom prompt of our shell program
* Only if stdin is associated with a terminal
* Return: Nothing (void)
*/
void printPrompt(void)
{
    /* Declare and initialize a variable to store the prompt */
	char *prompt = "♥ ";
	/* Check if stdin is associated with a terminal */
	if (isatty(STDIN_FILENO) == true)
	printf("%s", prompt); /* Print the prompt */
}

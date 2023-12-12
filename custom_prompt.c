#include "shell.h"

/**
* show_prompt - entry point
* Return: Always 0 on success
*/

int custom_prompt(void)
{
	/* Define */
	char *prompt = "<3 ";

	/* Print the prompt */
	printf("%s", prompt);

	return (0);
}

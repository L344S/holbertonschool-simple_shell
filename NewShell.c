#include "header.h"

/**
* main - entry point
* @argc: argument count
* @argv: arguments passed
* Return: Always 0 on success
*/

int main(void)
{
	char *prompt = "<3 ";

	while (1)
	{
		/* Print the prompt */
		printf("%s", prompt);

		/* Read user input (you can use fgets) */
		read_line();
		/* ... Parse and execute the command */
	}

	return (0);
}

#include "shell.h"
/**
* main - entry point
* Return: Always 0 on success
*/
int main(void)
{
	while (1)
	{
	/* Print the prompt */
	custom_prompt();
	/* Read user input */
	read_line();
	/* execute the command */
	}

	return (0);
}

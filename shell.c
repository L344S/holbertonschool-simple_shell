#include "shell.h"
/**
* main - entry point to our shell
* @argc: variable that counts the number of arguments passed to the program
* @argv: array of strings containing the arguments passed to the program
* Return: Always 0 on success
*/
int main(int argc, char **argv)
{
	/* variables */
	const char *path = ".";  /* Default to current directory */
	/* (void) prevent unused variable error */
	(void)argc;
	(void)argv;

	while (1)
	{
	/* Print the prompt */
	custom_prompt();
	/* Read user input */
	read_line();
	/* execute the command */

	/* Call the function with the specified path */
	listFilesInDirectory(path);

	listFiles(path);
	}

	return (0);
}

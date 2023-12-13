#include "shell.h"
/**
* main - entry point
* Return: Always 0 on success
*/
int main(void)
{
	char *line;
	const char *path = ".";  /** Default to current directory */

	while (1)
	{
	/* Print the prompt */
	custom_prompt();
	/* Read user input */
	read_line();
	/* execute the command */

	/** Call the function with the specified path */
	listFilesInDirectory(path);

	listFiles(path);
	}

	return (0);
}

#include "shell.h"
/**
 * main - entry point
 * Return: Always 0 on success
 */
int main(void)
{
	/* variables */
	const char *path = ".";  /* Default to current directory */

	while (1)
	{
		custom_prompt();
		read_line();

	/* Call the function with the specified path */
	listFiles(path);
	}
	return (0);
}

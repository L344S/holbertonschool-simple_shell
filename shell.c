#include "shell.h"
/**
<<<<<<< HEAD
 * main - entry point
 * Return: Always 0 on success
 */
int main(void)
{
	int i;
	char *line;
	char **tokens;
=======
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
>>>>>>> refs/remotes/origin/main

	while (1)
	{
		custom_prompt();
		line = read_line();

<<<<<<< HEAD
		tokens = tokenize_line(line);
		execute_ls();

		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
		free(line);
=======
	/* Call the function with the specified path */
	listFilesInDirectory(path);

	listFiles(path);
>>>>>>> refs/remotes/origin/main
	}
	return (0);
}

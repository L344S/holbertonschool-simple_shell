#include "shell.h"

/**
 * main - entry point of the program
 * Description: run the shell program
 * Only if stdin is associated with a terminal
 * Print the prompt, get the input, parse the input line, execute the command
 * Return: 0 on success or a number on failure
 */
int main(void)
{
	char *input_line = NULL;         /* stores the input line by the user */
	char **command_arguments = NULL; /* stores the parsed command arguments */
	size_t len = 0;                   /* stores the length of the input line */
	ssize_t read;	/* stores the result of getline (number of characters read) */

	while (1) /* Infinite loop */
	{
		printPrompt(); /* Calls a function to print the shell prompt. */
		read = getline(&input_line, &len, stdin); /* Read the input line */

		if (emptyLine(input_line) == 1)
			continue;

		if (read == EOF)
		{
			free(input_line); /* Free the input_line */
			exit(0);          /* Exit with status 0 */
		}

		command_arguments = parseLine(input_line); /* i_l - array command argument */

		if (strcmp(command_arguments[0], "exit") == 0) /* Handle "exit" command */
		{
			freeDP(command_arguments); /* Free memory of command_arguments array */
			free(input_line);         /* Free the input_line */
			exit(0);                  /* Exit with status 0 */
		}

		if (execute(command_arguments) == -1) /* Check if the command is not found */
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", command_arguments[0]);
		}

		freeDP(command_arguments); /* Free memory of command_arguments array */
	}                              /* End of while loop */

	free(input_line); /* Free the memory of input_line */
	return (0);         /* return 0 on success */
}

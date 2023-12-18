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
	char *input_line = NULL;
	char **command_arguments;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&input_line, &len, stdin)) != -1)
	{
		/* Remove newline character from getline */
		input_line[read - 1] = '\0';
		/* Print the prompt */
		printPrompt();

		/* Check if emptyLine is filled with spaces or tabs */
		if (emptyLine(input_line) == 1) /* 1 is true */
		{
			continue; /* Go back to the beginning of the loop (printPrompt again) */
		}

		/* Parse the input line and store them in command_arguments array*/
		command_arguments = parseLine(input_line);

		/* Check if the user wants to exit the shell */
		if (strcmp(command_arguments[0], "exit") == 0) /* compare if arg0 == exit */
			break; /* if true, exit the shell */

		/* Check if the user input is a not a built-in command */
		if (execute(command_arguments) == -1)
		{
			/* Print error message */
			fprintf(stderr, "hsh: command not found: %s\n", command_arguments[0]);
			continue; /* Go back to the beginning of the loop (printPrompt again) */
		}

		freeDP(command_arguments); /* Free the command_arguments array */
		command_arguments = NULL; /* Set command_arguments to NULL */
	}

	free(input_line); /* Free the input_line */
	return (0); /* Return 0 on success */
}

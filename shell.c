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
	char *input_line;
	char **command_arguments;
	int status = 1;
	int return_code = 0;

	while (status)
	{
		status = isatty(0); /** Check if the program is running in interactive mode */
		if (status == 1)
			printPrompt(); /* Print the prompt */
		input_line = readLine();

		/* Check if emptyLine is filled with spaces or tabs */
		if (emptyLine(input_line) == 1) /* 1 is true */
			continue; /* Go back to the beginning of the loop (printPrompt again) */

		/* Parse the input line and store them in command_arguments array*/
		command_arguments = parseLine(input_line);

		/* Check if the user wants to exit the shell */
		if (input_line == NULL || strcmp(command_arguments[0], "exit") == 0) /* compare if arg0 == exit */
		{
			freeDP(command_arguments); /* Free the command_arguments array */
			free(input_line);         /* Free the input_line */
			exit(0);
		}

		/* Check if the user input is not a built-in command */
		if (execute(command_arguments) == -1)
		{
			/* Print error message */
			fprintf(stderr, "hsh: command not found: %s\n", command_arguments[0]);
			return_code = 2;
			continue; /* Go back to the beginning of the loop (printPrompt again) */
		}
		freeDP(command_arguments); /* Free the command_arguments array */
	}
	free(input_line); /* Free the input_line */
	return (return_code); /** Return 0 or 2*/
}

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

	while (1)
	{
		printPrompt(); /* Print the prompt */
		read = getline(&input_line, &len, stdin);
		if (read == -1) /* Check for EOF or error */
			break;
		/* Check if emptyLine is filled with spaces or tabs */
		if (emptyLine(input_line) == 1) /* 1 is true */
			continue;
		command_arguments = parseLine(input_line);
		if (strcmp(command_arguments[0], "exit") == 0) /* compare if arg0 == exit */
		{
			if (command_arguments[1] == NULL)
			{
			freeDP(command_arguments); /* Free the command_arguments array */
			free(input_line); /* Free the input_line */
			exit(0); /* Return 0 on success */
			}
			else
			{
				freeDP(command_arguments); /* Free the command_arguments array */
				free(input_line); /* Free the input_line */
				exit(2); /* Return 2 if there is an argument after exit */
				}
		/* Return 0 on success */
		}        /* Check if the user input is not a built-in command */
		if (execute(command_arguments) == -1)
		{
			/* Print error message */
			fprintf(stderr, "./hsh: 1: %s: not found\n", command_arguments[0]);
			freeDP(command_arguments); /* Free the command_arguments array */
			exit(127); /* Return 127 on failure */
			continue; /* Go back to the beginning of the loop (printPrompt again) */
		}
		freeDP(command_arguments); /* Free the command_arguments array */
	}
	free(input_line); /* Free the input_line */
	return (0); /* Return 0 on success */
}


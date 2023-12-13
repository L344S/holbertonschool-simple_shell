#include "shell.h"
/**
* parse_line - parse a line from stdin (user input)
* @line: pointer to the line from stdin
* Return: pointer to an array of arguments
*/
char **parse_line(char *line)
{
	size_t bufsize = BUFSIZE; /* initialize buffer size */
	int i = 0; /* index for arguments for loop */

	char **arguments; /* pointer to an array of arguments */

	const char *delimitor = " \t\r\n\v\f"; /* delimitor for strtok */

	char *token; /* pointer to a token */

	if (line == NULL || *line == '\0') /* check if input line is NULL */
		return (NULL);

	arguments = malloc(bufsize * sizeof(char *)); /* allocate memory */
	if (arguments == NULL) /* check if allocation failed */
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delimitor); /* get the first token */
	for (i = 0; token != NULL; i++) /* loop through the tokens */
	{
		arguments[i] = token; /* store the token in the arguments array */
		token = strtok(NULL, delimitor); /* get the next token */
	}

	if (i == 0) /* check if no arguments were entered */
	{
		free(arguments); /* free the arguments array */
		return (NULL);
	}

	arguments[i] = NULL; /* set the last element to NULL */

	/* handle exit built-in command */

	/* handle env built-in command */

	return (arguments); /* return the arguments array */
}

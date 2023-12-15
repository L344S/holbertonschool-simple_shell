#include "shell.h"

/**
* readLine - read a line from stdin
* Description:
    * Use getline function to get the input user from stdin
	* Getline will dynamically allocate memory and update input_line
	* Getline return the number of characters read and store it in nb_char_line
* Return: the line on success or NULL on failure
*/
char *readLine(void)
{
    /* Initialize the line */
	char *input_line = NULL;
    /* Initialize the size of the line */
	size_t size_line = 0;
    /* Initialize the number of characters read */
	ssize_t read;

	/* Read the line from stdin */
	read = getline(&input_line, &size_line, stdin);
	/* If getline fails */
	if (read < 0 || !read)
	{
		/* Print error message */
		perror("Failed to read the command\n");
		/* Free the line */
		free(input_line);
		/* Return NULL */
		return (NULL);
	}
	/* Return the line */
	return (input_line);
}

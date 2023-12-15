#include "shell.h"

/**
 * parseLine - splits a string into words (tokens)
 * Description: it use a delimiter to split the string
 * @line: the string to be splitted
 * Return: an array of strings (each word of the line string) or NULL
 */
char **parseLine(char *line)
{
	char *copy_line = NULL, *token = NULL; /* copy of the line -> input of users*/
	char *delimiters = " \t\n"; /* delimiters of the line */
	char **tokens = NULL; /* store the array of words */
	int count_token = 0, i = 0; /* count the number of words and index */

	/* Duplicate the line and store it in copy_line */
	copy_line = strdup(line);
	if (!copy_line) /* if strdup fails */
		return (NULL);

	/* Count the number of words in the line using delimiters */
	token = strtok(copy_line, delimiters);
	while (token)
	{
		count_token++; /* increment the number of words */
		token = strtok(NULL, delimiters); /* get the next word */
	}

	free(copy_line); /* free the copy of the line */
	count_token++; /* increment the number of words for the NULL sign */
	/* Allocate memory for the tokens (array of token) */
	tokens = malloc(sizeof(char *) * count_token);
	if (!tokens) /* if malloc fails */
		return (NULL);

	token = strtok(line, delimiters); /* Reset token to store again a word */
	/* Store each word(token) in the array of tokens */
	for (i = 0; i < count_token - 1 && token != NULL; i++)
	{
		tokens[i] = strdup(token); /* store the word */
		if (!tokens[i]) /* if strdup fails */
		{
			freeMemory(tokens, i); /* free the array of tokens */
			free(copy_line); /* free the copy of the line */
			return (NULL);
		}
		token = strtok(NULL, delimiters);
	}
	tokens[i] = NULL; /* add NULL at the end of the array of tokens */
	return (tokens); /* return the array of tokens */
}

#include "shell.h"

/**
* parseLine - splits a string into words (tokens)
* Description: it use a delimiter to split the string
* @line: the string to be splitted
* Return: an array of strings (each word of the line string) or NULL
*/
char **parseLine(char *line)
{
	char *copy_line = NULL, *token = NULL; /* copy of line -> input of users*/
	char *delimiters = " \t\r\n\a"; /* delimiters of the line */
	char **tokens = NULL; /* store the array of words */
	int count_token = 0, i = 0; /* count the number of words and index */

	copy_line = strdup(line); /* Duplicate the user input line to copy_line */
	if (!copy_line) /* if strdup duplicate fails */
		return (NULL); /* return NULL, indicating failure */
	token = strtok(copy_line, delimiters); /* Split the line into words */
	while (token) /* Loop through the line, count the number of words */
	{
		count_token++; /* increment the number of words */
		token = strtok(NULL, delimiters); /* get the next word until NULL */
	}
	free(copy_line); /* free the copy of the line */
	count_token++; /* increment the number of words for the NULL sign */
	tokens = malloc(sizeof(char *) * count_token); /* Allocate memory for tokens*/
	if (!tokens) /* if malloc allocation memory fails */
		return (NULL); /* return NULL, indicating failure */
	copy_line = strdup(line); /*Duplicate again the user input line to copy_line*/
	if (!copy_line) /* if strdup duplicate fails */
	{
		free(tokens); /* free the tokens array */
		return (NULL); /* return NULL, indicating failure */
	}
	token = strtok(copy_line, delimiters); /* Split the line into words */
	while (token) /* Loop through the line, store the words in tokens array */
	{
		tokens[i] = strdup(token); /* Duplicate the token to tokens array */
		if (!tokens[i]) /* if strdup duplicate fails */
		{
			free(tokens); /* free the tokens array */
			free(copy_line); /* free the copy of the user's line */
			return (NULL); /* return NULL, indicating failure */
		} i++; /* increment the index */
		token = strtok(NULL, delimiters); /* get the next word until NULL */
	}
	tokens[i] = NULL; /* Null-terminate the array of tokens */
	free(copy_line); /* free the copy of the line */
	return (tokens); /* return the array of tokens */
}


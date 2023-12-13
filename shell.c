#include "shell.h"
/**
 * main - entry point
 * Return: Always 0 on success
 */
int main(void)
{
	int i;
	char *line;
	char **tokens;

	while (1)
	{
		custom_prompt();
		line = read_line();

		tokens = tokenize_line(line);

		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
		free(line);
	}
	return (0);
}

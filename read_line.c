#include "shell.h"
/**
* read_line - read a line from stdin (user input)
* Return: char pointer to the line from stdin
*/
char *read_line(void)
{
	/* initialize pointeur vers une ligne à NULL */
	char *line = NULL;

	/* initialize taille du buffer  */
	size_t bufsize = BUFSIZE;

    /* utlise getline pour lire la ligne */
	if (getline(&line, &bufsize, stdin) == -1) /* si erreur */
	{
		if (feof(stdin)) /* si fin de fichier est atteinte */
		{
			exit(EXIT_SUCCESS); /* quitte (succès) */
			}
			else /* si il""" y a une erreur */
			{
				perror("readline"); /* affiche l'erreur */
				exit(EXIT_FAILURE); /* quitte (échec) */
			}
	}

    /* retourne la ligne lue */
	return (line);
}


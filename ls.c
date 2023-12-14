#include "shell.h"

/**
* listFiles - entry point
* @path: path to the directory to list
* Description: lists all files and sub-directories of a directory
* Return: Always 0 on success
*/

void listFiles(const char *path)
{

	DIR *dir;
	struct dirent *entry;

	/** Open the specified directory */
	dir = opendir(path);

	/** Check if the directory is opened successfully */
	if (dir == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	/** Read and print information about each entry in the directory */
	while ((entry = readdir(dir)) != NULL)
	{
		/** Skip entries that start with a dot (hidden files) */
		if (entry->d_name[0] != '.')
		{
			printf("%s\t", entry->d_name);
		}
	}

	/** Close the directory */
	closedir(dir);
}


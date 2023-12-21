#include "shell.h"

/**
 * execute - execute the command
 * @args: array of arguments -> command and arguments
 * Description: compares the command with the built-in commands and executes
 * Return: 0 in success or EXIT_FAILURE
 */
int execute(char **args)
{
	char *path_cmd = NULL; /* Stores the path of the command */
	pid_t child_pid; /* Stores the pid of the child process */
	int child_status; /* Stores the status of the child process */
	char **original_environ = environ; /* Stores the original value of environ */

	if (strcmp(args[0], "env") == 0) /* Handle "env" command */
	{
		while (*environ) /* Loop through the environment */
			printf("%s\n", *environ++); /* Print the environment and increment */
		environ = original_environ; /* Restore the original value of environ */
		return (0); /* Return 0 on success */
	}
	if (strcmp(args[0], "cd") == 0) /* Handle "cd" command */
	{
		if (args[1] == NULL) /* If there is no argument after cd */
			chdir(getenv("HOME")); /* Change the current directory to HOME */
		else if (chdir(args[1]) != 0) /* If chdir fails */
			perror("cd"); /* Print a error message */
		return (0); /* Return 0 on success */
	}

	path_cmd = getPath(args[0]); /* Get the path of the command */
	if (path_cmd == NULL) /* If the command is not found */
		return (-1); /* Return -1, indicating failure */

	child_pid = fork(); /* Create a child process */
	if (child_pid == -1) /* If fork fails */
	{
		perror("Error: fork failed"); /* Print a error message */
		free(path_cmd); /* Free the path_cmd */
		return (-1); /* Return -1, indicating failure */
	}
	if (child_pid == 0) /* If it's the child process */
	{
		environ = original_environ; /* Restore the original value of environ */
		if (execve(path_cmd, args, environ) == -1) /* Execute the command but if it fails */
		{
			perror("Error: execve failed"); /* Print a error message */
			free(path_cmd); /* Free the path_cmd */
			exit(EXIT_FAILURE); /* Exit with status EXIT_FAILURE */
		}
		else /* If execve succeeds */
			waitpid(child_pid, &child_status, 0); /* Wait for the child process */
	}

	free(path_cmd); /* Free the path_cmd */
	return (0); /* Return 0 on success */
}
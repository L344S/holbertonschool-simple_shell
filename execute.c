#include "shell.h"

/**
 * execute - execute the command
 * @args: array of arguments -> command and arguments
 * Description: compares the command with the built-in commands and executes
 * Return: 0 in success or EXIT_FAILIURE
 */
int execute(char **args)
{
	/* to store the abbolute path of the command */
	char *path_cmd = NULL, **env = environ; /* to store the env array */
	pid_t child_pid; /* to store the child_pid of the child process */
	int child_status, executeOK; /* to store the status cp and execve func */

	/* Check if the command is env a built-in command */
	if (strcmp(args[0], "env") == 0) /* compare if args0 == env */
	{
		while (*env) /* Go through the env array */
		{
			printf("%s\n", *env); /* Print each env variable */
			env++;
		}
		return (0); /* Return 0 on success */
	}
	path_cmd = getPath(args[0]); /* Get the abbolute path of the command */
	if (path_cmd == NULL) /* If getPath fails -> command not found */
		return (-1);

	child_pid = fork(); /* Create a new childprocess copy of our current process*/
	if (child_pid == -1) /* If create child process fails */
	{
		perror("Error ; fork failed"); /* Print error message */
		free(path_cmd); /* Free the path_cmd */
		return (-1); /* -1 on failure */
	} else if (child_pid == 0) /* If create child process success */
	{
		executeOK = execve(path_cmd, args, environ); /* Execute the command */
		if (executeOK == -1) /* If execute fails == -1 */
		{
			perror("Error ; execve failed"); /* Print error message */
			return (-1); /* -1 on failure */
		}
	} else
	{
		waitpid(child_pid, &child_status, 0); /* Wait for cp to finish */
	}
	free(path_cmd); /* Free the path_cmd */
	return (0); /* Return 0 on success */
}

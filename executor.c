#include "shell.h"

/**
 * exec_cmd - Execute a command using fork and execve.
 * @argv: array of strings (command + args), NULL-terminated
 * Return: exit status, or -1 on failure
 */
int exec_cmd(char **argv)
{
	pid_t pid;
	int status;

	if (argv == NULL || argv[0] == NULL || argv[0][0] == '\0')
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		execve(argv[0], argv, environ);
		perror(argv[0]);
		exit(127);
	}

	if (waitpid(pid, &status, 0) == -1)
		return (-1);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (-1);
}
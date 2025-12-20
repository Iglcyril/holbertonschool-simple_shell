#include "shell.h"

/**
 * exec_cmd - Execute command using execve
 * @argv: command arguments
 * @envp: environment variables
 * @prog_name: shell program name for error messages
 * Return: exit status of the command
 */
int exec_cmd(char **argv, char **envp, char *prog_name)
{
	pid_t pid;
	int status;

	(void)prog_name;

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
		if (execve(argv[0], argv, envp) == -1)
		{
			perror(prog_name);
			exit(127);
		}
	}

	if (waitpid(pid, &status, 0) == -1)
		return (-1);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (-1);
}

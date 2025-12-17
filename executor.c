#include "shell.h"
/**
 * exec_cmd - Execute a command using fork and execve.
 * @cmd_args: An array of strings representing the command and its arguments.
 * Return: The exit status of the command, or -1 on failure.
 */
int exec_cmd(char *cmd)
{
	pid_t child_process;
	int wait_status;
	int exit_code;
	char *args[2];

	if (cmd == NULL)
		return (-1);
	if (cmd[0] == '\0')
		return (-1);

	args[0] = cmd;
	args[1] = NULL;

	child_process = fork();
	if (child_process == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_process == 0)
	{
		
		if (execve(cmd, args, environ) == -1)
		{
			perror(cmd);
			exit(127);
		}
	}

else
{
	waitpid(child_process, &wait_status, 0);

	if (WIFEXITED(wait_status))
	{
		exit_code = WEXITSTATUS(wait_status);
		return (exit_code);
	}
	else
	{
		return (-1);
	}
}
return (-1);
}

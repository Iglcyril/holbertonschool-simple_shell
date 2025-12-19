#include "shell.h"

/**
 * builtin_env - prints environment variables
 * @envp: environment array
 */
void builtin_env(char **envp)
{
	int i;

	if (envp == NULL)
		return;

	for (i = 0; envp[i] != NULL; i++)
		printf("%s\n", envp[i]);
}

/**
 * builtin_exit - exits the shell
 * @exit_status: pointer to last exit status
 * @input_line: input buffer to free
 */
void builtin_exit(int *exit_status, char *input_line)
{
	free(input_line);
	exit(*exit_status);
}

/**
 * check_builtin - checks if command is a builtin and runs it
 * @cmd_tokens: token array (argv)
 * @exit_status: pointer to last exit status
 * @input_line: input buffer (needed for exit cleanup)
 * @envp: environment array
 *
 * Return: 1 if builtin executed, 0 otherwise
 */
int check_builtin(char **cmd_tokens, int *exit_status,
		  char *input_line, char **envp)
{
	if (cmd_tokens == NULL || cmd_tokens[0] == NULL)
		return (0);

	if (strcmp(cmd_tokens[0], "exit") == 0)
	{
		builtin_exit(exit_status, input_line);
		return (1);
	}

	if (strcmp(cmd_tokens[0], "env") == 0)
	{
		builtin_env(envp);
		return (1);
	}

	return (0);
}
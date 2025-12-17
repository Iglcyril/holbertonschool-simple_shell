#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * builtin_env - prints environment variables
 */
void builtin_env(void)
{
	int env_index;

	env_index = 0;
	while (environ[env_index] != NULL)
	{
		printf("%s\n", environ[env_index]);
		env_index++;
	}
}

/**
 * builtin_exit - exits the shell
 * @cmd_tokens: token array to free
 * @exit_status: pointer to last exit status
 * @input_line: input buffer to free
 */
void builtin_exit(char **cmd_tokens, int *exit_status, char *input_line)
{
	free_array(cmd_tokens);
	free(input_line);
	exit(*exit_status);
}

/**
 * check_builtin - checks if command is a builtin and runs it
 * @cmd_tokens: token array (argv)
 * @exit_status: pointer to last exit status
 * @input_line: input buffer (needed for exit cleanup)
 *
 * Return: 1 if builtin executed, 0 otherwise
 */
int check_builtin(char **cmd_tokens, int *exit_status, char *input_line)
{
	if (cmd_tokens == NULL || cmd_tokens[0] == NULL)
		return (0);

	if (strcmp(cmd_tokens[0], "exit") == 0)
	{
		builtin_exit(cmd_tokens, exit_status, input_line);
		return (1);
	}

	if (strcmp(cmd_tokens[0], "env") == 0)
	{
		builtin_env();
		return (1);
	}

	return (0);
}

#include "shell.h"

char *shell_name = "./hsh";

/**
 * main - simple shell (task 0.1)
 * @argc: argument count
 * @argv: argument vector
 * Return: exit status
 */
int main(int argc, char **argv)
{
	char *input_buffer = NULL;
	size_t buffer_capacity = 0;
	ssize_t bytes_read;
	int is_interactive;
	int last_exit_status = 0;
	char *cmd;
	char *p;

	(void)argc;
	shell_name = argv[0];

	is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			write(STDOUT_FILENO, "($) ", 4);

		bytes_read = getline(&input_buffer, &buffer_capacity, stdin);
		if (bytes_read == -1)
		{
			if (is_interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		strip_newline(input_buffer, &bytes_read);

		/* skip leading spaces/tabs */
		cmd = input_buffer;
		while (*cmd == ' ' || *cmd == '\t')
			cmd++;

		/* empty line -> reprompt */
		if (*cmd == '\0')
			continue;

		/* task 0.1: keep only ONE word (no args) */
		p = cmd;
		while (*p && *p != ' ' && *p != '\t')
			p++;
		*p = '\0';

		last_exit_status = exec_cmd(cmd);
	}

	free(input_buffer);
	return (last_exit_status);
}
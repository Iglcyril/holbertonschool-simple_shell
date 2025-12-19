#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment
 *
 * Return: last exit status
 */
int main(int argc, char **argv, char **envp)
{
	char *input_buffer = NULL;
	size_t buffer_capacity = 0;
	ssize_t bytes_read;
	int is_interactive;
	int last_exit_status = 0;
	char **parsed_tokens;
	char *prog_name;
	unsigned int line_number = 0;

	(void)argc;
	prog_name = argv[0];
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

		line_number++;

		strip_newline(input_buffer, &bytes_read);
		if (*input_buffer == '\0')
			continue;

		parsed_tokens = split_string(input_buffer, " \t\n");
		if (parsed_tokens == NULL)
			continue;

		if (check_builtin(parsed_tokens, &last_exit_status,
				  input_buffer, envp))
		{
			free_array(parsed_tokens);
			continue;
		}

		last_exit_status = find_and_execute(parsed_tokens, envp, prog_name);

		if (last_exit_status == 126)
		{
			fprintf(stderr, "%s: %u: %s: Permission denied\n",
				prog_name, line_number, parsed_tokens[0]);
		}
		else if (last_exit_status == 127)
		{
			fprintf(stderr, "%s: %u: %s: not found\n",
				prog_name, line_number, parsed_tokens[0]);
		}

		free_array(parsed_tokens);
	}

	free(input_buffer);
	return (last_exit_status);
}
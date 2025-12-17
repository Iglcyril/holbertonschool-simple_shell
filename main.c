#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *shell_name = "./hsh";

int main(int argc, char **argv)
{
	char *input_buffer = NULL, **parsed_tokens = NULL;
	ssize_t bytes_read;
	size_t buffer_capacity = 0;
	int is_interactive_mode = isatty(STDIN_FILENO);
	int last_exit_status = 0;

	(void)argc;
	shell_name = argv[0];

	while (1)
	{
		if (is_interactive_mode)
			write(STDOUT_FILENO, "($) ", 4);

		bytes_read = getline(&input_buffer, &buffer_capacity, stdin);
		if (bytes_read == -1)
		{
			if (is_interactive_mode)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		strip_newline(input_buffer, &bytes_read);
		if (*input_buffer == '\0')
			continue;

		parsed_tokens = split_string(input_buffer, " \t\n");
		if (parsed_tokens == NULL)
			continue;

		if (check_builtin(parsed_tokens, &last_exit_status, input_buffer))
		{
			free_array(parsed_tokens);
			continue;
		}

		last_exit_status = find_and_execute(parsed_tokens);
		free_array(parsed_tokens);
	}

	free(input_buffer);
	return (last_exit_status);
}

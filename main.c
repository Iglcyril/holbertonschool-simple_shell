#include "shell.h"

char *shell_name = "./hsh";

int main(int argc, char **argv)
{
	char *input_buffer = NULL;
	size_t buffer_capacity = 0;
	ssize_t bytes_read;
	int is_interactive;
	int last_exit_status = 0;
	char **parsed_tokens;

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

		last_exit_status = exec_cmd(parsed_tokens);
		free_array(parsed_tokens);
	}

	free(input_buffer);
	return (last_exit_status);
}
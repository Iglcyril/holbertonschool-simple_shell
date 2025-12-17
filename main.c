#include "shell.h"
/**
* main - Entry point for the simple shell program.
* @argc: Argument count.
* @argv: Argument vector.
* Return: Always 0.
*/
int main(int argc, char **argv)
{
	char *input_buffer;
	char *cmd;
	ssize_t bytes_read;
	size_t buffer_capacity;
	int is_interactive;

	input_buffer = NULL;
	buffer_capacity = 0;
	is_interactive = isatty(STDIN_FILENO);

	(void)argc;
	(void)argv;

	while (1)
	{
		if (is_interactive)
			write(STDOUT_FILENO, "#Holberton$ ", 12);

		bytes_read = getline(&input_buffer, &buffer_capacity, stdin);
		if (bytes_read == -1)
			break;

		strip_newline(input_buffer, &bytes_read);

		
		cmd = input_buffer;

		while (*cmd == ' ')
			cmd++;

		bytes_read = strlen(cmd);
		while (bytes_read > 0 && cmd[bytes_read - 1] == ' ')
		{
			cmd[bytes_read - 1] = '\0';
			bytes_read--;
		}

		if (*cmd == '\0')
			continue;

		exec_cmd(cmd);
	}
	free(input_buffer);
	return (0);
}

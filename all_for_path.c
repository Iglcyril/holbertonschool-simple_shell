#include "shell.h"
/**
* build_path - Constructs a complete file path by combining a directory path and a command name.
* @dir_path: The directory path.
* @cmd_name: The command name.
* Return: Pointer to the newly constructed complete file path string.
*/
char *build_path(char *dir_path, char *cmd_name)
{
	char *complete_path;
	size_t total_length;
	size_t dir_length;

	if (dir_path == NULL)
		return (NULL);
	if (cmd_name == NULL)
		return (NULL);

	total_length = strlen(dir_path) + strlen(cmd_name) + 2;

	complete_path = malloc(total_lenght);
	if (complete_path == NULL)
		return (NULL);

	strcpy(complete_path, dir_path);

	dir_length = strlen(dir_path);

	if (dir_path[dir_lenght - 1] != '/')
	{
		strcat(complete_path, "/");
	}

	strcat(complete_path, cmd_name);

	return (complete_path);
}

/**
 * exec_direct - Execute command with direct path
 * @cmd_args: Command arguments
 *
 * Return: Exit status
 */
int exec_direct(char **cmd_args)
{
	int file_exist;
	int is_exec;

	file_exist = access(cmd_args[0], F_OK);
	if (file_exist == -1)
	{
		fprintf(stderr, "%s: %s: command not found\n", shell_name, cmd_args[0]);
		return (127);
	}

	is_exec = access(cmd_args[0], X_OK);
	if (is_exec == -1)
	{
		fprintf(stderr, "%s: %s: permission denied\n", shell_name, cmd_args[0]);
		return (126);
	}
	return (exec_cmd(cmd_args));
}

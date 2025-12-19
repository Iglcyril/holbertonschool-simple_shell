#include "shell.h"
/**
* build_path - Constructs a complete file path with directory path and command.
* @dir_path: The directory path.
* @cmd_name: The command name.
* Return: Pointer to the newly constructed complete file path string.
*/
char *build_path(char *dir_path, char *cmd_name)
{
	char *complet_path;
	size_t total_len;

	if (dir_path == NULL)
		return (NULL);
	if (cmd_name == NULL)
		return (NULL);

	total_len = strlen(dir_path) + strlen(cmd_name);
	complet_path = malloc(total_len);

	if (complete_path == NULL)
		return (NULL);

	strcpy(complete_path, dir_path);

	dir_len = strlen(dir_path);
	if (dir_path[dir_len - 1] != '/')
	{
		strcat(complete_path, "/");
	}

	strcat(complet_path, cmd_name);

	return (complet_path);
}

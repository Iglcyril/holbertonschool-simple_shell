#include "shell.h"

/**
 * build_path - Builds full path from directory and command
 * @dir_path: directory from PATH
 * @cmd_name: command name
 *
 * Return: malloc'ed full path or NULL
 */
char *build_path(char *dir_path, char *cmd_name)
{
	char *complete_path;
	size_t dir_len, cmd_len;
	int need_slash;

	if (dir_path == NULL || cmd_name == NULL)
		return (NULL);

	dir_len = strlen(dir_path);
	cmd_len = strlen(cmd_name);
	need_slash = (dir_len > 0 && dir_path[dir_len - 1] != '/');

	complete_path = malloc(dir_len + need_slash + cmd_len + 1);
	if (complete_path == NULL)
		return (NULL);

	strcpy(complete_path, dir_path);
	if (need_slash)
		strcat(complete_path, "/");
	strcat(complete_path, cmd_name);

	return (complete_path);
}

/**
 * search_in_path - Search command in PATH and execute it
 * @path_dirs: directories from PATH
 * @cmd_args: command arguments
 * @envp: environment
 * @prog_name: shell name
 *
 * Return: exit status
 */
int search_in_path(char **path_dirs, char **cmd_args,
		   char **envp, char *prog_name)
{
	char *full_path;
	char *original_cmd;
	int i, result;

	if (path_dirs == NULL || cmd_args == NULL || cmd_args[0] == NULL)
		return (127);

	original_cmd = cmd_args[0];

	for (i = 0; path_dirs[i] != NULL; i++)
	{
		full_path = build_path(path_dirs[i], original_cmd);
		if (full_path == NULL)
			continue;

		if (access(full_path, X_OK) == 0)
		{
			cmd_args[0] = full_path;
			result = exec_cmd(cmd_args, envp, prog_name);
			cmd_args[0] = original_cmd;
			free(full_path);
			return (result);
		}

		free(full_path);
	}

	return (127);
}

/**
 * exec_direct - Execute command with direct path
 * @cmd_args: command arguments
 * @envp: environment
 * @prog_name: shell name
 *
 * Return: exit status
 */
int exec_direct(char **cmd_args, char **envp, char *prog_name)
{
	if (cmd_args == NULL || cmd_args[0] == NULL)
		return (127);

	if (access(cmd_args[0], F_OK) == -1)
	{
		fprintf(stderr, "%s: %s: command not found\n",
			prog_name, cmd_args[0]);
		return (127);
	}

	if (access(cmd_args[0], X_OK) == -1)
	{
		fprintf(stderr, "%s: %s: Permission denied\n",
			prog_name, cmd_args[0]);
		return (126);
	}

	return (exec_cmd(cmd_args, envp, prog_name));
}

/**
 * find_and_execute - Decide how to execute a command
 * @cmd_args: command arguments
 * @envp: environment
 * @prog_name: shell name
 *
 * Return: exit status
 */
int find_and_execute(char **cmd_args, char **envp, char *prog_name)
{
	char *path_env;
	char **path_dirs;
	int result;

	if (cmd_args == NULL || cmd_args[0] == NULL)
		return (0);

	/* Direct paths */
	if (cmd_args[0][0] == '/' ||
	    (cmd_args[0][0] == '.' && cmd_args[0][1] == '/') ||
	    (cmd_args[0][0] == '.' && cmd_args[0][1] == '.' &&
	     cmd_args[0][2] == '/'))
		return (exec_direct(cmd_args, envp, prog_name));

	path_env = get_env_value("PATH", envp);
	if (path_env == NULL)
	{
		fprintf(stderr, "%s: %s: command not found\n",
			prog_name, cmd_args[0]);
		return (127);
	}

	path_dirs = split_string(path_env, ":");
	free(path_env);

	if (path_dirs == NULL)
		return (127);

	result = search_in_path(path_dirs, cmd_args, envp, prog_name);

	if (result == 127)
		fprintf(stderr, "%s: %s: command not found\n",
			prog_name, cmd_args[0]);
	else if (result == 126)
		fprintf(stderr, "%s: %s: Permission denied\n",
			prog_name, cmd_args[0]);

	free_array(path_dirs);
	return (result);
}
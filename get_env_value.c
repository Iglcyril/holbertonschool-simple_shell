#include "shell.h"

/**
 * get_env_value - returns the value of an environment variable
 * @name: variable name (example: "PATH")
 * @envp: environment array
 *
 * Return: pointer to the value inside envp, or NULL if not found
 */
char *get_env_value(const char *name, char **envp)
{
	size_t len;
	int i;
	char *value;

	if (name == NULL || envp == NULL)
		return (NULL);

	len = strlen(name);

	for (i = 0; envp[i] != NULL; i++)
	{

		if (strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
		{
			value = strdup(envp[i] + len + 1);
			return (value);
		}
	}

	return (NULL);
}

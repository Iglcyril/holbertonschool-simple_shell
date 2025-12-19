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
	size_t nlen;
	int i;

	if (name == NULL || *name == '\0' || envp == NULL)
		return (NULL);

	nlen = strlen(name);

	for (i = 0; envp[i] != NULL; i++)
	{
		
		if (strncmp(environ[i], name, nlen) == 0 && environ[i][nlen] == '=')
			return (environ[i] + nlen + 1);
	}

	return (NULL);
}
#include <string.h>

extern char **environ;

/**
 * get_env_value - returns the value of an environment variable
 * @name: variable name (example: "PATH")
 *
 * Return: pointer to the value inside environ, or NULL if not found
 */
char *get_env_value(const char *name)
{
	size_t nlen;
	int i;

	if (name == NULL || *name == '\0')
		return (NULL);

	nlen = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		
		if (strncmp(environ[i], name, nlen) == 0 && environ[i][nlen] == '=')
			return (environ[i] + nlen + 1);
	}

	return (NULL);
}

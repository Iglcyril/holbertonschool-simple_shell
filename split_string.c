#include "shell.h"
#include <stdlib.h>
#include <string.h>

char **split_string(char *input_str, char *delim)
{
	int count, i;
	char **tokens;
	char *copy;
	char *tok;
	char *clean;

	if (input_str == NULL || delim == NULL || *input_str == '\0' || *delim == '\0')
		return (NULL);

	count = token_count(input_str, delim);
	if (count <= 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count + 1));
	if (tokens == NULL)
		return (NULL);

	copy = malloc(strlen(input_str) + 1);
	if (copy == NULL)
	{
		free(tokens);
		return (NULL);
	}
	strcpy(copy, input_str);

	i = 0;
	tok = strtok(copy, delim);
	while (tok != NULL)
	{
		clean = clean_quotes(tok);

		tokens[i] = malloc(strlen(clean) + 1);
		if (tokens[i] == NULL)
		{
			while (i > 0)
			{
				i--;
				free(tokens[i]);
			}
			free(tokens);
			free(copy);
			return (NULL);
		}
		strcpy(tokens[i], clean);

		i++;
		tok = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	free(copy);
	return (tokens);
}
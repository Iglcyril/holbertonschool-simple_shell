#include "shell.h"
/**
 * split_string - splits a string into tokens
 * @input_str: string to split
 * @delim: delimiter characters
 *
 * Return: NULL-terminated array of tokens, or NULL on failure
 */
char **split_string(char *input_str, char *delim)
{
	char **tokens, *copy, *tok, *clean;
	int count, i;

	if (input_str == NULL || delim == NULL ||
		*input_str == '\0' || *delim == '\0')
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

	for (i = 0, tok = strtok(copy, delim); tok; tok = strtok(NULL, delim), i++)
	{
		clean = clean_quotes(tok);
		tokens[i] = malloc(strlen(clean) + 1);
		if (tokens[i] == NULL)
		{
			tokens[i] = NULL;
			free_array(tokens);
			free(copy);
			return (NULL);
		}
		strcpy(tokens[i], clean);
	}

	tokens[i] = NULL;
	free(copy);
	return (tokens);
}

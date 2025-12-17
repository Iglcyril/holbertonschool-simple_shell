#include "shell.h"

/**
 * clean_quotes - Removes surrounding quotes from a token if present.
 * @token: The input token string.
 * Return: Pointer to the cleaned token string.
 */
char *clean_quotes(char *token)
{
	size_t token_len;

	if (token == NULL)
		return (token);

	token_len = strlen(token);

	if (token_len > 1)
	{
		if (token[0] == '"')
		{
			if (token[token_len - 1] == '"')
			{
				token[token_len - 1] = '\0';
				return (token + 1);
			}
		}
		if (token[0] == '\'')
		{
			if (token[token_len - 1] == '\'')
			{
				token[token_len - 1] = '\0';
				return (token + 1);
			}
		}
	}
	return (token);
}

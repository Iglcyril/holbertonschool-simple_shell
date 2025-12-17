#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
*token_count - Count tokens in a string
*@input_str: String to analyze
*@delim: Delimiter characters
* Return: Number of tokens found
*/
int token_count(const char *input_str, const char *delim)
{
	int count = 0;
	char *copy, *tok;

	if (input_str == NULL || delim == NULL)
		return (0);

	if (*input_str == '\0')
		return (0);

	copy = malloc(strlen(input_str) + 1);
	if (copy == NULL)
		return (0);

	strcpy(copy, input_str);

	tok = strtok(copy, delim);
	while (tok != NULL)
	{
		count++;
		tok = strtok(NULL, delim);
	}

	free(copy);
	return (count);
}

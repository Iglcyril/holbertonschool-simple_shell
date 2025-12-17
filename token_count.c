#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
*token count - Count tokens in a string
*@input_str: String to analyze
*@delim: Delimiter characters
*
*
*/
int token_count(const char *input_str, const char *delim)
{
	int count = 0;
	char *copy, *tok;

	if (input_str == NULL || delim == NULL)
		return (0);

	if (*input_str == '\0')
		return (0);

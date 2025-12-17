#include "shell.h"
/**
* strip_newline - Removes the trailing newline character from a string.
* @input_str: The input string to be modified.
* @str_len: Pointer to the length of the input string.
* Return: void.
*/
void strip_newline(char *input_str, ssize_t *str_len)
{
if (input_str == NULL)
	return;

if (*str_len <= 0)
	return;

if (input_str[*str_len - 1] == '\n')
	{
		input_str[*str_len - 1] = '\0';
		*str_len = *str_len -1;
	}
}

#include "shell.h"
/**
* free_array - frees a NULL-terminated array of strings
* @array: the array to be freed
* Return: void
 */
void free_array(char **array)
{
	int array_idx = 0;

	if (array == NULL)
	{
		return;
	}

	while (array[array_idx] != NULL)
	{
		free(array[array_idx]);
		array_idx = array_idx + 1;
	}
	free(array);
}

#include "shell.h"

/**
 * my_free - Frees memory allocated for an array of strings.
 * @array: The array of strings to be freed.
 *
 * Description: This function frees the memory allocated for each string
 * in the array and then frees the array itself.
 */
void my_free(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	my_free(array);
}


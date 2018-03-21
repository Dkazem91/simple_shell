#include "shell.h"

char *get_array_element(char **array, char *element_name)
{
	char *str;

	while (*array != NULL)
	{
		str = str_search(element_name, *array);
		if (str != NULL)
			return (*array);

		array++;
	}

	return (NULL);
}

char **make_array(char *str, char delim)
{
	char *str_ptr = str;
	unsigned int i = 2;
	char **array = NULL;

	while (*str_ptr != '\0')
	{
		if (*str_ptr == delim)
			i++;

		str_ptr++;
	}

	array = malloc(i * sizeof(char **));
	if (array == NULL)
		exit(EXIT_FAILURE);

	array[0] = str;
	str_ptr = str;
	i = 1;

	while (*str_ptr != '\0')
	{
		if (*str_ptr == delim)
		{
			*str_ptr = '\0';
			str_ptr++;
			array[i] = str_ptr;
			i++;
		}
		str_ptr++;
	}
	array[i] = NULL;

	return (array);
}

int list_len(char **list, char *entry)
{
	int i = 0;

	if (entry == NULL)
	{
		while (*list != NULL)
		{
			i++;
			list++;
		}
		i++;
		return (i);
	}
	else
	{
		while (*list != NULL)
		{
			if (str_search(entry, *list) != NULL)
				return (i);

			i++;
			list++;
		}
	}

	return (-1);
}

char **array_cpy(char **old_array)
{
	char **new_array = NULL;
	char **ptr_array;
	int len;

	len = list_len(old_array, NULL);

	new_array = malloc(sizeof(char **) * len);

	ptr_array = new_array;
	while (*old_array != NULL)
	{
		*ptr_array = _strdup(*old_array);
		ptr_array++;
		old_array++;
	}
	*ptr_array = NULL;

	return (new_array);
}
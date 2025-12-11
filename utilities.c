#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * calc_args - find the number of strings to be printed
 * @format: a string with conversion specifiers
 *
 * Return: int number of units format should be broken into
 */
int calc_args(const char *format)
{
	int i = 0, str_count = 0, spec_count = 0, count = 0;
	char state = '0';

	if (format == NULL || *format == '\0')
		return (0);

	/* find number of state changes (str -> spec or spec -> string) */
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			spec_count++;
			i += 2;
			state = '%';
			continue;
		}
		while (format[i] != '%' && format[i] != '\0')
		{
			i++;
			if (state != 's')
				str_count++;
			state = 's';
		}
	}

	count = spec_count + str_count;

	/**
	 * printf("spec_count = %d\n", spec_count);
	 * printf("str_count = %d\n", str_count);
	 * printf("size = %d\n", count);
	 */

	return (count);
}

/**
 * seg_len - calculate length of string up to first of delimiter or null byte
 * @str: string to process
 * @delim: char to use as delimiter
 *
 * Return: int length of string
 */
int seg_len(const char *str, char delim)
{
	int len = 0;

	if (!str)
		return (0);

	while (str[len] != delim && str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strncpy - copy src to dst
 * @src: source string
 * @dst: destination string
 * @n: int number of chars to copy
 *
 * Return: dst or NULL
 */
char *_strncpy(const char *src, char *dst, int n)
{
	int i = 0;

	if (!src || !dst)
	{
		return (NULL);
	}

	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';

	return (dst);
}

/**
 * free_all - free all mallocs
 * @substrings: double pointer to strings, last string is NULL
 *
 * Return: always 0
 */
int free_all(char **substrings)
{
	int i = 0;

	while (substrings[i])
	{
		free(substrings[i]);
		i++;
	}
	free(substrings[i]);
	free(substrings);

	return (0);
}

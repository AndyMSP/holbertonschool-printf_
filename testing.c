#include <stdio.h>
#include "main.h"

/**
 * print_string_list - prints every string in a list of strings
 * @strings: list of strings
 *
 * Return: void
 */
void print_string_list(char **strings)
{
	int i;

	i = 0;
	while (strings[i])
	{
		printf("%s\n", strings[i]);
		i++;
	}
}

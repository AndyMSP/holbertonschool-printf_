#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - print a formatted string like printf
 * @format: string with format specifiers
 * @...: parameters to be printed
 *
 * Return: int number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char **substrings = NULL;
	int len = 0, i = 0, printed = 0, args;

	if (!format)
		return (-1);

	va_start(ap, format);

	substrings = parser(format, ap);
	if (!substrings)
		return (-1);
	args = calc_args(format);

	i = 0;
	while (i < args)
	{
		if (substrings[i][0] == -1 && substrings[i][1] == -1)
		{
			free_all(substrings);
			return (-1);
		}
		len = seg_len(substrings[i], -1, -1);
		printed += len;
		write(STDOUT_FILENO, substrings[i], len);

		i++;
	}

	free_all(substrings);

	return (printed);
}

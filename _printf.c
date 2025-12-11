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

	va_start(ap, format);

	substrings = parser(format, ap);
	args = calc_args(format);

	i = 0;
	while (i < args)
	{
		len = seg_len(substrings[i], '\0');
		printed += len;
		write(STDOUT_FILENO, substrings[i], len);

		i++;
	}

	free_all(substrings);

	return (printed);
}

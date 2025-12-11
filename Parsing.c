#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * parser- separate each prinable component into an array of strings
 * @format: string with format specifiers
 * @ap: va_list of arguments
 *
 * Return: Array of strings - last pointer is NULL
 *
 * **RETURNED POINTER AND EACH POINTER IN ARRAY MUST BE FREED**
 */
char **parser(const char *format, va_list ap)
{
	int args, i, len, j;
	char **strings = NULL, type;

	args = calc_args(format);

	/* malloc number of pointers */
	strings = malloc(sizeof(char *) * (args + 1));
	if (!strings)
		return (NULL);

	/* malloc for each pointer */
	i = 0,
	j = 0;
	while (i < args)
	{
		if (format[j] == '%')
		{
			type = format[j + 1];
			strings[i] = get_arg(type, ap);
			j += 2;
		}
		else
		{
			len = seg_len(format + j, '%', '\0');
			strings[i] = malloc(sizeof(char) * (len + 1));
			strings[i] = _strncpy(format + j, strings[i], len);
			j += len;
		}
		i++;
	}
	strings[i] = NULL;

	return (strings);
}

/**
 * get_arg - get arg as string given type
 * @spec: char type of required arg
 * @ap: va_list
 *
 * Return: string representation of argument
 *
 * **RETURNED POINTER MUST BE FREED**
 */
char *get_arg(char spec, va_list ap)
{
	int len;
	char ch, *str = "string", *res;

	switch (spec)
	{
	case 'c':
		ch = (char)va_arg(ap, int);
		res = malloc(sizeof(char) * 2);
		res[0] = ch;
		res[1] = -1;
		break;
	case 's':
		str = (char *)va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		len = seg_len(str, '\0', -1);
		res = malloc(sizeof(char) * (len + 1));
		res = _strncpy(str, res, len);
		break;
	case '%':
		res = malloc(sizeof(char) * 2);
		res[0] = '%';
		res[1] = -1;
		break;
	case '\0':
		res = malloc(sizeof(char) * 2);
		res[0] = -1;
		res[1] = -1;
		break;
	default:
		res = malloc(sizeof(char) * 3);
		res[0] = '%';
		res[1] = spec;
		res[2] = -1;
	}

	return (res);
}

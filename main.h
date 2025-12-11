#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int calc_args(const char *);
int seg_len(const char *, char);
char *_strncpy(const char *src, char *dst, int n);
char **parser(const char *, va_list);
char *get_arg(char, va_list);
int free_all(char **);

/* Testing Functions */
void print_string_list(char **strings);

#endif

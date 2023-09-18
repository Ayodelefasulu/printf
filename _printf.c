#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>
/**
 * _printf - prints something
 * @format: this is the format string
 * @...: ellipses
 *
 * Return: returns zero for now
 */
int _printf(const char *format, ...)
{
	int itr;
	va_list list;

	va_start(list, format);
	itr = 0;
	if (format == NULL)
		return (-1);
	while (format[itr] != '\0')
	{
		if (format[itr] == '%')
		{
			itr++;
			if (format[itr] == 's')
			{
				char *chs = va_arg(list, char *);

				puts(chs);
				itr++;
			}
			if (format[itr] == 'c')
			{
				int chc = va_arg(list, int);

				putchar(chc);
				itr++;
			}
			if (format[itr] == '%')
			{
				putchar(format[itr]);
				itr++;
			}
		}
		else
		{
			putchar(format[itr]);
			itr++;
		}
	}
	va_end(list);
	return (0);
}

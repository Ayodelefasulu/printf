#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>
/**
 * _printf - prints something
 * @format: this is the format string
 * @...: ellipses
 *
 * Return: length of string
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int itr;
	int length;
	/* int flength; */
	va_list list;

	va_start(list, format);
	itr = 0;
	length = 0;
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

				while (*chs)
				{
					putchar(*chs);
					length++;
					chs++;
				}
			}
			else if (format[itr] == 'c')
			{
				int chc = va_arg(list, int);

				putchar(chc);
				length++;
			}
			else if (format[itr] == '%')
			{
				putchar('%');
				length++;
			}
		}
		else
		{
			 putchar(format[itr]);
			 length++;
		}
		itr++;
	}
	va_end(list);

	/* flength = _strlen(format); */
	return (length);
}

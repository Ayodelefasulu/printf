#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf1 - handles d and i specifiers
 * @format: string
 * @...: elipses
 *
 * Return: 0
 */
int _printf1(const char *format, ...);
int _printf1(const char *format, ...)
{
	va_list list;
	int itr;
	int j;
	int length;

	va_start(list, format);

	if (format == NULL)
		return (-1);
	itr = 0;
	while (format[itr] != '\0')
	{
		if (format[itr] == '%')
		{
			itr++;
			if (format[itr] == 'd')
			{
				int chd = va_arg(list, int);

				char buffer[12];

				sprintf(buffer, "%d", chd);
				puts(buffer);
			}
			if (format[itr] == 'i')
			{
				int chi = va_arg(list, int);

				char buffer[20];

				sprintf(buffer, "%i", chi);

				for (j = 0; buffer[j] != '\0'; j++)
				{
					putchar(buffer[j]);
					length++;
				}
			}
		}
		else
			putchar(format[itr]);
		length++;
	}
		va_end(list);
		return (length);
}

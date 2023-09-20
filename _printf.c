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
	/* int j; */
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
					length += putchar(*chs);
					chs++;
				}
			}
			else if (format[itr] == 'c')
			{
				int chc = va_arg(list, int);

				length += putchar(chc);
			}
			else if (format[itr] == '%')
			{
				length += putchar('%');
<<<<<<< HEAD
			}
			else if (format[itr] == 'd')
			{
				int chd = va_arg(list, int);
				char buffer[12];

				sprintf(buffer, "%d", chd);
				_printf("%s", buffer);
				/* write(1, buffer, _strlen(buffer)); */
			}
			else if (format[itr] == 'i')
			{
				int chi = va_arg(list, int);
				char buffer[20];

				sprintf(buffer, "%i", chi);
				_printf("%s", buffer);
				/* write(1, buffer, _strlen(buffer)); */
=======
>>>>>>> parent of 9cc7a97... task 0
			}
		}
		else
		{
			length += putchar(format[itr]);
		}
		itr++;
	}
	va_end(list);
	return (length);
}

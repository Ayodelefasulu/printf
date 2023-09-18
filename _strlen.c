#include "main.h"
#include <stdio.h>
/**
 * _strlen - count string length
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

#include "main.h"

/**
 * converter - Converts a number into a string
 *		representation in a specified base.
 * @num: The number to be converted.
 * @base: The base to convert to, which can be any integer between 2 and 16.
 * @lowercase: A flag that determines whether the letters in the
 *		converted number should be lowercase or uppercase.
 *
 * Return: A pointer to the string representation of
 *		the number in the specified base.
**/

char *converter(unsigned long int num, int base, int lowercase)
{
	static char *digit;
	static char buffer[50];
	char *ptr;

	if (lowercase)
	{
		digit = "0123456789abcdef";
	}
	else
	{
		digit = "0123456789ABCDEF";
	}

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = digit[num % base];
		num /= base;
	} while (num != 0);
	{
		return (ptr);
	}
}

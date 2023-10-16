#include "main.h"

/**
 * unknown_print - Prints an unknown specifier
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that
 *	determines if a flag was passed to the function
 *
 * Return: the number of characters printed
**/

int unknown_print(va_list l, flags_t *f)
{
	char c;

	c = (char)va_arg(l, int);

	(void)f;
	(void)l;

	return (_putchar(c));
}

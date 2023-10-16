#include "main.h"

/**
 * character_print - Prints a character
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that
 *	determines if a flag was passed to the function
 *
 * This function retrieves a character from the va_list.
 * Return: the number of characters printed
**/

int character_print(va_list l, flags_t *f)
{
	char c;

	c = (char)va_arg(l, int);

	(void)f;

	return (_putchar(c));
}

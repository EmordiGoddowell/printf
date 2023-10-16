#include "main.h"

/**
 * string_print - Prints a string
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that
 *	determines if a flag was passed to the function
 *
 * Return: the number of characters printed.
**/

int string_print(va_list l, flags_t *f)
{
	char *str;

	str = va_arg(l, char *);

	(void)f;

	return (_puts(str));
}

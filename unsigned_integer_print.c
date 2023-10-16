#include "main.h"

/**
 * unsigned_integer_print - Prints an unsigned integer
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that
 *	determines if a flag was passed to the function
 *
 * Return: the number of characters printed.
**/

int unsigned_integer_print(va_list l, flags_t *f)
{
	unsigned int num;
	char *str;

	num = va_arg(l, unsigned int);
	str = converter(num, 10, 0);

	(void)f;
	{
		return (_puts(str));
	}
}

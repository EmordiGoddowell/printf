#include "main.h"

/**
 * integer_print - Prints an integer
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that
 *	determines if a flag was passed to the function
 *
 * Return: the number of characters printed
**/

int integer_print(va_list l, flags_t *f)
{
	int num;
	char *str;

	num = va_arg(l, int);
	str = converter(num, 10, 0);

	(void)f;

	return (_puts(str));
}

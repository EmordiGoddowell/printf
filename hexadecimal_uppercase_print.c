#include "main.h"

/**
 * hexadecimal_uppercase_print - Prints an unsigned
 *		integer in uppercase hexadecimal format
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that
 *		determines if a flag was passed to the function
 *
 * Return:  the number of characters printed
**/

int hexadecimal_uppercase_print(va_list l, flags_t *f)
{
	unsigned int num;
	char *str;
	int count;

	num = va_arg(l, unsigned int);
	str = converter(num, 16, 0);
	count = 0;

	if (f->hashtag_flag == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);

	return (count);
}

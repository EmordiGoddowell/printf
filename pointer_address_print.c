#include "main.h"

/**
 * pointer_address_print - Prints a pointer's address
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that
 *	determines if a flag was passed to the function
 *
 * Return: the number of characters printed
**/

int pointer_address_print(va_list l, flags_t *f)
{
	void *ptr;
	char *str;

	ptr = va_arg(l, void *);
	str = converter((unsigned long int)ptr, 16, 0);

	(void)f;

	return (_puts(str));
}

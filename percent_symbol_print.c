#include "main.h"

/**
 * percent_symbol_print - Prints the percent symbol
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that determines
 *	if a flag was passed to the function
 *
 * Return: Print the '%' character and return the
 *	number of characters printed
**/

int percent_symbol_print(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}

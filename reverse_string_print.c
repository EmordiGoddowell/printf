#include "main.h"

/**
 * reverse_string_print - Prints a string in reverse order
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that
 *	determines if a flag was passed to the function
 *
 * Return: the number of characters printed
**/

int reverse_string_print(va_list l, flags_t *f)
{
	int i;
	int j;
	char *s;

	i = 0;
	s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";
	while (s[i])
		i++;
	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

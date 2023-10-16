#include "main.h"

/**
 * special_string_print - Prints a string, replacing non-printable
 *		characters with their hex values
 * @l: A va_list that contains the arguments passed to the function
 * @f: A pointer to a flags_t struct that determines
 *	if a flag was passed to the function
 *
 * Return: the number of characters printed
**/

int special_string_print(va_list l, flags_t *f)
{
	int i;
	int count;
	char *res;
	char *s;

	count = 0;
	s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));
	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = converter(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}

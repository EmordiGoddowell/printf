#include "main.h"

/**
 * function_selector - a function that selects the
 *			appropriate function pointer
 * @s: the format specifier character
 *
 * Return: a pointer to the appropriate printing function,
 *		or NULL if no match is found.
**/

int (*function_selector(char s))(va_list, parameters_t *)
{
	int flags;

	register int i;

	print_handler func_arr[] = {
		{'i', integer_print},
		{'s', string_print},
		{'c', character_print},
		{'d', decimal_print},
		{'u', unsigned_integer_print},
		{'x', hexadecimal_print},
		{'X', hexadecimal_uppercase_print},
		{'b', binary_print},
		{'o', octal_print},
		{'R', rot13_encode_print},
		{'r', reverse_string_print},
		{'S', special_string_print},
		{'p', pointer_address_print},
		{'%', percent_symbol_print}
	};

	flags = 14;

	for (i = 0; i < flags; i++)
	{
		if (func_arr[i].c == s)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}

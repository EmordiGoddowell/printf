#include "main.h"

/**
 * function_selector - a function that selects the
 *			appropriate function pointer
 * @p: the format specifier character
 *
 * Return: a pointer to the appropriate printing function,
 *		or NULL if no match is found.
**/

int (*function_selector(const char *p))(va_list, flags_t *)
{
	int i;

	print_handler specifiers[] = {
		{"d", decimal_print},
		{"i", integer_print},
		{"u", unsigned_integer_print},
		{"x", hexadecimal_print},
		{"X", hexadecimal_uppercase_print},
		{"o", octal_print},
		{"b", binary_print},
		{"s", string_print},
		{"c", character_print},
		{"p", pointer_address_print},
		{"S", special_string_print},
		{"r", reverse_string_print},
		{"R", rot13_encode_print},
		{"%", percent_symbol_print},
		{NULL, NULL}
	};

	for (i = 0; specifiers[i].specifier != 0; i++)
	{
		if (*specifiers[i].specifier == *p)
			return (specifiers[i].f);
	}

	return (NULL);
}

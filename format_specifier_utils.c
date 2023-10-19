#include "main.h"
#include <string.h>

/**
 * init_params - Initializes the fields of a parameters_t struct
 * @params: A pointer to the parameters_t struct to initialize
 *
 * This function sets the 'unsign' and 'width' fields to 0,
 * the 'precision' field to -1, and the 'h_modifier' and 'l_modifier'
 * fields to 0. This effectively resets the parameters_t struct
 * to its default state.
**/

void init_params(parameters_t *params)
{
	params->unsign = 0;
	params->width = 0;
	params->precision = -1;
	params->h_modifier = 0;
	params->l_modifier = 0;
}

/**
 * get_flag - Checks for flags in the format string of a printf-style function
 * @p: A pointer to the current position in the format string
 * @params: A pointer to the parameters_t struct where flag information is stored
 *
 * This function scans the format string for any flags (like '-', '+', ' ', etc.)
 * that modify the behavior of the printf-style function. If a flag is found,
 * it updates the corresponding field in the parameters_t struct and returns 1.
 * If no flag is found, it returns 0.
**/

int get_flag(const char *p, parameters_t *params)
{
	if (*p == '+' || *p == '-' || *p == '#' || *p == '0' || *p == ' ')
	{
		switch (*p)
		{
			case '+':
				params->plus_flag = 1;
				break;
			case '-':
				params->minus_flag = 1;
				break;
			case '#':
				params->hashtag_flag = 1;
				break;
			case '0':
				params->zero_flag = 1;
				break;
			case ' ':
				params->space_flag = 1;
				break;
		}
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * get_width - Parses the width field in the format string of a printf-style function
 * @p: A pointer to the current position in the format string
 * @params: A pointer to the parameters_t struct where width information is stored
 * @ap: A va_list pointing to the current argument in the argument list
 *
 * This function scans the format string for a width field, which specifies a minimum
 * number of characters to output. If a digit between 1 and 9 is found, it reads the 
 * full number and stores it in the 'width' field of the parameters_t struct. If a '*'
 * is found, it retrieves the next argument from the argument list and stores it as 
 * the width. If no width field is found, it leaves the 'width' field unchanged.
 *
 * Returns: A pointer to the character following the width field in the format string.
**/

const char *get_width(const char *p, parameters_t *params, va_list ap)
{
	if (*p >= '1' && *p <= '9')
	{
		int width;

		p = p + sscanf(p, "%d", &width);

		params->width = (unsigned int)width;
	}
	else if (*p == '*')
	{
		params->width = va_arg(ap, unsigned int);
		p++;
	}
	return (p);
}

/**
 * get_precision - Parses the precision field in the format string of a printf-style function
 * @p: A pointer to the current position in the format string
 * @params: A pointer to the parameters_t struct where precision information is stored
 * @ap: A va_list pointing to the current argument in the argument list
 *
 * This function scans the format string for a precision field, which specifies the
 * minimum number of digits to be written for the output values. If a digit between 0
 * and 9 is found, it reads the full number and stores it in the 'precision' field of
 * the parameters_t struct. If a '*' is found, it retrieves the next argument from
 * the argument list and stores it as the precision. If no precision field is found,
 * it leaves the 'precision' field unchanged.
 *
 * Returns: A pointer to the character following the precision field in the format string.
**/

const char *get_precision(const char *p, parameters_t *params, va_list ap)
{
	p++;
	params->precision = 0;

	while (*p >= '0' && *p <= '9')
	{
		params->precision = params->precision * 10 + (*p - '0');
		p++;
	}
	if (*p == '*')
	{
		params->precision = va_arg(ap, int);
		p++;
	}
	return (p);
}

/**
 * get_modifier - Parses the length modifier in the format string of a printf-style function
 * @p: A pointer to the current position in the format string
 * @params: A pointer to the parameters_t struct where modifier information is stored
 *
 * This function scans the format string for a length modifier, which specifies the
 * size of the argument. If an 'h' is found, it sets the 'h_modifier' field of
 * the parameters_t struct to 1. If an 'l' is found, it sets the 'l_modifier' field
 * to 1. If no length modifier is found, it leaves the 'h_modifier' and 'l_modifier'
 * fields unchanged.
 *
 * Returns: A pointer to the character following the length modifier in the format string.
**/

const char *get_modifier(const char *p, parameters_t *params)
{
	if (*p == 'h')
	{
		params->h_modifier = 1;
	}
	else if (*p == 'l')
	{
		params->l_modifier = 1;
	}
	return (p + 1);
}

/**
 * get_specifier - Checks if the character pointed to by 'p' is a valid specifier
 * @p: A pointer to the current position in the format string
 *
 * This function checks if the character pointed to by 'p' is a valid specifier
 * for a printf-style function. The valid specifiers are 'c', 'd', 'i', 's', 'o',
 * 'u', 'x', 'X', 'p', 'r', 'S', 'R', and '%'.
 *
 * Returns: 1 if the character is a valid specifier, and 0 otherwise.
**/

int get_specifier(const char *p)
{
	const char *valid_specifiers = "cdisouxXprSR%";
	return (strchr(valid_specifiers, *p) != NULL);
}

/**
 * print_from_to - Prints characters from 'start' up to but not including 'p'
 * @start: A pointer to the start of the range in the string
 * @p: A pointer to the end of the range in the string
 *
 * This function prints characters from the position pointed to by 'start' up to
 * but not including the position pointed to by 'p'. It uses the '_putchar' function
 * to print each character. The '_putchar' function is assumed to print a single
 * character to stdout.
 *
 * Returns: The number of characters printed.
**/

int print_from_to(const char *start, const char *p)
{
	int count;

	count = 0;

	while (start < p)
	{
		_putchar(*start);
		start++;
		count++;
	}
	return (count);
}

/**
 * get_print_func - Retrieves a function pointer to the appropriate print function
 * @p: A pointer to the current position in the format string
 *
 * This function retrieves a function pointer to the appropriate print function
 * based on the specifier pointed to by 'p'. The print functions are stored in
 * an array of 'print_handler' structs, each of which contains a specifier string
 * and a function pointer. The function iterates through this array and returns
 * the function pointer associated with the matching specifier.
 *
 * Returns: A function pointer to the appropriate print function.
**/

int (*get_print_func(const char *p))(va_list, flags_t *)
{
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

	int i;

	for (i = 0; specifiers[i].specifier != NULL; i++)
	{
		if (strcmp(p, specifiers[i].specifier) == 0)
		{
			return (specifiers[i].f);
		}
	}
	return (NULL);
}

#include "main.h"
#include <stdarg.h>

/**
 * _printf - A custom implementation of the printf function
 * @format: The format string that specifies how subsequent
 *		arguments are converted for output
 *
 * Return: the number of characters printed, or -1 if an error occurs.
**/

int _printf(const char *format, ...)
{
	int sum;
	va_list ap;
	char *p, *start;

	parameters_t params = PARAMS_INIT;
	flags_t flags = {0};

	sum = 0;

	va_start(ap, format);

	for (p = (char *)format; *p; p++)
	{
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;

		while (get_flag(p, &params))
		{
			p++;
		}

		p = (char *)get_width((const char *)p, &params, ap);
		p = (char *)get_precision((const char *)p, &params, ap);

		if (get_modifier((const char *)p, &params))
		{
			p++;
		}

		if (!get_specifier(p))
		{
			sum += print_from_to(start, p);
		}
		else
		{
			int (*print_func)(va_list, flags_t*) = get_print_func(p);

			if (print_func)
			{
				sum += print_func(ap, &flags);
			}
		}
	}

	va_end(ap);
	return (sum);
}

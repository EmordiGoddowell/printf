#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - custom printf function with limited functionality.
 * @format: format string.
 * @...: arguments to be formatted and printed.
 *
 * Return: number of characters printed (excluding null byte).
**/
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	int count = 0;
	char buffer[1024];
	int buf_index = 0;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					handle_c(buffer, &buf_index, args);
					break;
				case 's':
					handle_s(buffer, &buf_index, args);
					break;
				case '%':
					handle_percent(buffer, &buf_index);
					break;
				case 'd':
				case 'i':
					handle_di(buffer, &buf_index, args);
					break;
				case 'b':
					handle_b(buffer, &buf_index, args);
					break;
				case 'u':
					handle_u(buffer, &buf_index, args);
					break;
				case 'o':
					handle_o(buffer, &buf_index, args);
					break;
				case 'x':
					handle_x(buffer, &buf_index, args);
					break;
				case 'X':
					handle_X(buffer, &buf_index, args);
					break;
				case 'p':
					handle_p(buffer, &buf_index, args);
					break;
				case 'r':
					handle_r(buffer, &buf_index, args);
					break;
				default:
					handle_percent(buffer, &buf_index);
					buffer[buf_index++] = *ptr;
			}
		}
		else
		{
			buffer[buf_index++] = *ptr;
		}
		if (buf_index >= sizeof(buffer) - 1)
		{
			write(1, buffer, buf_index);
			buf_index = 0;
		}
	}

	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
	}

	va_end(args);

	return count;
}

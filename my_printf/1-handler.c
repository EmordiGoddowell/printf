#include <stdarg.h>
#include <stdio.h>

/*
 * handle_c - prints out a single character
 * @buffer: The character buffer where the formatted output is stored.
 * @buf_index: A pointer to the current index in the buffer.
 * @args: The va_list of arguments.
*/
void handle_c(char buffer[], int *buf_index, va_list args)
{
	buffer[(*buf_index)++] = (char)va_arg(args, int);
}

/*
 * handle_s - prints out a string
 * @buffer: The character buffer where the formatted output is stored.
 * @buf_index: A pointer to the current index in the buffer.
 * @args: The va_list of arguments.
*/
void handle_s(char buffer[], int *buf_index, va_list args)
{
	char *str = va_arg(args, char*);

	while (*str)
	{
		if (*buf_index < sizeof(buffer) - 1)
			buffer[(*buf_index)++] = *str++;
		else
		{
			write(1, buffer, *buf_index);
			*buf_index = 0;
		}
	}
}


/*
 * handle_percent - prints percent
 * @buffer: The character buffer where the formatted output is stored.
 * @buf_index: A pointer to the current index in the buffer.
*/
void handle_percent(char buffer[], int *buf_index)
{
	if (*buf_index < sizeof(buffer) - 1)
		buffer[(*buf_index)++] = '%';
	else
	{
		write(1, buffer, *buf_index);
		*buf_index = 0;
	}
}

/**
 * handle_di - Print signed integers.
 *
 * @buffer: The character buffer where the formatted output is stored.
 * @buf_index: A pointer to the current index in the buffer.
 * @args: The variable arguments list containing the integer to be printed.
**/
void handle_di(char buffer[], int *buf_index, va_list args)
{
	int num = va_arg(args, int);
	int len;

	len = snprintf(buffer + *buf_index, sizeof(buffer) - *buf_index, "%d", num);
	if (len > 0)
		*buf_index += len;
	else
		*buf_index = sizeof(buffer) - 1;
}

/**
 * handle_b - Print binary representation of an unsigned integer.
 *
 * @buffer: The character buffer where the formatted output is stored.
 * @buf_index: A pointer to the current index in the buffer.
 * @args: The variable arguments list containing the
 *		unsigned integer to be converted.
**/
void handle_b(char buffer[], int *buf_index, va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary[33];
	int index = 0;
	int i;

	if (num == 0)
		binary[index++] = '0';
	else
		while (num > 0)
		{
			binary[index++] = (num % 2) ? '1' : '0';
			num /= 2;
		}
	for (i = 0; i < index / 2; i++)
	{
		char temp = binary[i];

		binary[i] = binary[index - i - 1];
		binary[index - i - 1] = temp;
	}

	binary[index] = '\0';

	char *bin_ptr = binary;

	while (*bin_ptr)
	{
		if (*buf_index < sizeof(buffer) - 1)
			buffer[(*buf_index)++] = *bin_ptr++;
		else
		{
			write(1, buffer, *buf_index);
			*buf_index = 0;
		}
	}
}

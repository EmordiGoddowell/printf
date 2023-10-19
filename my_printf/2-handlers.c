#include <stdarg.h>
#include <stdio.h>

void handle_u(char buffer[], int *buf_index, va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len;

	len = snprintf(buffer + *buf_index, sizeof(buffer) - *buf_index, "%u", num);

	if (len > 0)
		*buf_index += len;
	else
		*buf_index = sizeof(buffer) - 1;
}

void handle_o(char buffer[], int *buf_index, va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len;

	len = snprintf(buffer + *buf_index, sizeof(buffer) - *buf_index, "%o", num);

	if (len > 0)
		*buf_index += len;
	else
		*buf_index = sizeof(buffer) - 1;
}

void handle_x(char buffer[], int *buf_index, va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len;

	len = snprintf(buffer + *buf_index, sizeof(buffer) - *buf_index, "%x", num);

	if (len > 0)
		*buf_index += len;
	else
		*buf_index = sizeof(buffer) - 1;
}

void handle_X(char buffer[], int *buf_index, va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len;

	len = snprintf(buffer + *buf_index, sizeof(buffer) - *buf_index, "%X", num);

	if (len > 0)
		*buf_index += len;
	else
		*buf_index = sizeof(buffer) - 1;
}

void handle_p(char buffer[], int *buf_index, va_list args)
{
	void *ptr = va_arg(args, void*);
	int len;

	len = snprintf(buffer + *buf_index, sizeof(buffer) - *buf_index, "%p", ptr);

	if (len > 0)
		*buf_index += len;
	else
		*buf_index = sizeof(buffer) - 1;
}

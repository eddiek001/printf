#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - our printf function
 * @format: our format
 * Return: the printed characters
 */

int _printf(const char *format, ...)
{
	va_list arg;
	char buffer[BUFF_SIZE];
	int buff_index = 0, i, print = 0, width, precision, flags, print_chars = 0;

	if (format == NULL)
		return (-1);
	va_start(arg, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			size = get_size(format, &i);
			width = get_width(format, &i);
			precision = get_precision(format, &i);
			++i;
			print = handle_print(format, &i, arg, flags,
					size, width, precision, buffer);
			if (print == -1)
				return (-1);
			print_chars = print_chars + print;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(arg);
	return (print_chars);
}

/**
 * print_buffer - prints the contents inside the buffer
 * @buffer: array of characters
 * @buff_index: length of characters
 */

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}


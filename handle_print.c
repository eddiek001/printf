#include "main.h"
/**
 * handle_print - prints an argument
 * @format: formatted string
 * @arg: list of arguments
 * @index: index
 * @buffer: buffer array
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 * @flags: gets active flags
 * Return: printed characters
 */

int handle_print(const char *format, int *index, va_list arg, char buffer[],
	int width, int size, int precision, int flags)
{
	int i, unknown_len = 0, print_chars = -1;
	format_t format_arg[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percentage},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hex_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13}, {'\0', NULL}
	};
	for (i = 0; format_arg[i].format != '\0'; i++)
		if (format[*index] == format_arg[i].format)
			return (format_arg[i].fn(arg, buffer, flags, width, precision, size));

	if (format_arg[i].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		unknown_len += write(1, &format[*index], 1);
		return (unknown_len);
	}
	return (print_chars);
}


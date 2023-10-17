#include "main.h"

/**
* print_hexadecimal - prints an hexadecimal
* @arg: argument list
* @buffer: buffer array
* @width: width specifier
* @flags: active flags
* @size: size specifier
* @precision: precision specifier
* Return: hexadecimal
*/

int print_hexadecimal(va_list arg, char buffer[],
	int width, int flags, int size, int precision)
{
	return (print_hex(arg, "0123456789abcdef",
		buffer, width, flags, 'x', size, precision));
}

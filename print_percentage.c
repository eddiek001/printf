#include "main.h"

/**
* print_percentage- prints percentage
* @arg: argument list
* @buffer: stores array
* @width: size of width
* @size: size specification
* @precision: precision specification
* @flags: get active flags
* Return: percentage sign
*/

int print_percentage(va_list arg, char buffer[],
	 int width, int size, int precision, int flags)
{
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(arg);

	return (write(1, "%%", 1));
}

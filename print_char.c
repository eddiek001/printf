#include "main.h"
/**
*print_char - print a char
*@arg: list of arguments
*@buffer:buffer array
*@flags:active flags
*@width: calc width
*@precision: precision specifier
*@size: size specifier
*Return: Number of char
*/
int print_char(va_list arg, char buffer[],
	int flags,int width,int size, int precision)
{
	char c = va_arg(arg, int);

	return (handle_write_char
	(c, buffer, flags, width, precision, size));
}

#include "main.h"
/*
*print_pointer - print value of variable
*@arg: list of arguments
*@buffer: buffer array
*@flags: calc active flags
*@width: width specifier
*@precision: precision specifier
*@size: size specifier
*Return: NUmber of char printed.
*/


int print_pointer(va_list arg, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(arg, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';

	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[index--] =  map_to[num_address % 16];
		num_address /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	index++;

	return (write_pointer(buffer, index, length, width,
	flags, padd, extra_c, padd_start));
}

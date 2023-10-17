#include "main.h"

/**
* print_hex - prints hexadecimal in lower or uppercase
* @arg: argument list
* @map_to: array to map to
* @buffer: buffer array
* @flag_ch: gets active flags
* @width: width specifier
* @size: size specifier
* @flags: gets active flags
* @precision: precision specifier
* Return: hexadecimal
*/

int print_hex(va_list arg, char map_to[], char buffer[],
		int flag_ch, int width, int size, int flags, int precision)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(arg, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsignd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num = num / 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsignd(0, i, buffer, size, width, precision, flags));
}

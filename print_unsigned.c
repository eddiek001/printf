#include "main.h"

/**
* print_unsigned - prints an unsigned number
* @arg: argument list
* @buffer: buffer array
* @width: width specifier
* @precision: precision specifier
* @size: size specifier
* @flags: active flags
* Return: unsigned int
*/

int print_unsigned(va_list arg, char buffer[],
		int width, int precision, int size, int flags)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(arg, unsigned long int);

	num = convert_size_unsignd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num = num / 10;
	}
	i++;
	return (write_unsignd(0, i, buffer, size, width, precision, flags));

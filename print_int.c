#include "main.h"

/**
* print_int - prints integers
* @arg: argument list
* @buffer: buffer array
* @width: get the width
* @precision: precision specifier
* @size: size specifier
* @flags: active flags
* Return: integer
*/

int print_int(va_list arg, char buffer[],
	 int width, int precision, int size, int flags)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	unsigned long int num;
	long int n = va_arg(arg, long int);

	n = convert_size_num(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num = num / 10;
	}
	i++;
	return (write_num(is_neg, i, buffer, size, width, precision, flags));
}

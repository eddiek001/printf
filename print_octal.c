#include "main.h"

/**
* print_octal - prints octal number
* @arg: argument list
* @buffer: buffer array
* @width: width specifier
* @precision: precision specifier
* @size: size specifier
* @flags: active flags
* Return: unsigned int
*/

int print_octal(va_list arg, char buffer[],
         int width, int precision, int size, int flags)
{
        int i = BUFF_SIZE - 2;
        unsigned long int n = va_arg(arg, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(width);

        n = convert_size_unsigned(n, size);
        if (n == 0)
                buffer[i--] = '0';
        buffer[BUFF_SIZE - 1] = '\0';

        while (n > 0)
        {
                buffer[i--] = (n % 8) + '0';
                n = n / 8;
        }

	if (flags & F_HASH && init_n != 0)
		buffer[i--] = '0';
        i++;
        return (write_unsigned(0, i, buffer,size, width, precision, flags));

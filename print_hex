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
	int flag_ch, int width, int size,int flags, int precision)
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
                buffer[i--] = map_to[n % 16];
                n = n / 16;
        }

        if (flags & F_HASH && init_n != 0)
	{
		buffer[i--] = flag_ch;
                buffer[i--] = '0';
	}
        i++;
        return (write_unsigned(0, i, buffer,size, width, precision, flags));
}

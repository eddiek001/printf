#include "main.h"

/**
* print_hex_upper - prints an hexadecimal in uppercase
* @arg: argument list
* @buffer: buffer array
* @width: width specifier
* @flags: active flags
* @size: size specifier
* @precision: precision specifier
* Return: hexadecimal
*/

int print_hex_upper(va_list arg, char buffer[],
        int width, int flags, int size, int precision)
{
        return (print_hex(arg, "0123456789ABCDEF",
                buffer, width, flags, 'X', size, precision));
}

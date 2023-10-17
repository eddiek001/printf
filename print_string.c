#include "main.h"
/**
*print_string - prints a string
*@arg: list arguments
*@buffer: buffer array
*@flags: active flags
*@width: calc width
*@precision: precision specifier
*@size: size spcifier
*Return: Number of char printed
*/
int print_string(va_list arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, length = 0;
	char *s = va_arg(arg, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
			write(1, " ", 1);
			write(1, &s[0], length);
			return (width);
		}
	}

	return (write(1, s, length));
}

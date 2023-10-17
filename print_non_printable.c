#include "main.h"
/**
*print_non_printable - Print ascci codes for non printables
*@arg: list of arguments
*@buffer: buffer array
*@flags: calc active flags
*@width: calc width
*@precision: precision specifier
*@size: size specifier
*Return: Number of char printed
*/

int print_non_printable(va_arg arg, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = 0, set = 0;
	char *s = va_arg(arg, char *);

	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(precision);

	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		if (its_printable(s[i]))
			buffer[i + set] = s[i];
		else
		set += append_hexa_code(s[i], buffer, i + set);

		i++;

	}

	buffer[i + set] = '\0';

		return (write(1, buffer, i + set));
}

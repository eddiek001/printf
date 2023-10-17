#include "main.h"
/**
*print_rot13 - print a rot13 string
*@buffer: buffer array
*@arg: list of arguments
*@flags: calc active flags
*@precision: precision specifier
*@size: size specifier
*@width: calc width
*Return: Number of chat printed .
*
*/

int print_rot13(va_arg arg, char buffer[], int flags,
	int width, int precision, int size)
{
	char x;
	char *s;
	unsigned int k, i;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(arg, char *);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(precision);

	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == s[i])
			{
				x = out[k];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[k];
		{
			x = s[i];
			write(1, &x, 1);
			count++
		}
	}
	return (count);
}

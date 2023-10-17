#include "main.h"
/**
*print_binary - print an unsignrd number
*@arg: list of arguments
*@buffer: buffer array
*@flags: active flags
*@width: calc width
*@precision: precision specifier
*@size: Size specifier
*Return: Number of charsc printed
*/
int print_binary(va_list arg, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int a, b, i, sum;
	unsigned int j[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(arg, unsigned int);
	b = 2147483648;
	j[0] = a / b;
	for (i = 1; i < 32; i++)
{
	b /= 2;
	j[i] = (a / b) % 2;
}
	for (i = 0, sum = 0, count = 0; 1 < 32; i++)
	{
		sum += j[i];
		if (sum || i == 31)
		{
			char k = '0' + j[i];

			write(1, &k, 1);
			count++;
		}
	}
	return (count);
}

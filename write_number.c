#include "main.h"

/**
 * write_number - print a string
 * @is_negative:  list of arguments
 * @index: character arg
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: calc width
 * @precision: precison specifier
 * @size: size specifier
 *
 * Return: Number of char printed
 */
int write_number(int is_negative, int index, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padd = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';

	return (write_num(index, buffer, flags, width, precision, length,
			padd, extra_char));
}

/**
 * write_num - write a no using a buffer
 * @index: index which the number starts on buffer
 * @buffer: buffer array
 * @flags: flags specifier
 * @width: calc width
 * @length: calc length
 * @pr: precision specifier
 * @padd: padding character
 * @extra_c: extra char
 * Return: NUmber of printed chars
 */
int write_num(int index, char buffer[], int flags, int width,
	int pr, int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (pr == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (pr == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (pr > 0 && pr < length)
		padd = ' ';
	while (pr > length)
		buffer[--index] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], length));
}



/**
 * write_unsignd - write an unsinged number
 * @is_negative: number indicating if the number is negative
 * @index: index where number starts
 * @buffer: array of chars
 * @flags: flags
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: NUmber of writenn chars
 */

int write_unsignd(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[1] = padd;
		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
		}
	}
	return (write(1, &buffer[index], length));
}


/**
 * write_pointer - write a memory address
 * @buffer: buffer array
 * @index: index at which the number starts
 * @length: length of number
 * @width: width specifier
 * @flags: flags specifier
 * @padd: char represent
 * @extra_c: char representing
 * @padd_start: index at which padding starts
 *
 * Return: number of chars
 */
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{

	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[3], i - 3 + write(1, &buffer[index], length)));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

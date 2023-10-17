#include "main.h"

/**
 * write number - print a string
 * @is_negative:  list of arguments
 * @ind: character arg
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: calc width
 * @precision: precison specifier
 * @size: size specifier
 *
 * Return: Number of char printed
 */
int write_number(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padd = ' ', extra_char = 0;
	
	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0'
	if (is_negative)
		extra_char = '_';
	else if (flags & F_SPACE)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';

	return (write_n(index, buffer, flags, width, precison, length,
			padd, extra_char));
}

/**
 * write_n - write a no usinf=g a buffer
 * @index: index which the number starts on buffer
 * @buffer: buffer array
 * @flags: flags specifier
 * @width: calc width
 * @length: calc length
 * @precision: precision specifier
 * @padd: padding character
 * @extra_char: extra char
 *
 * Return: NUmber of printed chars
 */

int write_n(int index , char buffet[], int flags, int width,
	int precision, int length , char padd, char extra_char)
{
	int i, padd_start = 1;

	if (precision == 0 && index == BUFF_SIZE -2 && buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFF_SIZE -2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_char != 0)
		length++
	if (width > legth)
	{
		for (i = 1; i < width - lengh + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0'
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i -1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1 &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0'
		{
			if (extra_c)
				buffer[--padd_start] = extra_char;
			return (write(1,&buffer[padd_start], i - padd_start) +
				write(1, &buffer[index], length - (1 -padd_start)));
		}
	}
	if (extra_char)
		buffer[--index] = extra_char;
	return (write(1, &buffer[index], length));
}
/**
 * write_unsgnd - write an unsinged number
 * @is_negative: number indicating if the number is negative
 * @index: index where number starts
 * @buffer: array of chars
 * @flag: flags
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: NUmber of writenn chars
 */

int write_unsgnd(int is_negative,int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1, i = 0;
	char padd =' ';

	UNUSED(is_negative);
	UNUSED(Size);

	if (precision == 0 && index == BUFF_SIZE -2 && buffer[index] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & F_ZERO) && ! (flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[1] = '\0';
		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) +write(1, &buffer[index], length));
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
 * @extra_char: char representing
 * @padd_start: index at which padding starts
 *
 * Return: number of chars
 */
int write_pointers(char buffer[], int index, int length,
	int width, int flags, char padd, char extra_char, int padd_start)
{

	int i;
	if (width > length)
	{
		for (i = 3; i < width - length +3 i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags F_MINUS && padd == ' ')
		{
			buffer[index] = 'x';
			buffer[--index] = '0';
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[3], i - 3 + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_char)
				buffer[--padd_start] = etra_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[index], length - (1 -padd_start) -2));
		}
		buffer[--index] = 'x';
		buffer[--index] = '0';
		if (extra_char)
			buffer[--index] = extra_char;
		return (write(1, &buffer[index], BUFF_SIZE - index -1));

	}
}

























#include "main.h"

/**
 * is_printable - evaluates if character is printable
 * @c: character to be evaluated
 * Return: 1 if c is printable else 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hex - appends ascii in hexadecimal code
 * @buffer: buffer array
 * @i: index to start appending
 * @ascii_code: ASCII code
 * Return: integer 3
 */
int append_hex(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if character is a digit
 * @c: input character
 * Return: returns 1 or 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_num - converts a number to the specified size
 * @num: input number
 * @size: number indicating the type to be converted
 * Return: num
 */
long int convert_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsigned - converts a number to the specified size
 * @num: input number
 * @size: number indicating the type to be converted
 * Return: num
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}


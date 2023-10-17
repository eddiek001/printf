#include "main.h"

/**
 * get_width - calculates the width
 * @format: formatted string
 * @i: list of argument
 * @arg: list of arguments
 * Return: width.
 */

int get_width(const char *format, int *i, va_list arg)
{
	int current_i;
	int width = 0;

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			width *= 10;
			width += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			width = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*i = current_i - 1;

	return (width);
}


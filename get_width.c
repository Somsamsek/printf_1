#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_li;
	int widthz = 0;

	for (curr_li = *i + 1; format[curr_li] != '\0'; curr_li++)
	{
		if (is_digit(format[curr_li]))
		{
			widthz *= 10;
			widthz += format[curr_li] - '0';
		}
		else if (format[curr_li] == '*')
		{
			curr_li++;
			widthz = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_li - 1;

	return (widthz);
}


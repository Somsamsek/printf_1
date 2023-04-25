#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @li: List of arguments to be printed.
 * @my_list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *li, va_list my_list)
{
	int curr_li;
	int widthz = 0;

	for (curr_li = *li + 1; format[curr_li] != '\0'; curr_li++)
	{
		if (is_digit(format[curr_li]))
		{
			widthz *= 10;
			widthz += format[curr_li] - '0';
		}
		else if (format[curr_li] == '*')
		{
			curr_li++;
			widthz = va_arg(my_list, int);
			break;
		}
		else
			break;
	}

	*li = curr_li - 1;

	return (widthz);
}


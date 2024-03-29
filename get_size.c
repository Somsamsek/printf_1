#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_li = *i + 1;
	int my_size = 0;

	if (format[curr_li] == 'l')
		my_size = S_LONG;
	else if (format[curr_li] == 'h')
		my_size = S_SHORT;

	if (my_size == 0)
		*i = curr_li - 1;
	else
		*i = curr_li;

	return (my_size);
}


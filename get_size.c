#include "main.h"

/**
* get_size - Calculate the size to cast the argument
* @format: Formatted string containing the arguments
* @i: Current index in the format string to be printed
*
* Return: Size specifier
*/

int get_size(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;

if (format[curr_i] == 'l')
size = S_LONG;
else if (format[curr_i] == 'h')
size = S_SHORT;

if (size == 0)
*i = curr_i - 1;
else
*i = curr_i;

return (size);
}

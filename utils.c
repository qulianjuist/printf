#include "main.h"

/**
* is_printable - Check if a character is printable
* @c: Character to be evaluated
* Return: 1 if c is printable, 0 otherwise
*/

int is_printable(char c)

{
	if (c >= 32 && c < 127)
	return (1);

	return (0);
}

/**
* append_hexa_code - Append ASCII in hexadecimal code to buffer
* @buffer: Array of characters
* @i: Index at which to start appending
* @ascii_code: ASCII code to be appended
* Return: Always 3 (number of characters appended)
*/

int append_hexa_code(char ascii_code, char buffer[], int i)

{
	char map_to[] = "0123456789ABCDEF";

/* The hexadecimal format code is always 2 digits long */
		if (ascii_code < 0)
		ascii_code *= -1;

		buffer[i++] = '\\';
		buffer[i++] = 'x';

		buffer[i++] = map_to[ascii_code / 16];
		buffer[i] = map_to[ascii_code % 16];

return (3);
}

/**
* is_digit - Check if a character is a digit
* @c: Character to be evaluated
* Return: 1 if c is a digit, 0 otherwise
*/

int is_digit(char c)

{
	if (c >= '0' && c <= '9')
	return (1);

	return (0);
}

/**
* convert_size_number - Cast a number to the specified size
* @num: Number to be casted
* @size: Size indicating the type to cast to
* Return: Casted value of num
*/

long int convert_size_number(long int num, int size)
{

	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
* convert_size_unsgnd - Cast an unsigned number to the specified size
* @num: Unsigned number to be casted
* @size: Size indicating the type to cast to
* Return: Casted value of num
*/

long int convert_size_unsgnd(unsigned long int num, int size)

{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

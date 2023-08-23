#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Print a character
 * @c: Character to be printed
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
    int i = 0;
    char padd = ' ';

    UNUSED(precision);
    UNUSED(size);

    if (flags & F_ZERO)
	padd = '0';

    buffer[i++] = c;
    buffer[i] = '\0';

    if (width > 1)
    {
	buffer[BUFF_SIZE - 1] = '\0';
	for (i = 0; i < width - 1; i++)
		buffer[BUFF_SIZE - i - 2] = padd;

	if (flags & F_MINUS)
	return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
	else
	return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) + write(1, &buffer[0], 1));
    }

    return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Write a number
 * @is_negative: Indicates if the number is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - ind - 1;
    char padd = ' ', extra_ch = 0;

    UNUSED(size);

    if ((flags & F_ZERO) && !(flags & F_MINUS))
	padd = '0';

    if (is_negative)
	extra_ch = '-';
    else if (flags & F_PLUS)
	extra_ch = '+';
    else if (flags & F_SPACE)
	extra_ch = ' ';

    return (write_num(ind, buffer, flags, width, precision, length, padd, extra_ch));
}

/**
 * write_num - Write a number using a buffer
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Padding character
 * @extra_c: Extra character
 *
 * Return: Number of printed characters.
 */
int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c)
{
    return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Write an unsigned number
 * @is_negative: Indicates if the number is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{

    return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Array of characters
 * @ind: Index at which the number starts in the buffer
 * @length: Length of the number
 * @width: Width specifier
 * @flags: Active flags
 * @padd: Padding character
 * @extra_c: Extra character
 * @padd_start: Index at which padding should start
 *
 * Return: Number of characters printed.
 */
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start)
{
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

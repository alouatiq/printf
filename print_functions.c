#include "main.h"

/**
 * _printchar - Prints a character
 * @args: The argument list containing the character to print
 *
 * Return: The number of characters printed
 */
int _printchar(va_list args)
{
    char c = va_arg(args, int);

    return (_add_to_buffer(NULL, NULL, c)); /* Use the buffer system */
}

/**
 * _printstring - Prints a string
 * @args: The argument list containing the string to print
 *
 * Return: The number of characters printed
 */
int _printstring(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        count += _add_to_buffer(NULL, NULL, *str);
        str++;
    }

    return (count);
}

/**
 * _printint - Prints an integer
 * @args: The argument list containing the integer to print
 *
 * Return: The number of characters printed
 */
int _printint(va_list args)
{
    int n = va_arg(args, int);
    char str[12]; /* Enough to hold INT_MIN (-2147483648) */
    int i, count = 0;

    _itoa(n, str, 10); /* Convert the integer to a string */

    for (i = 0; str[i]; i++)
        count += _add_to_buffer(NULL, NULL, str[i]);

    return (count);
}

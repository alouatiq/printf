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
    _putchar(c);
    return (1);
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
    int i;

    if (!str)
        str = "(null)";

    for (i = 0; str[i]; i++)
        _putchar(str[i]);

    return (i);
}

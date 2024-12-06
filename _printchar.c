#include "main.h"

/**
 * _printchar - Prints a character
 * @args: The argument list containing the character to print
 *
 * Return: The number of characters printed (always 1)
 */
int _printchar(va_list args)
{
    char c = va_arg(args, int); /* Retrieve the character from the argument list */
    _putchar(c);                /* Use _putchar to print the character */
    return (1);                 /* Return the count of characters printed */
}

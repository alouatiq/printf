#include "main.h"

/**
 * _printstring - Prints a string
 * @args: The argument list containing the string to print
 *
 * Return: The number of characters printed
 */
int _printstring(va_list args)
{
    char *str = va_arg(args, char *); /* Retrieve the string from the argument list */
    int i;

    if (!str)
        str = "(null)"; /* Handle null strings */

    for (i = 0; str[i]; i++)
        _putchar(str[i]); /* Print each character using _putchar */

    return (i); /* Return the count of characters printed */
}

#include "main.h"

/**
 * _printreverse - Prints a string in reverse
 * @args: The argument list containing the string to print
 *
 * Return: The number of characters printed
 */
int _printreverse(va_list args)
{
    char *str = va_arg(args, char *);
    int i, count = 0;

    if (!str)
        str = "(null)";

    for (i = 0; str[i]; i++) /* Find string length */
        ;

    for (i -= 1; i >= 0; i--) /* Print string in reverse */
    {
        _putchar(str[i]);
        count++;
    }

    return (count);
}

/**
 * _printrot13 - Encodes a string using ROT13 and prints it
 * @args: The argument list containing the string to encode and print
 *
 * Return: The number of characters printed
 */
int _printrot13(va_list args)
{
    char *str = va_arg(args, char *);
    int i, count = 0;
    char c;

    if (!str)
        str = "(null)";

    for (i = 0; str[i]; i++)
    {
        c = str[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
                c += 13;
            else
                c -= 13;
        }
        _putchar(c);
        count++;
    }

    return (count);
}

/**
 * _printnonprintable - Prints a string with non-printable characters as hex codes
 * @args: The argument list containing the string to print
 *
 * Return: The number of characters printed
 */
int _printnonprintable(va_list args)
{
    char *str = va_arg(args, char *);
    int i, count = 0;

    if (!str)
        str = "(null)";

    for (i = 0; str[i]; i++)
    {
        if (str[i] < 32 || str[i] >= 127) /* Non-printable characters */
        {
            _putchar('\\');
            _putchar('x');
            count += 2;

            if (str[i] < 16) /* Add leading zero for single-digit hex */
            {
                _putchar('0');
                count++;
            }

            count += _putchar((str[i] / 16) + '0'); /* First hex digit */
            count += _putchar((str[i] % 16) < 10 ? (str[i] % 16) + '0'
                                                 : (str[i] % 16) - 10 + 'A'); /* Second hex digit */
        }
        else
        {
            _putchar(str[i]);
            count++;
        }
    }

    return (count);
}

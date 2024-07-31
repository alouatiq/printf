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

/**
 * _printint - Prints an integer
 * @args: The argument list containing the integer to print
 *
 * Return: The number of characters printed
 */
int _printint(va_list args)
{
    int n = va_arg(args, int);
    int num, last = n % 10, digit, exp = 1;
    int  i = 1;

    n = n / 10;
    num = n;

    if (last < 0)
    {
        _putchar('-');
        num = -num;
        n = -n;
        last = -last;
        i++;
    }

    if (num > 0)
    {
        while (num / 10 != 0)
        {
            exp = exp * 10;
            num = num / 10;
        }
        num = n;
        while (exp > 0)
        {
            digit = num / exp;
            _putchar(digit + '0');
            num = num - (digit * exp);
            exp = exp / 10;
            i++;
        }
    }
    _putchar(last + '0');

    return (i);
}

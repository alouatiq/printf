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
    unsigned int num, digit, exp = 1;
    int count = 0;

    if (n < 0)
    {
        _putchar('-');
        count++;
        num = -n;
    }
    else
        num = n;

    while (num / exp > 9)
        exp *= 10;

    while (exp > 0)
    {
        digit = num / exp;
        _putchar(digit + '0');
        count++;
        num %= exp;
        exp /= 10;
    }

    return (count);
}

/**
 * _printbinary - Prints an unsigned integer in binary
 * @args: The argument list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */
int _printbinary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;
    int i;
    unsigned int mask = 0x80000000;  // Mask to check each bit, assuming 32-bit integer

    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    while (!(mask & n))  // Skip leading zeros
        mask >>= 1;

    for (; mask; mask >>= 1)
    {
        _putchar((n & mask) ? '1' : '0');
        count++;
    }

    return count;
}

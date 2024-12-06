#include "main.h"

/**
 * _printint - Prints an integer
 * @args: The argument list containing the integer to print
 *
 * Return: The number of characters printed
 */
int _printint(va_list args)
{
    int n = va_arg(args, int);   /* Retrieve the integer from the argument list */
    unsigned int num, digit, exp = 1;
    int count = 0;

    if (n < 0)                   /* Handle negative numbers */
    {
        _putchar('-');
        count++;
        num = -n;
    }
    else
    {
        num = n;
    }

    while (num / exp > 9)        /* Calculate the largest power of 10 in num */
        exp *= 10;

    while (exp > 0)              /* Print each digit */
    {
        digit = num / exp;
        _putchar(digit + '0');
        count++;
        num %= exp;
        exp /= 10;
    }

    return (count);
}

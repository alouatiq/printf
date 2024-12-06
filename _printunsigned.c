#include "main.h"

/**
 * _printunsigned - Prints an unsigned integer
 * @args: The argument list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */
int _printunsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int); /* Retrieve the number */
    unsigned int digit, exp = 1;
    int count = 0;

    while (num / exp > 9) /* Calculate the largest power of 10 in num */
        exp *= 10;

    while (exp > 0) /* Print each digit */
    {
        digit = num / exp;
        _putchar(digit + '0');
        count++;
        num %= exp;
        exp /= 10;
    }

    return (count);
}

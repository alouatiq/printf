#include "main.h"

/**
 * _printoctal - Prints an unsigned integer in octal format
 * @args: The argument list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */
int _printoctal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    char oct[32];
    int i = 0, count = 0;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    while (num > 0)
    {
        oct[i++] = (num % 8) + '0'; /* Convert to octal digit */
        num /= 8;
    }

    while (--i >= 0) /* Print the octal digits in reverse order */
    {
        _putchar(oct[i]);
        count++;
    }

    return (count);
}

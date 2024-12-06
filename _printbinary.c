#include "main.h"

/**
 * _printbinary - Prints an unsigned integer in binary format
 * @args: The argument list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */
int _printbinary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int); /* Retrieve the number */
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
    int count = 0, started = 0;

    while (mask > 0)
    {
        if (num & mask)
        {
            _putchar('1');
            started = 1;
            count++;
        }
        else if (started)
        {
            _putchar('0');
            count++;
        }
        mask >>= 1;
    }

    if (count == 0) /* Handle the case for 0 */
    {
        _putchar('0');
        count = 1;
    }

    return (count);
}

#include "main.h"

/**
 * _printhex - Prints an unsigned integer in hexadecimal format
 * @args: The argument list containing the unsigned integer to print
 * @uppercase: Flag indicating if the hexadecimal characters should be uppercase
 *
 * Return: The number of characters printed
 */
int _printhex(va_list args, int uppercase)
{
    unsigned int num = va_arg(args, unsigned int);
    char hex[16];
    char *base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int i = 0, count = 0;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    while (num > 0)
    {
        hex[i++] = base[num % 16];
        num /= 16;
    }

    while (--i >= 0)
    {
        _putchar(hex[i]);
        count++;
    }

    return (count);
}

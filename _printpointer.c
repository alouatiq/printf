#include "main.h"

/**
 * _printpointer - Prints a memory address in hexadecimal format
 * @args: The argument list containing the pointer to print
 *
 * Return: The number of characters printed
 */
int _printpointer(va_list args)
{
    void *ptr = va_arg(args, void *);
    unsigned long int address;
    char hex[16];
    int i = 0, count = 0;

    if (!ptr)
    {
        return (write(1, "(nil)", 5)); /* Directly output "(nil)" for NULL pointers */
    }

    address = (unsigned long int)ptr;

    /* Convert address to hexadecimal */
    while (address > 0)
    {
        unsigned long int num = address % 16;
        hex[i++] = (num < 10) ? (num + '0') : ((num - 10) + 'a');
        address /= 16;
    }

    /* Print "0x" prefix for pointers */
    _putchar('0');
    _putchar('x');
    count += 2;

    /* Print hexadecimal address in reverse order */
    while (--i >= 0)
    {
        _putchar(hex[i]);
        count++;
    }

    return (count);
}

#include "main.h"

/**
 * _print_unsigned - Prints an unsigned integer
 * @args: The argument list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */
int _print_unsigned(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int num = n;
    int i, len = 0;

    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    while (num > 0)
    {
        num = num / 10;
        len++;
    }

    for (i = len - 1; i >= 0; i--)
    {
        _putchar((n / power(10, i)) % 10 + '0');
    }

    return len;
}

int _print_custom_string(va_list args) {
    char *str = va_arg(args, char *);
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            count += _printf("\x%02X", (unsigned char)str[i]);
        } else {
            _putchar(str[i]);
            count++;
        }
    }
    return count;
}

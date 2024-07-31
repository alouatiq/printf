#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Character string composed of zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte
 * used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                return (-1);

            switch (format[i]) {
                case 'u':
                    count += _print_unsigned(args);
                    break;
                case 'o':
                    count += _print_octal(args);
                    break;
                case 'x':
                    count += _print_hex(args, 0);
                    break;
                case 'X':
                    count += _print_hex(args, 1);
                    break;
                case 'S':
                    count += _print_custom_string(args);
                    break;
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    _putchar('%');
                    _putchar(format[i]);
                    count += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}

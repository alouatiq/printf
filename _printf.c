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

            if (format[i] == 'c')
                count += _printchar(args);
            else if (format[i] == 's')
                count += _printstring(args);
            else if (format[i] == 'd' || format[i] == 'i')
                count += _printint(args);
            else if (format[i] == 'b')
                count += _printbinary(args);
            else if (format[i] == '%')
            {
                _putchar('%');
                count++;
            }
            else
            {
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

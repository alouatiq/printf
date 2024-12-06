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

            switch (format[i])
            {
            case 'c':
                count += _printchar(args); /* Handle %c */
                break;
            case 's':
                count += _printstring(args); /* Handle %s */
                break;
            case 'd':
            case 'i':
                count += _printint(args); /* Handle %d and %i */
                break;
            case 'b':
                count += _printbinary(args); /* Handle %b */
                break;
            case 'u':
                count += _printunsigned(args); /* Handle %u */
                break;
            case 'o':
                count += _printoctal(args); /* Handle %o */
                break;
            case 'x':
                count += _printhex(args, 0); /* Handle %x (lowercase) */
                break;
            case 'X':
                count += _printhex(args, 1); /* Handle %X (uppercase) */
                break;
            case 'p':
                count += _printpointer(args); /* Handle %p */
                break;
            case 'r':
                count += _printreverse(args); /* Handle %r */
                break;
            case 'R':
                count += _printrot13(args); /* Handle %R */
                break;
            case 'S':
                count += _printnonprintable(args); /* Handle %S */
                break;
            case '%':
                _putchar('%'); /* Handle %% */
                count++;
                break;
            default:
                _putchar('%');
                _putchar(format[i]);
                count += 2; /* Print unknown specifier as-is */
                break;
            }
        }
        else
        {
            _putchar(format[i]); /* Print regular characters */
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}

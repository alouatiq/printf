#include "main.h"

/* Define buffer size */
#define BUFFER_SIZE 1024

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
    char buffer[BUFFER_SIZE];
    int buffer_index = 0, i = 0, count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
            {
                va_end(args);
                return (-1);
            }

            switch (format[i])
            {
                case 'c':
                    count += _add_to_buffer(buffer, &buffer_index, va_arg(args, int));
                    break;
                case 's':
                    count += _printstring_to_buffer(buffer, &buffer_index, va_arg(args, char *));
                    break;
                case 'd':
                case 'i':
                    count += _printint_to_buffer(buffer, &buffer_index, va_arg(args, int));
                    break;
                case '%':
                    count += _add_to_buffer(buffer, &buffer_index, '%');
                    break;
                default:
                    count += _add_to_buffer(buffer, &buffer_index, '%');
                    count += _add_to_buffer(buffer, &buffer_index, format[i]);
                    break;
            }
        }
        else
        {
            count += _add_to_buffer(buffer, &buffer_index, format[i]);
        }
        i++;
    }

    /* Flush any remaining characters in the buffer */
    if (buffer_index > 0)
        count += _write_buffer(buffer, buffer_index);

    va_end(args);
    return (count);
}

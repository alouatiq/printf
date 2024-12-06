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
    int i = 0, count = 0, buffer_index = 0;
    char buffer[BUFFER_SIZE];

    if (!format)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
            {
                va_end(args);
                return (-1);
            }

            /* Old cases preserved */
            if (format[i] == 'c')
                count += _add_to_buffer(buffer, &buffer_index, va_arg(args, int)); /* %c */
            else if (format[i] == 's')
                count += _printstring_to_buffer(buffer, &buffer_index, va_arg(args, char *)); /* %s */
            else if (format[i] == 'd' || format[i] == 'i')
                count += _printint_to_buffer(buffer, &buffer_index, va_arg(args, int)); /* %d, %i */
            else if (format[i] == '%')
                count += _add_to_buffer(buffer, &buffer_index, '%'); /* %% */
            else
            {
                /* New cases for advanced specifiers */
                switch (format[i])
                {
                case 'b':
                    count += _printbinary_to_buffer(buffer, &buffer_index, va_arg(args, unsigned int));
                    break;
                case 'u':
                    count += _printunsigned_to_buffer(buffer, &buffer_index, va_arg(args, unsigned int));
                    break;
                case 'o':
                    count += _printoctal_to_buffer(buffer, &buffer_index, va_arg(args, unsigned int));
                    break;
                case 'x':
                    count += _printhex_to_buffer(buffer, &buffer_index, va_arg(args, unsigned int), 0);
                    break;
                case 'X':
                    count += _printhex_to_buffer(buffer, &buffer_index, va_arg(args, unsigned int), 1);
                    break;
                case 'p':
                    count += _printpointer_to_buffer(buffer, &buffer_index, va_arg(args, void *));
                    break;
                case 'r':
                    count += _printreverse_to_buffer(buffer, &buffer_index, va_arg(args, char *));
                    break;
                case 'R':
                    count += _printrot13_to_buffer(buffer, &buffer_index, va_arg(args, char *));
                    break;
                case 'S':
                    count += _printnonprintable_to_buffer(buffer, &buffer_index, va_arg(args, char *));
                    break;
                default:
                    count += _add_to_buffer(buffer, &buffer_index, '%');
                    count += _add_to_buffer(buffer, &buffer_index, format[i]);
                    break;
                }
            }
        }
        else
        {
            count += _add_to_buffer(buffer, &buffer_index, format[i]);
        }
        i++;
    }

    /* Flush remaining characters in the buffer */
    if (buffer_index > 0)
        count += _write_buffer(buffer, buffer_index);

    va_end(args);
    return (count);
}

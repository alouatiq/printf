#include "main.h"
#include <stdlib.h>

/**
 * _printf - Custom implementation of printf
 * @format: Format string
  * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char *str;
    char c;
    int d;
    char buffer[20]; // Buffer for integer to string conversion

    va_start(args, format);
    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*ptr == 's')
            {
                str = va_arg(args, char *);
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (*ptr == 'd' || *ptr == 'i')
            {
                d = va_arg(args, int);
                itoa(d, buffer, 10);
                str = buffer;
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (*ptr == '%')
            {
                write(1, "%", 1);
                count++;
            }
        }
        else
        {
            write(1, ptr, 1);
            count++;
        }
    }
    va_end(args);
    return count;
}

/**
 * itoa - Convert integer to string
 * @value: Integer value
 * @str: Buffer to store the string
 * @base: Numerical base
 * Return: Pointer to the buffer
 */
char *itoa(int value, char *str, int base)
{
    char *ptr = str, *ptr1 = str, tmp_char;
    int tmp_value;

    if (base < 2 || base > 36) { *str = '\0'; return str; }

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "0123456789abcdefghijklmnopqrstuvwxyz"[tmp_value - value * base];
    } while ( value );

    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return str;
}

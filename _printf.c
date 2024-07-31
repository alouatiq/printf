#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
* _printf - Custom implementation of the printf function
* @format: Format string containing the characters and the specifiers
* 
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int printed_chars = 0;
int i = 0;
if (format == NULL)
return (-1);
va_start(args, format);
while (format[i])
{
if (format[i] == '%' && format[i + 1] != '\0')
{
i++;
if (format[i] == 'c')
{
char c = va_arg(args, int);
write(1, &c, 1);
printed_chars++;
}
else if (format[i] == 's')
{
char *s = va_arg(args, char *);
int len = 0;
while (s[len])
len++;
write(1, s, len);
printed_chars += len;
}
else if (format[i] == '%')
{
write(1, "%", 1);
printed_chars++;
}
else
{
write(1, &format[i - 1], 1);
write(1, &format[i], 1);
printed_chars += 2;
}
}
else
{
write(1, &format[i], 1);
printed_chars++;
}
i++;
}
va_end(args);
return (printed_chars);
}

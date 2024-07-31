#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
* Description: this function will call the corresponding function
* that will handle the format
* Return: length of the formatted output string
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
int i = 0;
va_start(args, format);
if (!format)
return (-1);
while (format && format[i])
{
if (format[i] == '%')
{
i++;
if (format[i] == 'c')
count += _putchar(va_arg(args, int));
else if (format[i] == 's')
count += _puts(va_arg(args, char *));
else if (format[i] == '%')
count += _putchar('%');
else if (format[i] == 'd' || format[i] == 'i')
count += _print_number(va_arg(args, int));
else
return (-1);
}
else
count += _putchar(format[i]);
i++;
}
va_end(args);
return (count);
}
/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
* _puts - prints a string to stdout
* @str: the string to print
*
* Return: number of characters printed
*/
int _puts(char *str)
{
int i = 0;
if (!str)
str = "(null)";
while (str[i])
_putchar(str[i++]);
return (i);
}
/**
* _print_number - prints an integer to stdout
* @n: the integer to print
*
* Return: number of characters printed
*/
int _print_number(int n)
{
unsigned int num;
int count = 0;
if (n < 0)
{
_putchar('-');
count++;
num = -n;
}
else
{
num = n;
}
if (num / 10)
count += _print_number(num / 10);
_putchar((num % 10) + '0');
count++;
return (count);
}

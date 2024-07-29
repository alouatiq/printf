#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
* Return: number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
int count = 0;
const char *p;
va_list args;
char c;
char *s;
va_start(args, format);
for (p = format; *p != '\0'; p++)
{
if (*p == '%')
{
p++;
switch (*p)
{
case 'c':
c = va_arg(args, int);
write(1, &c, 1);
count++;
break;
case 's':
s = va_arg(args, char *);
while (*s)
{
write(1, s++, 1);
count++;
}
break;
case '%':
write(1, "%", 1);
count++;
break;
default:
write(1, p, 1);
count++;
break;
}
}
else
{
write(1, p, 1);
count++;
}
}
va_end(args);
return count;
}

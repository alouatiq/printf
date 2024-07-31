#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _printchar(va_list args);
int _printstring(va_list args);
int _printint(va_list args);

#endif /* MAIN_H */

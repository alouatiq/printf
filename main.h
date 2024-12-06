#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Function prototypes */
int _printf(const char *format, ...); /* Main printf function */
int _putchar(char c);                /* Writes a character to stdout */
int _printchar(va_list args);        /* Handles %c */
int _printstring(va_list args);      /* Handles %s */
int _printint(va_list args);         /* Handles %d and %i */

#endif /* MAIN_H */

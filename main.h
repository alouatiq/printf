#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Main printf function */
int _printf(const char *format, ...); /* Main printf function */

/* Low-Level Output Functions */
int _putchar(char c);                /* Writes a single character to stdout */

/* Buffer Management Functions */
int _add_to_buffer(char *buffer, int *index, char c); /* Add character to buffer */
int _write_buffer(char *buffer, int len);            /* Flush buffer to stdout */

/* Handlers with Buffer Support */
int _printstring_to_buffer(char *buffer, int *index, char *str); /* For %s */
int _printint_to_buffer(char *buffer, int *index, int num);      /* For %d, %i */
int _printbinary_to_buffer(char *buffer, int *index, unsigned int num); /* For %b */
int _printunsigned_to_buffer(char *buffer, int *index, unsigned int num); /* For %u */
int _printoctal_to_buffer(char *buffer, int *index, unsigned int num); /* For %o */
int _printhex_to_buffer(char *buffer, int *index, unsigned int num, int uppercase); /* For %x, %X */
int _printpointer_to_buffer(char *buffer, int *index, void *ptr); /* For %p */
int _printreverse_to_buffer(char *buffer, int *index, char *str); /* For %r */
int _printrot13_to_buffer(char *buffer, int *index, char *str);   /* For %R */
int _printnonprintable_to_buffer(char *buffer, int *index, char *str); /* For %S */

/* Handlers for Specifiers */
int _printchar(va_list args);        /* Handles %c */
int _printstring(va_list args);      /* Handles %s */
int _printint(va_list args);         /* Handles %d and %i */
int _printbinary(va_list args);      /* Handles %b */
int _printunsigned(va_list args);    /* Handles %u */
int _printoctal(va_list args);       /* Handles %o */
int _printhex(va_list args, int uppercase); /* Handles %x and %X */
int _printpointer(va_list args);     /* Handles %p */
int _printreverse(va_list args);     /* Handles %r */
int _printrot13(va_list args);       /* Handles %R */
int _printnonprintable(va_list args); /* Handles %S */

/* Utility Functions */
int _strlen(char *str);              /* String length utility */
char *_itoa(int num, char *str, int base); /* Integer to string conversion */
char *_reverse(char *str);           /* Reverse a string */
char *_rot13(char *str);             /* ROT13 encoding */
char *_strcpy(char *dest, const char *src); /* String copy utility */

#endif /* MAIN_H */

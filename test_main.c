#include <stdio.h>
#include "main.h"

/**
 * main - Entry point for testing the _printf function
 *
 * Return: Always 0
 */
int main(void)
{
    int len1, len2;

    /* Test mandatory tasks */
    printf("=== Mandatory Tasks ===\n");
    len1 = _printf("Character: [%c]\n", 'H');
    len2 = printf("Character: [%c]\n", 'H');
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    len1 = _printf("String: [%s]\n", "Hello, World!");
    len2 = printf("String: [%s]\n", "Hello, World!");
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    len1 = _printf("Decimal: [%d]\n", 123);
    len2 = printf("Decimal: [%d]\n", 123);
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    len1 = _printf("Integer: [%i]\n", -456);
    len2 = printf("Integer: [%i]\n", -456);
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    len1 = _printf("Percent: [%%]\n");
    len2 = printf("Percent: [%%]\n");
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    /* Test advanced tasks */
    printf("=== Advanced Tasks ===\n");
    len1 = _printf("Binary: [%b]\n", 5);
    printf("Expected: [101]\n\n");

    len1 = _printf("Unsigned: [%u]\n", 123);
    len2 = printf("Unsigned: [%u]\n", 123);
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    len1 = _printf("Octal: [%o]\n", 83);
    len2 = printf("Octal: [%o]\n", 83);
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    len1 = _printf("Hex (lower): [%x]\n", 255);
    len2 = printf("Hex (lower): [%x]\n", 255);
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    len1 = _printf("Hex (upper): [%X]\n", 255);
    len2 = printf("Hex (upper): [%X]\n", 255);
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    len1 = _printf("Pointer: [%p]\n", (void *)0x7ffee637b8c0);
    len2 = printf("Pointer: [%p]\n", (void *)0x7ffee637b8c0);
    printf("Lengths: _printf = %d, printf = %d\n\n", len1, len2);

    len1 = _printf("Reversed: [%r]\n", "Hello");
    printf("Expected: [olleH]\n\n");

    len1 = _printf("ROT13: [%R]\n", "Hello");
    printf("Expected: [Uryyb]\n\n");

    len1 = _printf("Non-printable: [%S]\n", "Best\nSchool");
    printf("Expected: [Best\\x0ASchool]\n\n");

    return (0);
}

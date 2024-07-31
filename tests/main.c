#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("Let's try to printf a simple sentence.\n");
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    _printf("Integer:[%d]\n", 123);
    _printf("Negative:[%i]\n", -456);
    return (0);
}

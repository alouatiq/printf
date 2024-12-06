#include "main.h"

/**
 * _strlen - Calculates the length of a string
 * @str: The string to calculate the length of
 *
 * Return: The length of the string (excluding the null terminator)
 */
int _strlen(char *str)
{
    int len = 0;

    if (!str)
        return (0);

    while (str[len])
        len++;

    return (len);
}

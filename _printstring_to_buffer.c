#include "main.h"

/**
 * _printstring_to_buffer - Adds a string to the buffer
 * @buffer: The buffer to write to
 * @index: Pointer to the current index in the buffer
 * @str: The string to write
 *
 * Return: The number of characters written
 */
int _printstring_to_buffer(char *buffer, int *index, char *str)
{
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        count += _add_to_buffer(buffer, index, *str);
        str++;
    }

    return (count);
}

#include "main.h"

/**
 * _printint_to_buffer - Adds an integer to the buffer
 * @buffer: The buffer to write to
 * @index: Pointer to the current index in the buffer
 * @num: The integer to write
 *
 * Return: The number of characters written
 */
int _printint_to_buffer(char *buffer, int *index, int num)
{
    char str[12]; /* Enough for an int (-2147483648) */
    int count = 0, i;

    _itoa(num, str, 10); /* Convert integer to string */
    for (i = 0; str[i]; i++)
    {
        count += _add_to_buffer(buffer, index, str[i]);
    }

    return (count);
}

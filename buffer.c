#include "main.h"

/* Define buffer size */
#define BUFFER_SIZE 1024

/**
 * _write_buffer - Writes characters from the buffer to stdout
 * @buffer: The buffer containing characters to write
 * @len: The number of characters to write
 *
 * Return: The total number of characters written
 */
int _write_buffer(char *buffer, int len)
{
    return (write(1, buffer, len));
}

/**
 * _add_to_buffer - Adds a character to the buffer and flushes if full
 * @buffer: The buffer to hold characters
 * @index: Pointer to the current index in the buffer
 * @c: The character to add to the buffer
 *
 * Return: The total number of characters written (flushed)
 */
int _add_to_buffer(char *buffer, int *index, char c)
{
    int written = 0;

    buffer[*index] = c;
    (*index)++;

    /* If buffer is full, flush it */
    if (*index == BUFFER_SIZE)
    {
        written = _write_buffer(buffer, *index);
        *index = 0; /* Reset the buffer index */
    }

    return (written);
}

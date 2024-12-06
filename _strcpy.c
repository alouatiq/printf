#include "main.h"

/**
 * _strcpy - Copies a string from source to destination
 * @dest: The destination buffer
 * @src: The source string to copy
 *
 * Return: A pointer to the destination string
 */
char *_strcpy(char *dest, const char *src)
{
    int i;

    if (!dest || !src)
        return (NULL);

    for (i = 0; src[i]; i++)
        dest[i] = src[i];

    dest[i] = '\0'; /* Null-terminate the destination string */

    return (dest);
}

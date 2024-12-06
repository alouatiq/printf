#include "main.h"

/**
 * _rot13 - Encodes a string using ROT13
 * @str: The string to encode
 *
 * Return: A pointer to the encoded string
 */
char *_rot13(char *str)
{
    int i;
    char *encoded = str;

    if (!str)
        return (NULL);

    for (i = 0; str[i]; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z'))
        {
            encoded[i] = ((str[i] - 'A' + 13) % 26) + 'A';
        }
        else if ((str[i] >= 'a' && str[i] <= 'z'))
        {
            encoded[i] = ((str[i] - 'a' + 13) % 26) + 'a';
        }
        else
        {
            encoded[i] = str[i]; /* Non-alphabetical characters remain unchanged */
        }
    }

    return (encoded);
}

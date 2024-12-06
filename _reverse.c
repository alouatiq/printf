#include "main.h"

/**
 * _reverse - Reverses a string in place
 * @str: The string to reverse
 *
 * Return: A pointer to the reversed string
 */
char *_reverse(char *str)
{
    int len = 0, i;
    char temp;

    if (!str)
        return (NULL);

    /* Calculate string length */
    while (str[len])
        len++;

    /* Swap characters from both ends */
    for (i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    return (str);
}

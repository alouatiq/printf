#include "main.h"

char *_itoa(int num, char *str, int base)
{
    int i = 0, is_negative = 0, start, end; /* Declare variables at the top */
    unsigned int n;

    /* Handle 0 explicitly */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return (str);
    }

    /* Handle negative numbers for base 10 */
    if (num < 0 && base == 10)
    {
        is_negative = 1;
        n = -num;
    }
    else
    {
        n = (unsigned int)num;
    }

    /* Process individual digits */
    while (n != 0)
    {
        int rem = n % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        n /= base;
    }

    /* Add negative sign for base 10 */
    if (is_negative)
        str[i++] = '-';

    str[i] = '\0';

    /* Reverse the string */
    for (start = 0, end = i - 1; start < end; start++, end--)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }

    return (str);
}

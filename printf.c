#include "main.h"

/**
 * _printf - Custom implementation of printf
 * @format: Format string
 * 
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
  va_list args;
  int count = 0;
  const char *ptr;
  char *str;
  char c;

  va_start(args, format);
  for (ptr = format; *ptr != '\0'; ptr++)
    {
      if (*ptr == '%')
	{
	  ptr++;
	  if (*ptr == 'c')
	    {
	      c = va_arg(args, int);
	      write(1, &c, 1);
	      count++;
	    }
	  else if (*ptr == 's')
	    {
	      str = va_arg(args, char *);
	      while (*str)
		{
		  write(1, str, 1);
		  str++;
		  count++;
		}
	    }
	  else if (*ptr == '%')
	    {
	      write(1, "%", 1);
	      count++;
	    }
	}
      else
	{
	  write(1, ptr, 1);
	  count++;
	}
    }
  va_end(args);
  return count;
}

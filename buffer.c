char buffer[BUFFER_SIZE];
int buffer_index = 0;

...
if (format[i] == '%')
{
    ...
    _add_to_buffer(buffer, &buffer_index, '%'); /* Example for literal '%' */
    ...
}
else
{
    _add_to_buffer(buffer, &buffer_index, format[i]); /* Regular characters */
}
...

/* Flush remaining characters in the buffer */
if (buffer_index > 0)
    count += _write_buffer(buffer, buffer_index);

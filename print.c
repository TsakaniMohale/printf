#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer and resets it
 * @buffer: Array of characters
 * @buff_ind: Pointer to the current index in the buffer
 */
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf-like function
 * @format: The format string.
 * @...: Variable number of arguments.
 * Return: The number of characters printed.
 */
int custom_printf(const char *format, ...)
{
    int i, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list args;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            flags = get_flags(format, &i);
            width = get_width(format, &i, args);
            precision = get_precision(format, &i, args);
            size =


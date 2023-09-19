#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function for 'c', 's', and '%'
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            printed_chars++;
        }
        else
        {
            format++; // Move past '%'
            if (*format == '\0') // Check for '%' at the end
                break;

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                printed_chars++;
            }
            else
            {
                // Handle unsupported format specifier
                write(1, format - 1, 1);
                write(1, format, 1);
                printed_chars += 2;
            }
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}


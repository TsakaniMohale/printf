#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
  va_list args;
  int count = 0;

  va_start(args, format);

  for (int i = 0; i < strlen(format); i++) {
    if (format[i] == '%') {
      switch (format[i + 1]) {
        case 'c':
          count += 1;
          putchar(va_arg(args, int));
          break;
        case 's':
          count += strlen(va_arg(args, char *));
          puts(va_arg(args, char *));
          break;
        default:
          fprintf(stderr, "Unknown format specifier: '%c'\n", format[i + 1]);
          return -1;
      }
      i += 1;
    } else {
      count += 1;
      putchar(format[i]);
    }
  }

  va_end(args);

  return count;
}


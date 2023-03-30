#include <unistd.h>
#include <stdarg.h>

size_t  ft_putstr(char *string, int *length) {
    if (!string)
        string = "(null)";
    while (*string)
        *length += write(1, string++, 1);
}

void ft_putnbr(long long int number, int base, int *length) {
    char *hex = "0123456789abcdef";

    if (number < 0) {
        number *= -1;
        *length += write(1, "-", 1);
    }
    if (number >= base)
        ft_putnbr((number / base), base, length);
    *length += write(1, &hex[number % base], 1);
}

int ft_printf(char *format, ...) {
    int size = 0;
    va_list ap;

    va_start(ap, format);
    while (*format) {
        if ((*format == '%') && *(format + 1)) {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(ap, char *), &size);
            else if (*format == 'd')
                ft_putnbr((long long int)va_arg(ap, int), 10, &size);
            else if (*format == 'x')
                ft_putnbr((long long int)va_arg(ap, unsigned int), 16, &size);
        }
        else
            size += write(1, format, 1);
        format++;
    }
    return (va_end(ap), size);
}

/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Acts like the print function
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <stddef.h>

int m_replace2(char type, va_list ap)
{
    switch (type) {
    case 'X':
        a_to_hex_x_maj(va_arg(ap, char *));
        break;
    case 'x':
        a_to_hex_x(va_arg(ap, char *));
        break;
    case '%':
        my_putchar(type);
        break;
    default:
        my_putchar('%');
        my_putchar(type);
    }
}

int m_replace(char type, va_list ap)
{
    switch (type) {
    case 'c':
        my_putchar(va_arg(ap, int));
        break;
    case 'i':
    case 'd':
        my_put_nbr(va_arg(ap, int));
        break;
    case 's':
        my_putstr(va_arg(ap, char *));
        break;
    case 'b':
        int_to_bin(va_arg(ap, int));
        break;
    case 'S':
        a_to_oct(va_arg(ap, char *));
        break;
    default:
        m_replace2(type, ap);
    }
}

int count_args(char type, int count, va_list ap)
{
    switch (type) {
    case 'c':
    case 'i':
    case 'd':
    case 's':
    case 'b':
    case 'S':
        count++;
        return count;
    case 'X':
    case 'x':
        count++;
        return count;
    default:
        return count;
    }
}

int my_printf(char *str, ...)
{
    va_list ap;
    va_list check;
    char type;
    int count = 0;
    char *sum;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '%') {
            count = count_args(str[i + 1], count, ap);
            i++;
        }
    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            m_replace(str[i + 1], ap);
            i++;
        } else
            my_putchar(str[i]);
    }
    va_end(ap);
}

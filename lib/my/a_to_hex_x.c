/*
** EPITECH PROJECT, 2021
** a_to_hex_x
** File description:
** Transforms int in octodecimal base
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/list.h"

int print_result(int result, int ascii)
{
    result = ascii % 16;
    ascii = ascii / 16;
    my_put_nbr(result);
}

int conversion_to_char_2(int result, int ascii)
{
    switch (result) {
    case 13:
        print_result(result, ascii);
        my_putchar('d');
        break;
    case 14:
        print_result(result, ascii);
        my_putchar('e');
        break;
    case 15:
        print_result(result, ascii);
        my_putchar('f');
        break;
    }
}

int conversion_to_char(int result, int ascii)
{
    switch (result) {
    case 10:
        print_result(result, ascii);
        my_putchar('a');
        break;
    case 11:
        print_result(result, ascii);
        my_putchar('b');
        break;
    case 12:
        print_result(result, ascii);
        my_putchar('c');
        break;
    default:
        conversion_to_char_2(result, ascii);
    }
}

int conversion_to_hex(int ascii)
{
    int result = ascii;

    while (result != 0) {
        result = ascii % 16;
        ascii = ascii / 16;
        conversion_to_char(result, ascii);
    }
}

int a_to_hex_x(char *str)
{
    int ascii = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        ascii = str[i];
        conversion_to_hex(ascii);
    }
}

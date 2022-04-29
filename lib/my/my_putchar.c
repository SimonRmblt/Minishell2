/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** Copies the putchar function
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
    return;
}

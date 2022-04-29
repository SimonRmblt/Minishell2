/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Displays the number given as parameter
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    } else
        my_putchar(nb + 48);
}

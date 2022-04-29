/*
** EPITECH PROJECT, 2021
** a_to_oct
** File description:
** Transforms int in octodecimal base
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/list.h"

int conversion(int a_value, int j, char *str)
{
    int i = a_value;
    struct list *head = NULL;
    int count = 0;

    for (; a_value >= 8; count++) {
        i = a_value % 8;
        a_value = a_value / 8;
        push(&head, i);
        if (j != my_strlen(str) - 1 && i == 0)
            push(&head, 0);
    }
    i = a_value % 8;
    push(&head, i);
    my_putchar('\\');
    if (count == 1)
        my_put_nbr(0);
    if (count == 0)
        my_putstr("00");
    print_list(head);
    free_list(head);
}

char *a_to_oct(char *str)
{
    int a = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] <= 32 || str[j] == 127) {
            a = str[j];
            conversion(a, j, str);
        }
        my_putchar(str[j]);
    }
}

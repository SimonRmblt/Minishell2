/*
** EPITECH PROJECT, 2021
** int_to_bin
** File description:
** Transforms int in binary base
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/list.h"

int int_to_bin(int digit)
{
    int result;
    int i = 0;
    char *nbr;
    struct list *head = NULL;

    while (digit != 0) {
        result = digit % 2;
        digit /= 2;
        push(&head, result);
        i++;
    }
    print_list(head);
    free_list(head);
}

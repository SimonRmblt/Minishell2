/*
** EPITECH PROJECT, 2021
** int_to_bin
** File description:
** Transforms int in binary base
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/list.h"

void free_list(struct list *list)
{
    struct list *tmp;
    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void free_data(d_list *d)
{
    d_list *tmp;
    while (d != NULL) {
        tmp = d;
        d = d->next;
        free(tmp->data);
        free(tmp);
    }
}

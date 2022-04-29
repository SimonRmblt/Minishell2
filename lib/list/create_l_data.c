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

l_data *create_l_data(void *data, enum type type)
{
    l_data *d = malloc(sizeof(l_data));

    d->data = data;
    d->type = type;
    return d;
}

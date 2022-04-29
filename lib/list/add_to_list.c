/*
** EPITECH PROJECT, 2021
** int_to_bin
** File description:
** Transforms int in binary base
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/list.h"
#include "../../include/struct.h"

void add_data(struct data **head_ref, l_data *new_data)
{
    struct data *new_list = malloc(sizeof(struct data));
    struct data *tmp = *head_ref;

    if (tmp == NULL)
        return push_data(head_ref, new_data);
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_list->l_data = new_data;
    new_list->next = NULL;
    tmp->next = new_list;
}

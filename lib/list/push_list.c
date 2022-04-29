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

void push(struct list **head_ref, int new_nbr)
{
    struct list *new_list = malloc(sizeof(struct list));

    new_list->nbr = new_nbr;
    new_list->next = (*head_ref);
    *head_ref = new_list;
}

void push_data(struct data **head_ref, void *new_data)
{
    struct data *new_list = malloc(sizeof(struct data));

    new_list->data = new_data;
    new_list->next = (*head_ref);
    *head_ref = new_list;
}

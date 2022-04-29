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

void print_list(struct list *list)
{
    struct list *temp = list;

    while (temp != NULL) {
        my_put_nbr(temp->nbr);
        my_printf(" ");
        temp = temp->next;
    }
}

/*void print_list_data(d_list *a)
{
    d_list *temp = a;
    while (temp != NULL) {
        if (temp->l_data->type == STR)
            my_printf("%s", (char *)temp->l_data->data);
        if (temp->l_data->type == INT)
            my_printf("%i", temp->l_data->data);
        if (temp->l_data->type == CHAR)
            my_printf("%c", temp->l_data->data);
        temp = temp->next;
    }
}

void print_list_data_type(d_list *a, enum type type)
{
    d_list *temp = a;
    while (temp != NULL) {
        if (temp->l_data->type == STR && type == STR)
            my_printf("%s", (char *)temp->l_data->data);
        if (temp->l_data->type == INT && type == INT)
            my_printf("%i", temp->l_data->data);
        if (temp->l_data->type == CHAR && type == CHAR)
            my_printf("%c", temp->l_data->data);
        if (temp->l_data->type == NONE && type == NONE)
            my_printf("NULL");
        temp = temp->next;
    }
}*/

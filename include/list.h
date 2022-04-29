/*
** EPITECH PROJECT, 2021
** List
** File description:
** Includes all the linked lists
*/

#include "struct.h"

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H

struct list {
    int nbr;
    struct list *next;
};

enum type {
    INT,
    STR,
    CHAR,
    STRUCT,
    NONE,
};

typedef struct l_data {
    void *data;
    enum type type;
} l_data;

typedef struct data {
    void *data;
    struct data *next;
} d_list;

void print_list_data_type(d_list *a, enum type type);
l_data *create_l_data(void *data, enum type type);
void add_data(struct data **head_ref, l_data *new_data);
void print_list_data(d_list *a);
void push_data(struct data **head_ref, void *);
void push(struct list **, int);
void print_list(struct list *);
void free_list(struct list *);
void free_data(d_list *d);

#endif

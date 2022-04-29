/*
** EPITECH PROJECT, 2021
** Mini Shell 2
** File description:
** Mini Shell 2 malloc check
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "include/list.h"
#include "include/my.h"

void *exoc(size_t size, int opt, int ex_code)
{
    static d_list *d = NULL;
    if (opt == 1) {
        void *tmp = malloc(size);
        push_data(&d, tmp);
        if (tmp != NULL)
            return tmp;
        write(2, "Malloc Failed.\n", 15);
        exoc(0, 0, 84);
    }
    if (opt == 0) {
        free_data(d);
        if (ex_code >= 0)
            exit(ex_code);
        else
            return 0;
    }
}

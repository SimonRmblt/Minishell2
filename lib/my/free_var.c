/*
** EPITECH PROJECT, 2021
** Free Double Table
** File description:
** Free Double Table
*/

#include "../../include/my.h"
#include "../../include/list.h"
#include "../../include/minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void free_double_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_exec_command(
    char *error, char *error2, char *full_error_msg)
{
    free(error);
    free(error2);
    free(full_error_msg);
}

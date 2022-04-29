/*
** EPITECH PROJECT, 2021
** Parse args
** File description:
** parse args into double array
*/

#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"
#include "../../include/minishell.h"

int get_tab_height(char **str)
{
    int i = 0;
    while (str[i] != NULL)
        i++;
    return i;
}

int get_tab_height_n(char **str, char *stop)
{
    int i = 0;
    while (my_strcmp(str[i], stop) != 0)
        i++;
    return i;
}

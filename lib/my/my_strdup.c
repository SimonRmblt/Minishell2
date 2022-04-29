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

char *my_strdup(char *str)
{
    if (str == NULL)
        return NULL;
    int len = my_strlen(str);
    char *new_str = exoc(sizeof(char) * len + 1, 1, 0);
    for (int i = 0; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[len] = '\0';
    return new_str;
}

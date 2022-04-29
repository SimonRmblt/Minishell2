/*
** EPITECH PROJECT, 2021
** Mini Shell 2
** File description:
** Mini Shell 2 env manager
*/

#include "include/my.h"
#include "include/list.h"
#include "include/minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int is_alpha(char c)
{
    if (c > 64 && c < 91 || c > 96 && c < 123)
        return 1;
    return 0;
}

int is_alphanumerical(char *str)
{
    int check = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 47 || str[i] > 58) && is_alpha(str[i]) == 0)
            return 0;
    }
    return 1;
}

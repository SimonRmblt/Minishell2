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
#include <unistd.h>

int char_in_string(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

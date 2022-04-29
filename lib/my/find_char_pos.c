/*
** EPITECH PROJECT, 2021
** find char pos
** File description:
** find char pos inside a string
*/

#include "../../include/my.h"

int char_pos_finder(char *str, char sep)
{
    int pos = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep)
            pos = i;
    }
    return pos;
}

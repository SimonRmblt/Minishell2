/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Copies the strcompare function
*/

#include "../../include/my.h"

int my_strcmp(char *str1, char *str2)
{
    int check = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return 1;
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] == str2[i])
            check++;
    if (check == my_strlen(str1))
        return 0;
}

int my_strncmp(char *str1, char *str2, int size)
{
    int check = 0;

    if (str1 == NULL || str2 == NULL)
        return 1;
    if (my_strlen(str2) != size)
        return 1;
    for (int i = 0; i != size; i++)
        if (str2[i] == str1[i])
            check++;
    if (check == my_strlen(str2))
        return 0;
    return 1;
}

int my_char_strcmp(char *str1, char *str2, char c)
{
    int check = 0;

    if (my_strlen(str2) < my_strlen(str1))
        return 1;
    for (int i = 0; str1[i] != c; i++) {
        if (str1[i] == str2[i])
            check++;
    }
    if (check == my_strlen(str2))
        return 0;
    return 1;
}

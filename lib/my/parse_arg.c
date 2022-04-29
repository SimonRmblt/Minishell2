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

int count_separators(char *arg, const char *separator)
{
    int a = 0;

    for (int j = 0; separator[j]; j++)
        for (int i = 0; arg[i] != '\0'; i++) {
            arg[i] == separator[j] ? a++ : a;
        }
    return a;
}

int get_word_nbr(char *str)
{
    int nbr = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && is_alpha(str[i]) == 1) {
            nbr++;
            continue;
        }
        if (is_alpha(str[i]) == 1 && is_alpha(str[i - 1]) == 0)
            nbr++;
    }
    return nbr;
}

char **parse_arg(char *str, const char *separators)
{
    int space = count_separators(str, separators);
    char *tmp = my_strdup(str);
    if (my_strlen(tmp) == space)
        return NULL;
    char **args = exoc(sizeof(char *) * (get_word_nbr(tmp) + 2), 1, 0);
    char *str_token = strtok(tmp, separators);
    int i = 0;

    while (str_token != NULL) {
        args[i] = exoc(sizeof(char) * my_strlen(str_token), 1, 0);
        args[i] = str_token;
        args[i + 1] = NULL;
        str_token = strtok(NULL, separators);
        i++;
    }
    return args;
}

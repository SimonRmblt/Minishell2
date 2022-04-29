/*
** EPITECH PROJECT, 2021
** Mini Shell 2
** File description:
** Mini Shell 2 env manager
*/

#include "../include/my.h"
#include "../include/list.h"
#include "../include/minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char **check_if_exists_env(char **env, char **str, int check)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], str[1], my_strlen(str[1])) == 0
            && env[i][my_strlen(str[1])] == '=') {
            char *full_str = replace_var(env, str, check);
            env[i] = full_str;
            return env;
        }
    }
    if (check == 2)
        return add_var(env, str);
    else
        return add_var_opt(env, str);
}

char **add_to_env(char **env, char **str, int check)
{
    if (check == 1) {
        for (int i = 0; env[i] != NULL; i++)
            my_printf("%s\n", env[i]);
        return env;
    }
    return check_if_exists_env(env, str, check);
}

char **write_on_tab(char **dest, char **src)
{
    int i = 0;
    for (; src[i] != NULL; i++) {
        dest[i] = my_strdup(src[i]);
        dest[i + 1] = NULL;
    }
    return dest;
}
